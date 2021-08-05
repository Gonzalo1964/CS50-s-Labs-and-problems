#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: recover image\n");
        return 1;
    }
    //Open memory card
    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        printf("Could not open file:\n");
        return 2;
    }
    // declaring variables
    unsigned char BUFFER[512];
    int jpgcounter = 0;
    FILE *output = NULL;
    char *jpgname = malloc(8 * sizeof(char));

    //Repeat until end of card
    while (fread(BUFFER, sizeof(char), 512, input))
    {
        // Looking for JPEG HEADER
        if (BUFFER[0] == 0xff && BUFFER[1] == 0xd8 && BUFFER[2] == 0xff && (BUFFER[3] & 0xf0) == 0xe0 )
        {
            sprintf(jpgname, "%03i.jpg", jpgcounter);
            output = fopen(jpgname, "w");
            jpgcounter++;

        }
        // If already found JPEG
        if (output != NULL)
        {
            fwrite(BUFFER, sizeof(char), 512, output);
        }

    }
    // Closing opened files

    free(jpgname);
    fclose(output);
    fclose(input);
    return 0;
}