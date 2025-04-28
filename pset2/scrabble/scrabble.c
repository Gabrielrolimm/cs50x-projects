#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// scores for each letter of the alphabet
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// declare function to calculate
int scorecheck(string words);

// main function of the code
int main(void)
{

    // get each player's words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // use function to calculate the player's scores
    int player1score = scorecheck(word1);
    int player2score = scorecheck(word2);

    // print the results of the game
    if (player1score > player2score)
    {
        printf("Player 1 wins!\n");
    }
    else if (player2score > player1score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// function to check the score of each player's word
int scorecheck(string words)
{
    int score = 0;
    for (int i = 0, length = strlen(words); i < length; i++)
    {
        if (isupper(words[i]))
        {
            score += points[words[i] - 'A'];
        }
        else if (islower(words[i]))
        {
            score += points[words[i] - 'a'];
        }
    }
    return score;
}
