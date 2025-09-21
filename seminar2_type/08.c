#include <stdio.h>

enum shape 
{
    ROCK,
    PAPER,
    SCISSORS
};

enum result 
{
    LOSS,
    DRAW,
    WIN
};

void print_shape(enum shape s) 
{
    switch (s) 
    {
        case ROCK:    printf("Rock"); break;
        case PAPER:   printf("Paper"); break;
        case SCISSORS: printf("Scissors"); break;
    }
}

void print_result(enum result r) 
{
    switch (r) 
    {
        case LOSS: printf("Loss"); break;
        case DRAW: printf("Draw"); break;
        case WIN:  printf("Win"); break;
    }
}

enum result get_result(enum shape a, enum shape b) 
{
    if (a == b) return DRAW;
    
    switch (a) 
    {
        case ROCK:
            if (b == SCISSORS) 
            {
                return WIN;
            } else 
            {
                return LOSS;
            }
        case PAPER:
            if (b == ROCK) 
            {
                return WIN;
            } else {
                return LOSS;
            }
        case SCISSORS:
            if (b == PAPER) 
            {
                return WIN;
            } else {
                return LOSS;
            }
    }
    return LOSS;
}


enum shape get_strength(enum shape s) 
{
    switch (s) 
    {
        case ROCK:     return SCISSORS;
        case PAPER:    return ROCK;
        case SCISSORS: return PAPER;
    }
    return ROCK;
}

int main(void) 
{
    printf("Rock vs Rock: "); print_result(get_result(ROCK, ROCK)); printf("\n");
    printf("Rock vs Paper: "); print_result(get_result(ROCK, PAPER)); printf("\n");
    printf("Rock vs Scissors: "); print_result(get_result(ROCK, SCISSORS)); printf("\n");

}