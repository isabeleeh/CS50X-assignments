#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t  BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Only one command-line argument is acceptable
    if (argc < 2)
    {
        printf("Usage: ./recover IMAGE.\n");
        return 1;
    }

    // Open .raw file for reading
    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // To read the file into buffer 512B at a time
    BYTE *buffer = malloc(BLOCK_SIZE);
    int count = 0;
    char filename[8] = {0};
    FILE *jpeg_file = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        // To read the head of the JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // check out and close the previous file
            if (jpeg_file != NULL)
            {
                fclose(jpeg_file);
            }

            // prepare for the new jpeg file
            sprintf(filename, "%03d.jpg", count);
            count++;

            // Yes, it is JPEG
            jpeg_file = fopen(filename, "w");
            if (jpeg_file == NULL)
            {
                printf("could not create file %s.\n", filename);
                fclose(jpeg_file);
                return 1;
            }
        }

        if (jpeg_file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, jpeg_file);
        }

    }

    // close the last jpeg file
    if (jpeg_file != NULL)
    {
        fclose(jpeg_file);
    }
    fclose(raw_file);

    free(buffer);

}