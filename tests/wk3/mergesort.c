#include <cs50.h>
#include <stdio.h>

void mergesort(int arr[], int starter, int ending);

void merge(int arr[], int p, int q, int r);

void printArray(int arr[], int size);

int main(void)
{
    int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr, 0, size - 1);
    printf("sorted array: \n");
    printArray(arr, size);
}

void mergesort(int arr[], int starter, int ending)
{
    if (starter < ending)
    {
        //m is the point where the array is divided into two subarrays
        int m = (starter + ending - 1) / 2;
        mergesort(arr, starter, m);
        mergesort(arr, m + 1, ending);

        //Merge the sorted subarrays
        merge(arr, starter, m, ending);
    }
}

void merge(int arr[], int p, int q, int r)
{
    //create two arrays to be merged
    int size1 = q - p + 1;
    int size2 = r - q;

    int leftarr[size1], rightarr[size2];

    for (int i = 0; i < size1; i++)
    {
        leftarr[i] = arr[p + i];
    }

    for (int i = 0; i < size2; i++)
    {
        rightarr[i] = arr[q + 1 + i];
    }

    int i = 0, j = 0, k = p;

    while ((i < size1) && (j < size2))
    {
        if (leftarr[i] < rightarr[j])
        {
            arr[k] = leftarr[i];
            i++;
        }
        else
        {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        arr[k] = leftarr[i];
        k++;
        i++;
    }

    while (j < size2)
    {
        arr[k] = rightarr[j];
        k++;
        j++;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}