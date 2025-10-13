#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** get_test_strings()
{
    char** arr = (char**) malloc(4 * sizeof(char*));

    arr[0] = (char*) malloc(4 * sizeof(char));
    strcpy(arr[0], "Cat");

    arr[1] = (char*) malloc(7 * sizeof(char));
    strcpy(arr[1], "Mouse");

    arr[2] = (char*) malloc(9 * sizeof(char));
    strcpy(arr[2], "Elephant");

    arr[3] = NULL;

    return arr;
}

void print_strings(char** string_array)
{
    int i = 0;
    while (string_array[i] != NULL)
    {
        printf("%s\n", string_array[i]);
        i++;
    }
}

size_t* get_sizes(char** string_array)
{
    int count = 0;
    while (string_array[count] != NULL)
    {
        count++;
    }

    size_t* sizes = (size_t*) malloc(count * sizeof(size_t));

    for (int i = 0; i < count; i++)
    {
        sizes[i] = strlen(string_array[i]) + 1;
    }

    return sizes;
}

char** load_lines(const char* filename)
{
    FILE* file = fopen(filename, "r");

    int line_count = 0;
    int c;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n')
        {
            line_count++;
        }
    }
    line_count++;

    char** lines = (char**) malloc((line_count + 1) * sizeof(char*));

    fseek(file, 0, SEEK_SET);

    size_t* lengths = (size_t*) malloc(line_count * sizeof(size_t));
    for (int i = 0; i < line_count; i++)
    {
        lengths[i] = 0;
        while ((c = fgetc(file)) != '\n' && c != EOF)
        {
            lengths[i]++;
        }
        lengths[i]++;
    }

    fseek(file, 0, SEEK_SET);

    for (int i = 0; i < line_count; i++)
    {
        lines[i] = (char*) malloc(lengths[i]);
        fgets(lines[i], lengths[i], file);
        size_t len = strlen(lines[i]);
        if (len > 0 && lines[i][len - 1] == '\n')
        {
            lines[i][len - 1] = '\0';
        }
    }

    lines[line_count] = NULL;

    free(lengths);
    fclose(file);

    return lines;
}

void destroy_strings(char*** p_string_array)
{
    int i = 0;
    while ((*p_string_array)[i] != NULL)
    {
        free((*p_string_array)[i]);
        i++;
    }

    free(*p_string_array);
    *p_string_array = NULL;
}

void sort_strings(char** words)
{
    int count = 0;
    while (words[count] != NULL)
    {
        count++;
    }

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (strcmp(words[i], words[j]) > 0)
            {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    char** lines = load_lines(argv[1]);

    sort_strings(lines);

    FILE* out_file = fopen(argv[2], "w");

    int i = 0;
    while (lines[i] != NULL)
    {
        if (lines[i][0] != '\0')
    {
        fprintf(out_file, "%s\n", lines[i]);
    }
        i++;
    }

    fclose(out_file);
    destroy_strings(&lines);
}