#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GAMES 100
#define MAX_TITLE 50

typedef struct 
{
    char title[MAX_TITLE];
    double avg_rating;
} Game;

int compare(const void* a, const void* b) 
{
    Game* game1 = (Game*)a;
    Game* game2 = (Game*)b;
    if (game1->avg_rating < game2->avg_rating) return 1;
    if (game1->avg_rating > game2->avg_rating) return -1;
    return 0;
}

int main() 
{
    int n;
    scanf("%d", &n);

    Game games[MAX_GAMES];

    for (int i = 0; i < n; i++) 
    {
        char title[MAX_TITLE];
        char temp;

        scanf("%[^:]", title);
        int len = strlen(title);
        while (len > 0 && title[len-1] == ' ') 
        {
            title[--len] = '\0';
        }

        scanf("%c", &temp);

        int k;
        scanf("%d", &k);

        int sum = 0;
        for (int j = 0; j < k; j++) 
        {
            int rating;
            scanf("%d", &rating);
            sum += rating;
        }

        games[i].avg_rating = (double)sum / k;

        strcpy(games[i].title, title);

        scanf("%c", &temp);
    }

    qsort(games, n, sizeof(Game), compare);

    for (int i = 0; i < n; i++) 
    {
        printf("%s, %.3f\n", games[i].title, games[i].avg_rating);
    }
}