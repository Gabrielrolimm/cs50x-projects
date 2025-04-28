#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover filename\n");
        return 1;
    }

    // Open memory card
    FILE *mc = fopen(argv[1], "r");
    if (mc == NULL)
    {
        printf("Could not open file\n");
        return 2;
    }

    // Block of bytes
    uint8_t buffer[512];

    // Variables
    bool found = false;
    int j_count = 0;
    char j_name[8];
    FILE *fptr = NULL;

    // While there's data to read
    while (fread(buffer, 1, 512, mc) == 512)
    {
        // If it's the start of a JPG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            found = true;
        }

        if (found == true)
        {
            if (j_count != 0) // close file, if already opened
            {
                fclose(fptr);
            }

            // Create JPG files from data
            sprintf(j_name, "%03i.jpg", j_count); // JPG file name
            fptr = fopen(j_name, "w");
            fwrite(buffer, 1, 512, fptr); // Write to the JPG file
            if (fptr == NULL)
            {
                fclose(mc);
                printf("Could not write to file %s\n", j_name);
                return 3;
            }
            found = false;
            j_count++; // Increase the count of JPG files
        }
        else if (j_count != 0)
        {
            fwrite(buffer, 1, 512, fptr);
        }
    }

    // Close files
    fclose(fptr);
    fclose(mc);
}
