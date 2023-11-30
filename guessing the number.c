//guess the number game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 100
int RandomNumber() {
    return rand() % 100 + 1;
}

// Function to check if the user's guess is correct
int isCorrect(int numberToGuess, int userGuess) {
    if (userGuess == numberToGuess) {
        return 1;  // Guess is correct
    } else if (userGuess > numberToGuess) {
        printf("Too high! Try again.\n");
    } else {
        printf("Too low! Try again.\n");
    }
    return 0;  // Guess is incorrect
}

int main() {
    int numberToGuess, userGuess, attempts = 0;

    // Set seed for random number generation
    srand(time(NULL));

    // Generate a random number between 1 and 100
    numberToGuess = RandomNumber();

    printf("Welcome to the Guess the Number Game!\n");
    printf("Try to guess the number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &userGuess);

        attempts++;

    } while (!isCorrect(numberToGuess, userGuess));

    printf("Congratulations! You guessed the number in %d attempts.\n", attempts);

    return 0;
}
