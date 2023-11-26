#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 3

void print_board(char board[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        printf("\n");
        for(int j=0;j<SIZE;j++){
            if(j <SIZE-1) printf(" %c |",board[i][j]);
            else printf(" %c ",board[i][j]);
        }
        printf("\n");
        if(i<SIZE-1)  for(int j=0;j<SIZE;j++)  printf(" -- ");
    }
    printf("\n");
}

int isBoardFull(char board[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)  
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return 0; // board is not full
    }
    return 1;//board is full
}

int winner(char board[SIZE][SIZE], char ch){
    for(int i=0;i<3;i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == ch) return 1;
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == ch) return 1;
    }
    //for diagonals
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == ch) return 1;
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == ch) return 1;
    
    return 0;//no any winner
}
bool pos_Validate(char board[SIZE][SIZE], int row, int col){
    if(board[row][col] !='O' && board[row][col] != 'X') return true;
    return false;
}

int evaluate(char board[SIZE][SIZE]){
    if(winner(board, 'X')) return 1;
    else if(winner(board,'O')) return -1;
    else if(isBoardFull(board)) return 0;
    else return 2;
}
int minimax(char board[SIZE][SIZE], int depth, bool isMax){
    int score = evaluate(board);
    if(score != 2) return score;
    
    char ch;
    if(isMax){
        int max = -1000;
        for(int i=0;i < SIZE;i++){
            for(int j=0;j < SIZE;j++){
                if(pos_Validate(board, i, j)){
                    ch = board[i][j];
                    board[i][j] = 'X';
                    int current = minimax(board, depth + 1, !isMax);
                    max = (current > max) ? current : max;
                    board[i][j] = ch;
                }
            }
        }
        return max;
    }else {
        int min = 1000;
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(pos_Validate(board, i, j)){
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

void hard(char board[SIZE][SIZE]){
    int move;
    int bestVal= -1000;
    int row = -1;
    int col = -1;
    char ch;
    // if(isBoardFull(board)){
    //     printf("Game is draw");
    //     return;
    // }
    for(int i=0; i < SIZE; i++){
        for(int j=0; j < SIZE; j++){
            if(pos_Validate(board, i, j)){
                
                ch = board[i][j];
                board[i][j] = 'X';
                move = minimax(board, 0, 0);
                board[i][j] = ch;
                
                if(move > bestVal){
                    row = i;
                    col = j;
                    bestVal = move;
                }
            }
        }
    }
    board[row][col] = 'X';
}

void single(char board[SIZE][SIZE]){
    int difficulty_level;
    int move;    
    int row;
    int col;
    // printf("Do you want to play easy or hard\n\nEnter 1 for Easy and 0 for Hard\n");
    // scanf("%d",&difficulty_level);
    
    do{
        print_board(board);
        printf("Enter move ");
        scanf("%d",&move);
        row = (move - 1) / 3;
        col = (move - 1) % 3;
        
        board[row][col] = 'O';
        
        if(winner(board, 'O')){
            printf("Congratulations you won \n");
            break;
        }
        if(isBoardFull(board)){
            printf("Game is draw");
            break;
        }
        
        hard(board);
        
        if (winner(board, 'X')) {
            printf("Computer wins \n");
            break;
        }

        if (isBoardFull(board)) {
            printf("Game is draw\n");
            break;
        }
    
    }while(isBoardFull(board)!=1);
    return;
}
int main(){
    int game_mode; // to play single or multiplayer 
    int cont; //to continue
    do{
        char board[SIZE][SIZE] = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
        };
        
        printf("Wanted to play  multiplayer or single \n Enter 1 for multiplayer and 0 for single ");
        scanf("%d",&game_mode);    
        
        if(game_mode){
            printf("X is for player 1 and O is for player 2\n");
            // multiplayer(board);
        }else{
            single(board);
        }
        print_board(board);
        
        printf("Do you want to play again, Enter 1 to continue \n");
        scanf("%d",&cont);
    }while(cont);
}





// void multiplayer(char board[SIZE][SIZE]){
//     char player = 'X';
//     int move;
//     int row;
//     int col;
//     do{
//         print_board(board);
//         printf("Turn of player %c, Enter position ",player);
//         scanf("%d",&move);
//         row = (move - 1) / 3;
//         col = (move -1) % 3;
        
//         if(pos_Validate(board,row,col)){
//             if(player == 'X'){
//                 board[row][col] = player;
//             }else if(player == 'O'){
//                 board[row][col] = player;
//             }
             
//             player = (player == 'X') ? 'O' : 'X';
//         }else{
//             printf("Enter move again \n");
//         }
//         if(winner(board)!=0) {
//             printf("Winner is %c\n", winner(board));
//             return;
//         }
//     }while(isBoardFull(board));
//     printf("Game Draw \n");
//     return;
// }
