   #include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    srand(time(0));
    int score = 0;
    int playAgain = 1;
    
    printf("========================================\n");
    printf("      NUMBER GUESSING GAME\n");
    printf("========================================\n\n");
    
    while (playAgain) {
        int maxNumber, maxAttempts, difficulty;
        
        printf("Choose difficulty:\n");
        printf("1. Easy (1-50, 10 attempts)\n");
        printf("2. Medium (1-100, 7 attempts)\n");
        printf("3. Hard (1-200, 5 attempts)\n");
        printf("Your choice (1-3): ");
        
        if (scanf("%d", &difficulty) != 1 || difficulty < 1 || difficulty > 3) {
            printf("Invalid input! Using Medium difficulty.\n");
            difficulty = 2;
            clearInputBuffer();
        }
        
        // Set game parameters
        if (difficulty == 1) {
            maxNumber = 50;
            maxAttempts = 10;
        } else if (difficulty == 2) {
            maxNumber = 100;
            maxAttempts = 7;
        } else {
            maxNumber = 200;
            maxAttempts = 5;
        }
        
        int secretNumber = rand() % maxNumber + 1;
        int attempts = 0;
        int guessedCorrectly = 0;
        
        printf("\nI'm thinking of a number between 1 and %d.\n", maxNumber);
        printf("You have %d attempts to guess it.\n\n", maxAttempts);
        
        while (attempts < maxAttempts && !guessedCorrectly) {
            int guess;
            printf("Attempt %d/%d - Your guess: ", attempts + 1, maxAttempts);
            
            if (scanf("%d", &guess) != 1) {
                printf("Please enter a valid number!\n");
                clearInputBuffer();
                continue;
            }
            
            attempts++;
            
            if (guess < 1 || guess > maxNumber) {
                printf("Number must be between 1 and %d!\n", maxNumber);
            } else if (guess < secretNumber) {
                printf("Too low! ");
                printf(secretNumber - guess > 20 ? "Way too low!\n" : "Try higher.\n");
            } else if (guess > secretNumber) {
                printf("Too high! ");
                printf(guess - secretNumber > 20 ? "Way too high!\n" : "Try lower.\n");
            } else {
                guessedCorrectly = 1;
                int roundScore = (maxAttempts - attempts + 1) * difficulty * 10;
                score += roundScore;
                
                printf("\n****************************************\n");
                printf("* Congratulations! You got it in %d %s!\n", attempts, attempts == 1 ? "try" : "tries");
                printf("* The number was: %d\n", secretNumber);
                printf("* You earned %d points!\n", roundScore);
                printf("****************************************\n");
            }
            
            // Warning when running low on attempts
            if (!guessedCorrectly && attempts == maxAttempts - 2) {
                printf("Warning: Only 2 attempts left!\n");
            }
            
            printf("\n");
        }
        
        if (!guessedCorrectly) {
            printf("Game over! The number was: %d\n", secretNumber);
        }
        
        printf("Total score: %d\n", score);
        printf("Play again? (1 for Yes, 0 for No): ");
        
        if (scanf("%d", &playAgain) != 1) {
            clearInputBuffer();
            playAgain = 0;
        }
        
        printf("\n");
    }
    
    printf("========================================\n");
    printf("    Thanks for playing! Final score: %d\n", score);
    printf("========================================\n");
    
    return 0;
}             
