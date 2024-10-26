#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

bool source[MAX];

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
bool is_circle(int from, int to);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }
    //source[n] true means candidate n is still source, all locked[x][n] is false
    for (int n = 0; n < candidate_count; n++)
    {
        source[n] = true;
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }
    //test preferences[][] value
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("preferences[%i][%i] is: %i \n", i, j, preferences[i][j]);
        }
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        //assume no two candidates have the same name
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // Assume that every voter will rank each of the candidates.
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
            printf("preferences[%i][%i] is %i. \n", ranks[i], ranks[j], preferences[ranks[i]][ranks[j]]);
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        preferences[i][i] = 0;
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // sort pairs[] based on preferences[][]
    pair swap_pair;
    for (int x = 0; x < pair_count; x++)
    {
        for (int y = x + 1; y < pair_count; y++)
        {
            if (preferences[pairs[x].winner][pairs[x].loser] < preferences[pairs[y].winner][pairs[y].loser])
            {
                swap_pair.winner = pairs[y].winner;
                swap_pair.loser = pairs[y].loser;

                pairs[y].winner = pairs[x].winner;
                pairs[y].loser = pairs[x].loser;

                pairs[x].winner = swap_pair.winner;
                pairs[x].loser = swap_pair.loser;
            }
        }
    }
    //test pairs value
    for (int i = 0; i < pair_count; i++)
    {
        printf("pairs[%i]: %i vs. %i \n", i, pairs[i].winner, pairs[i].loser);
    }
    return;
}

bool is_circle(int winner, int loser)
{
    if (locked[loser][winner] == true)
    {
        return true;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[i][winner] == true)
        {
            return is_circle(i, loser);
        }

    }

    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int x = 0; x < pair_count; x++)
    {
        if (is_circle(pairs[x].winner, pairs[x].loser) == false)
        {
            locked[pairs[x].winner][pairs[x].loser] = true;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int y = 0; y < candidate_count; y++)
    {
        bool isloser = false;
        for (int x = 0; x < candidate_count; x++)
        {
            if (locked[x][y])
            {
                isloser = true;
                break;
            }
        }

        if (isloser)
        {
            continue;
        }
        if (!isloser)
        {
            printf("%s\n", candidates[y]);
        }
    }
    return;
}