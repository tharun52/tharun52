#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const int JPEG_LEN = 512;

typedef uint8_t byte;

int main(int argc, char *argv[])
{
    // if no file is given
    if (argc < 2)
    {
        printf("please enter atleast one file to open\n");
        return 1;
    }
    // if more than one file is given
    else if (argc > 2)
    {
        printf("Enter only one file to open\n");
        return 1;
    }

    // Opening the file
    FILE *file = fopen(argv[1], "r");
    
    // when the file cannot be opened
    if (file == NULL)
    {
        printf("Cound not open the file\n");
        return 1;
    }

    // initializing few values
    FILE *JPEG;
    byte buffer[JPEG_LEN];
    int jpeg_found = 0;
    int jpeg_num = 0;

    while (fread(buffer, sizeof(buffer), 1, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg_found == 0)
            {
                jpeg_found = 1;
            }
            else
            {
                fclose(JPEG);
            }
            
            // creating the file name
            char filename[8];
            sprintf(filename, "%03i.jpg", jpeg_num);
            
            // creating the jpg file and writing into it
            JPEG = fopen(filename, "w");
            fwrite(buffer, sizeof(buffer), 1, JPEG);
        
            // updating the number of jpeg
            jpeg_num++;
        }
        else
        {
            if (jpeg_found == 1)
            {
                fwrite(buffer, sizeof(buffer), 1, JPEG);
            }
        }
    }
    fclose(JPEG);
    fclose(file);
}
