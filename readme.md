// the turn of the computer which calls minimax algo to find its input
void computer(char board[SIZE][SIZE]){
	int best = -1000;
	int row = -1, col = -1;
	char ch;

	for(int i=0;i < SIZE; i++){
		for(int j=0;j < SIZE; j++){
			if(isValid(board, i, j)){ 
				ch = board[i][j]; 
				board[i][j] = 'X';
				int move = minimax(board, 0, 0);
				board[i][j] = ch;

				if(move > best){
					row = i;
					col = j;
					best = move;
				}
			}
		}
	}
	printf("computer plays move: %d\n", (row * SIZE) + (col + 1));
	board[row][col] = 'X';
}

//when the player is playing with computer
void single(char board[SIZE][SIZE]){
	printBoard(board);
	while(1){
		int move;
		int row,col;
		printf("Enter your move ");
		scanf("%d",&move);
		
		row = (move - 1) / 3;
		col = (move - 1) % 3;
        
        if(isValid(board,row,col)){
    		if(row < 0 || col < 0 || row >=SIZE || col >= SIZE){
    			printf("Invalid move. Try again. \n");
    			continue;
    		}
    
    		board[row][col] = 'O';
    
    		if(winner(board, 'O')){
    			printf("Congratulation you won\n ");
    			break;
    		}
    
    		if(isBoardFull(board)){
    			printf("Game is draw\n");
    			break;
    		}
    
    		computer(board);
    
    		printBoard(board);
    
    		if(winner(board, 'X')){
    			printf("Computer wins\n ");
    			break;
    		}
    
    		if(isBoardFull(board)){
    			printf("Game is draw\n");
    			break;
    		}	
        }else{
	        printf("Invalid input.\n");
	    }
	}
	return;
}


			
##Rock, paper, scissors, lizard, spock
##Rules for the game are as under:
/*
##Rock (0):

##Crushes Scissors.
##Crushes Lizard.
##Paper (1):

##Covers Rock.
##Disproves Spock.
##Scissors (2):

##Cuts Paper.
##Decapitates Lizard.
##Lizard (3):

##Eats Paper.
##Poisons Spock.
##Spock (4):

##Vaporizes Rock.
##Smashes Scissors.
##So, each choice has two possible outcomes: it defeats two other choices and is defeated by two other choices. The goal is to choose the option that defeats your opponent's choice based on these relationships.


##For example:

##If you choose Rock, you win against Scissors and Lizard, but you lose to Paper and Spock.
##If you choose Paper, you win against Rock and Spock, but you lose to Scissors and Lizard.
##The game adds an extra layer of strategy compared to the traditional Rock, Paper, Scissors, as players need to consider the interactions between five choices rather than just three.
*/
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random choice
int generateComputerChoice() {
    return rand() % 5;  // 0: Rock, 1: Paper, 2: Scissors, 3: Lizard, 4: Spock
}

// Function to determine the winner based on choices
int determineWinner(int userChoice, int computerChoice) {
    if ((userChoice == 0 && (computerChoice == 2 || computerChoice == 3)) ||
        (userChoice == 1 && (computerChoice == 0 || computerChoice == 4)) ||
        (userChoice == 2 && (computerChoice == 1 || computerChoice == 3)) ||
        (userChoice == 3 && (computerChoice == 1 || computerChoice == 4)) ||
        (userChoice == 4 && (computerChoice == 0 || computerChoice == 2))) {
        return 1;  // User wins
    } else if (userChoice == computerChoice) {
        return 0;  // It's a tie
    } else {
        return -1; // Computer wins
    }
}

// Function to print choices
void printChoices() {
    printf("Choices:\n");
    printf("0. Rock\n");
    printf("1. Paper\n");
    printf("2. Scissors\n");
    printf("3. Lizard\n");
    printf("4. Spock\n");
}

int main() {
    int userChoice, computerChoice, result;
    char playAgain;

    // Set seed for random number generation
    srand(time(NULL));

    printf("Welcome to Rock, Paper, Scissors, Lizard, Spock!\n");

    do {
        // Get user choice
        printChoices();
        printf("Enter your choice (0-4): ");
        scanf("%d", &userChoice);

        if (userChoice < 0 || userChoice > 4) {
            printf("Invalid choice. Please enter a number between 0 and 4.\n");
            continue;
        }

        // Generate computer choice
        computerChoice = generateComputerChoice();

        // Display choices
        printf("You chose: %d\n", userChoice);
        printf("Computer chose: %d\n", computerChoice);

        // Determine the winner
        result = determineWinner(userChoice, computerChoice);

        if (result == 1) {
            printf("Congratulations! You win!\n");
        } else if (result == -1) {
            printf("Sorry, you lose. Better luck next time!\n");
        } else {
            printf("It's a tie. Try again!\n");
        }

        // Ask if the user wants to play again
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! Goodbye.\n");

    return 0;
}
