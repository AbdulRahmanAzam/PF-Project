#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]){
	for(int i=0; i < SIZE; i++){
		for(int j =0 ; j < SIZE; j++){
			if(j < SIZE-1) printf(" %c |", board[i][j]);
			else printf(" %c ", board[i][j]);
		}
		printf("\n");
		if(i < SIZE -1) for (int k=0; k < SIZE; k++) printf(" --"); 
		printf("\n"); 
	}
}

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

int isValid(char board[SIZE][SIZE], int row, int col){
	if(board[row][col] >= '1' && board[row][col] <= '9'){
		return 1; // yes position valid
	}
	return 0; // position not valid 
}


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
	board[row][col] = 'X';
}

void single(char board[SIZE][SIZE]){
	while(1){
		printf("current board\n");
		printBoard(board);
		int move;
		int row,col;
		printf("Enter your move ");
		scanf("%d",&move);
		
		row = (move - 1) / 3;
		col = (move - 1) % 3;

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
	}
	return;
}

int main(){
	char board[SIZE][SIZE] = {
		{'1','2','3'},
		{'4','5','6'},
		{'7','8','9'}
	};
	single(board);
}

