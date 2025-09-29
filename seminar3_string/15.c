#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_integer(const char *str) 
{
    if (!str || !*str) return 0;
    int i = 0;
    if (str[0] == '-' || str[0] == '+') i++;
    for (; str[i]; i++) 
    {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int parse_range(const char *str, int *start, int *end) 
{
    char *colon = strchr(str, ':');
    if (!colon) return 0;

    char temp[256];
    strncpy(temp, str, colon - str);
    temp[colon - str] = '\0';

    if (!is_integer(temp)) return 0;
    *start = atoi(temp);

    if (strlen(colon + 1) == 0) return 0;
    if (!is_integer(colon + 1)) return 0;
    *end = atoi(colon + 1);

    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 4) 
    {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: ./line_extractor <input_file> <output_file> <lines>\n");
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    char *lines_spec = argv[3];

    FILE *input = fopen(input_filename, "r");
    if (!input) 
    {
        printf("Error: File %s does not exist!\n", input_filename);
        return 1;
    }

    int start_line = 0, end_line = 0;
    int is_single = 0;

    if (is_integer(lines_spec)) 
    {
        start_line = atoi(lines_spec);
        end_line = start_line + 1;
        is_single = 1;
    } else if (parse_range(lines_spec, &start_line, &end_line)) 
    {
        if (start_line >= end_line) 
        {
            printf("Error: Invalid range (start >= end)!\n");
            fclose(input);
            return 1;
        }
    } else 
    {
        printf("Error: Wrong lines format!\n");
        fclose(input);
        return 1;
    }

    FILE *output = fopen(output_filename, "w");
    if (!output) 
    {
        printf("Error: Cannot create output file '%s'\n", output_filename);
        fclose(input);
        return 1;
    }

    char line[1024];
    int current_line = 1;

    while (fgets(line, sizeof(line), input)) 
    {
        if (current_line >= start_line && current_line < end_line) 
        {
            fputs(line, output);
        }
        current_line++;
    }

    fclose(input);
    fclose(output);

    printf("Lines extracted successfully.\n");
}