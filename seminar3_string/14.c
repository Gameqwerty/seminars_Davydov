#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *input_filename = argv[1];
    char *output_filename = argv[2];
    int key = atoi(argv[3]);

    FILE *input = fopen(input_filename, "r");
    FILE *output = fopen(output_filename, "w");
    int ch;
    while ((ch = fgetc(input)) != EOF) 
    {
        ch += key;
        fputc(ch, output);
    }

    fclose(input);
    fclose(output);
}