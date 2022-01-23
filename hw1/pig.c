#include "names.h" // include the names file from the directory

#include <limits.h> // used for UINT_MAX
#include <stdint.h> //used for int64_t
#include <stdio.h>
#include <stdlib.h>

#define SEED 2021

typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER } Position;
const Position pig[7] = { SIDE, SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER, JOWLER };

char *PositionString(Position
        pos) { // wrote this function to get the position of pig and print out the output of my choice
    switch (pos) {
    case SIDE: return "side";
    case RAZORBACK: return "back";
    case TROTTER: return "upright";
    case SNOUTER: return "snout";
    case JOWLER: return "ear";
    }
}

const int points[] = { 0, 0, 10, 10, 15, 5,
    5 }; // used this for the point values and they correspond with the pig array

int main(void) {
    int players; //initialize players
    printf("How many players? "); // ask for input
    scanf("\n%d", &players); // takes input

    if (players > 10 || players < 2) {
        fprintf(stderr,
            "Invalid number of players. Using 2 instead.\n"); //  checks if there is an invalid number of players
        players = 2;
    }

    int64_t seed_value; // initialize seed value
    printf("Random seed: ");
    scanf("%ld", &seed_value); // take random seed input

    if (seed_value < 0 || seed_value > UINT_MAX) {
        fprintf(stderr, "Invalid random seed. Using 2021 instead.\n");
        seed_value = SEED;
    }

    int score[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // array to keep track pf score

    srandom(seed_value);
    while (1) {
        for (int x = 0; x < players; x++) { // iterates through the players playing
            printf("%s", names[x]);
            printf(" rolls the pig...");

            int a = random() % 7; // rolls the dice

            if (pig[a] == 0) { // checks in pig lands on side
                printf(" pig lands on ");
                printf("%s\n", PositionString(pig[a]));
            }

            while (pig[a] != 0) {
                if (pig[a] != 2) { // checks if pig lands upright
                    printf(" pig lands on ");
                    printf("%s",
                        PositionString(
                            pig[a])); // gets the position of the position and prints out what it landed on
                    score[x] += points[a];
                } else {
                    printf(" pig lands ");
                    printf("%s", PositionString(pig[a]));
                    score[x] += points[a]; // added the points to the score array
                }
                if (score[x] >= 100) { // checks to see if a player reached one hundred points
                    printf("\n");
                    printf("%s", names[x]);
                    printf(" wins with ");
                    printf("%d", score[x]);
                    printf(" points!");
                    printf("\n");
                    return 0; // if player reached one hundred points, end program
                }

                a = random() % 7; // variable to roll dice
                if (pig[a] == 0) { // checks again if it rolled on side
                    printf(" pig lands on ");
                    printf("%s\n", PositionString(pig[a]));
                }
            }
        }
    }
    //	printf("%d", players);
    //	printf("%ld", seed_value);
    //	printf("%s", PositionString(pig[3]));
    // ^^^these print statements are to test my code
}
