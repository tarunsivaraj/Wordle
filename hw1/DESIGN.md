Tarun Sivaraj
Design.md
hw1


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

We would use the switch statement to give values to the names. The way the pig will land.

So lets start with the user inputs

players = input(“Number of players”)
print(“The number of players are: “ + players)

This game can be played with 2 people all the way up to 10 people. If it is more that 10 people ,
 we would get a value error. This would be the first lines of code under the main function where 
 most of the program would take place. The user would type a number ranging from two to ten inclusive 
 and that is how many people would play the game. However there are cases we have to look
at for where invalid inputs could be used. Something like “asdf” would not be counted as a valid input. 
In that case we would need to check if the user input is a valid input.
In python we would do something like this:


try:
    players: input(“Number of players”)
    players: int(players)
except ValueError:
    print(“Invalid number of players using two instead”
    players = 2

If a number more that 10 is inputed, the defalt plaer value will be 2

The next step would be to ask the user input for the seed value. The purpose of the
seed value would be to make grading the assignment easier(I think). What the seed value
does is it makes the random number generated the same if the seed number is the same. So
for example if you input the seed number 5 and the random numbers you get are 4, 2, 6, 1, 5,
the numbers will be exactly the same when you run the program again with the same exact
seed number. Just like the players, the input will work the same for the seed value. The only
difference would be the range. The range would be from 0 to UINT_MAX. This is basically
telling us the maximum unsigned integer. After the user input part, you would go onto the
logic section which would be the harder part of the lab. If the user inputs a negative number it
will set the default seed value to 2021.

Now we would iterate through the players that the user imputed. To do that we would need a
for loop and that would look something like this:

for (int i = 0; i < players; i++)
    print(names[i])

This will iterate through the number of players and it will print out the players names
from the names array. We are given a header file called names.h so all we have to do is
include it and we will be able to use it. As we are iterating we will need to use the random
number generator to find out which way the pig will be landing on. We will set the seed value
using srandom(seed_value) before the while loop. After that we can call random() whenever
we want and however many times as we need. Then we will need to test if the pig lands on its
side and if it does we need to go to the next person turn. For that we will have another while
loop:

while pig[a] != 0:
    Rest of code

Now the keyword ties back to the emun that we are given. The way we use that is if
we try to get the index pig[4] we will get the position of that word. So the position will be 3.
Another example would be pig[1] and pig[0] would both output 0 since they are both SIDE
and SIDE is the first item in the enum. That is why we have to use “switch” so we can get
actual words from the position instead of numbers.


printf("Random seed: ");

The whole game depends on the seed value since it is a random game and it is all luck. The random numbers
 generated will be the same each time if the seeed value does not change.

After that we would need a while loop that keeps running unntil a player has won the game.

int score[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

We would use this to keep track of the score. The max would be 10 since the max number of players would be 10.
If there are 3 players, the first 3 values would be used and the others will remain untouched.

int a = random() % 7 

Now we roll the dice from 0-6. 
After we get the value we will use this

PositionString(pig[a])

This will give us the position the pig landed on instead of a number. 

Each time after the dice is rolled this will be said:

Score[x] += points[a]

X would be the player index value and a would be the random number rolled. After that we
would need to check if a player has hit 100 point so we would use an if statement for that and
it would look something like this:

if score[x] >= 100:
print(player + “won with “ + points + “ points!”
exit

x would represent the player index and it would check at each player, that way the program
would know immediately when someone hits 100 points instead of waiting for someone to
land on side. After a player hits 100 points or higher, the program will exit and it will end.
This is why I feel like having an infinite loop until the if condition is met makes this
assignment a lot easier.

After implementing all of this, the code should work and should run perfectly. Another
important thing would be when you are writing the boundaries for the seed value, it would be
between 0 and UINT_MAX. Since UINT_MAX is an unsigned int, seed_value needs to be
int64_t. Also make sure to add stdint.h in the include section at the top of the code.