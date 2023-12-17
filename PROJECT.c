#include<stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 3
//Function to generate random number between 1 and 100
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
int generateComputerChoice() {
    return rand() % 5;  // 0: Rock, 1: Paper, 2: Scissors, 3: Lizard, 4: Spock
}

// Function to determine the winner based on choices
int determineWinner(int userChoice, int computerChoice) {
    if ((userChoice == 1 && (computerChoice == 3 || computerChoice == 4)) ||
        (userChoice == 2 && (computerChoice == 1 || computerChoice == 5)) ||
        (userChoice == 3 && (computerChoice == 2 || computerChoice == 4)) ||
        (userChoice == 4 && (computerChoice == 2 || computerChoice == 5)) ||
        (userChoice == 5 && (computerChoice == 1 || computerChoice == 3))) {
        return 1;  // User wins
    } else if (userChoice == computerChoice) {
        return 0;  // It's a tie
    } else {
        return -1; // Computer wins
    }
}

// Function to print choices
void printChoices() {
    printf("Choices:\n"
    "1. Rock\n"
    "2. Paper\n"
    "3. Scissors\n"
    "4. Lizard\n"
    "5. Spock\n");
}

void printBoard(char board[SIZE][SIZE]);
int isBoardFull(char board[SIZE][SIZE]);
int winner(char board[SIZE][SIZE], char ch);
int isValid(char board[SIZE][SIZE], int row, int col);
int evaluate(char board[SIZE][SIZE]);
int minimax(char board[SIZE][SIZE], int depth, bool isMax);
void best_move(char board[SIZE][SIZE]);
void easy_move(char board[SIZE][SIZE]);
void computer(char board[SIZE][SIZE],int mode);
void multiplayer(char board[SIZE][SIZE]);

//to print the board of tic tac toe
void printBoard(char board[SIZE][SIZE]){
  // printf("\033[36m^^^^^^^^^^ WELCOME TO TIC TAC BOARD BATTLE ^^^^^^^^^^^\033[0m\n\n");
      printf("\033[33m***************\033[0m\n"); 
  for(int i=0; i < SIZE; i++){

    for(int j =0 ; j < SIZE; j++){
        if(board[i][j] == 'X'){
           printf("\033[33m|\033[0m \033[31m%c\033[0m \033[33m|\033[0m", board[i][j]);
        }else if(board[i][j] == 'O'){
            printf("\033[33m|\033[0m \033[34m%c\033[0m \033[33m|\033[0m", board[i][j]);
        }else
             printf("\033[33m|\033[0m %c \033[33m|\033[0m", board[i][j]);
    }
    printf("\n");
     if(i < SIZE -1) printf("\033[33m---------------\033[0m\n"); 

  }
  printf("\033[33m***************\033[0m\n"); 
}

//check whether the board have available inputs or not
int isBoardFull(char board[SIZE][SIZE]){
  for(int i=0;i < SIZE; i++){
    for(int j=0;j <SIZE; j++){
      if(board[i][j] >= '1' && board[i][j] <= '9'){
        return 0; // board is not full
      }
    }
  }
  return 1; // board is full
}

// to check whether player wins or not
int winner(char board[SIZE][SIZE], char ch){
  for(int i=0;i < SIZE; i++){
    if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == ch ) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == ch)) {
            return 1;  // Player wins
        }
  }

  if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == ch) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == ch)) {
        return 1;  // Player wins
    }

    return 0;
}

// to check whether the move is valid or it is already input before
int isValid(char board[SIZE][SIZE], int row, int col){
  if(board[row][col] >= '1' && board[row][col] <= '9'){
    return 1; // yes position valid
  }
  return 0; // position not valid 
}

// evaluation funciton used for minimax algorithm
int evaluate(char board[SIZE][SIZE]){
  if(winner(board, 'X')){
    return 1; // computer wins
  } else if(winner(board, 'O')){
    return -1; // player wins
  } else if(isBoardFull(board)){
    return 0; // its a draw
  } else {
    return 2; // game is going on
  }
}

//minimax algorithm which is recursive function, calculates the best input by checking the whole game (ARTIFICIAL INTELLIGENCE)
int minimax(char board[SIZE][SIZE], int depth, bool isMax){
  int score = evaluate(board);
  if(score != 2){
    return score;
  }
  char ch;
  if(isMax){
    int max = -1000;
    for(int i=0;i < SIZE; i++){
      for(int j=0; j < SIZE; j++){
        if(isValid(board, i, j)){
          ch = board[i][j]; 
          board[i][j] = 'X';
          int current = minimax(board,depth + 1, !isMax);
          max = (current > max) ? current : max;
          board[i][j] = ch; 
        }
      }
    }
    return max;
  }else {
    int min = 1000;
    for(int i=0;i < SIZE; i++){
      for(int j=0;j < SIZE; j++){
        if(isValid(board, i, j)){
          ch = board[i][j];
          board[i][j] = 'O';
          int current = minimax(board, depth + 1, !isMax);
          min = (current < min) ? current : min;
          board[i][j] = ch; 
        }
      }
    }
    return min;
  }
}

// the turn of the best_move which calls minimax algo to find its input
void best_move(char board[SIZE][SIZE]){
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

void easy_move(char board[SIZE][SIZE]){
    int move;
    int row;
    int col;
    do{
        move = (rand() % 9) + 1;
        row = (move - 1) / 3;
        col = (move - 1) % 3;
    }while(isValid(board,row,col) == 0);

    board[row][col] = 'X';
    printf("Computer move %d\n",move);
}

//when the player is playing with computer
void computer(char board[SIZE][SIZE], int mode){
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
        //   system("cls");
          printf("\033[36m^^^^^^^^^^ WELCOME TO TIC TAC BOARD BATTLE ^^^^^^^^^^^\033[0m\n\n");
          if(mode == 2) easy_move(board);
          if(mode == 3) best_move(board);
        
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

void multiplayer(char board[SIZE][SIZE]){
  char player = 'X';
  int move;
  int row,col;
  while(1){
    // system("cls");

    printBoard(board);
    printf("player %c enter move ",player);
    scanf("%d", &move);
    row = (move - 1) / 3;
    col = (move - 1) % 3;

    if(isValid(board,row,col)){
      if(player == 'X'){
        board[row][col] = 'X';
      }else if(player == 'O'){
        board[row][col] = 'O';
      }

    }else{
      printf("Invalid input, Enter correct move\n");
      player = (player == 'X') ? 'O' : 'X';
    }

    if(winner(board,player)){
      printf("Congratulations player %c won the game!\n", player);
      return;
    } 
    if(isBoardFull(board)){
      printf("Game is Draw\n");
      return;
    }

    player = (player == 'X') ? 'O' : 'X';
  }
}


int main()
{
	int num;
	printf("----------WELCOME TO THE CRYPTOGRAM BRAINDOM----------");
	printf("\nChoose your interest: ");
	printf("\n1. Tic Tac Toe (Multiplayer/Solo) ");
	printf("\n2. Guessing the number ");
	printf("\n3. Rock, paper, scissors, lizard, spock\n");
	scanf("%d",&num);

	if(num==1)
	{
		 int cont;
  int level;
  int mode;
  char name[20];
  srand(time(0));
  printf("\033[36m^^^^^^^^^^ WELCOME TO TIC TAC BOARD BATTLE ^^^^^^^^^^^\033[0m\n\n");
  do{
    char board[SIZE][SIZE] = {
      {'1','2','3'},
      {'4','5','6'},
      {'7','8','9'}
    };
    printf("1.Want to play with friend\n"
    "2.Want to play with computer in easy mode\n"
    "3.Want to play with computer in hard mode\n"
    "4.EXIT\n");

    scanf("%d",&mode);
    // system("clear");
    if(mode == 1){
      multiplayer(board);
    }else if(mode == 2){
      computer(board,mode);//easy mode		
    }else if(mode == 3){
        computer(board,mode);//hard mode
    }else break;

    printf("Do you want to play again\n"
    "1. To continue\n" 
    "0. To exit\n");

    scanf("%d", &cont);
  }while(cont);
  printf("See you again!");
    return 0;
}
	
	if(num==2)
	{
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
	
	if(num==3)
	{
		int userChoice, computerChoice, result;
    char playAgain;

    // Set seed for random number generation
    srand(time(NULL));

    printf("Welcome to Rock, Paper, Scissors, Lizard, Spock!\n");

    do {
        // Get user choice
        printChoices();
        printf("Enter your choice (1-5): ");
        scanf("%d", &userChoice);

        if (userChoice < 1 || userChoice > 5) {
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
		
		else{
			printf("\nMake a valid choice");
		}
}
