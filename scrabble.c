#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int ascii_score(int val);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2) {
        printf("Player 1 wins!");
    } else if (score1 < score2) {
        printf("Player 2 wins!");
    } else {
        printf("Tie!");
    };
}

int compute_score(string word)
{
    int totalPoints = 0;
    int val = 0;
    int len = strlen(word);
    for (int i = 0 ; i < len ; i++) {//one loop for uppercase and one loop for lowercase
        val = word[i];
        if (val >= 65 && val < 91) {
            totalPoints += ascii_score(val);
        } else if (val >= 97 && val < 123) {
            val -= 32;
            totalPoints += ascii_score(val);
        } else {
            totalPoints += 0 ;//just for my own sanity
        };
    }
    return totalPoints;
}

int ascii_score(int val)
{
    val -= 65;
    int points = 0;
    points = POINTS[val];
    return points;
}
