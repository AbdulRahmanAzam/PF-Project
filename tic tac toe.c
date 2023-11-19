#include<stdio.h>
// #include<conio.h> 
void structure(int arr[3][3]){
    int a=1,b,c;
    for(int i =0; i<3; i++){
        for(int j =0; j<3;j++){
            arr[i][j] = a++;
        }
    }
}
void output(int arr[3][3]){
    int a=1,b,c;
    for(int i =0; i<3; i++){
        for(int j =0; j<3;j++){
            printf(" %d ",arr[i][j]);
            if(j<2){
                printf("|");
            }
        }
        printf("\n");
        for(int j =0; j<3;j++){
            if(i<2)
            printf(" -- ");
        }
        printf("\n");
    }
}

int main() {
    int a,b,c,i,j,k;
    int arr[3][3];
    int brr[3][3];
    int inp=0;
    structure(arr);
    output(arr);
            // if(a<9){
            //     for(){
            //         for(){
                        
            //         }
            //     }
            // }    
            for(i=0;i<9;i++){
                printf("Enter position ");
                scanf("%d ",&a);
                switch(a){
                case 1:
                    i=0;
                    j=0;
                break;
                case 2:
                    i=0;
                    j=1;
                break;
                case 3:
                    i=0;
                    j=2;
                break;
                case 4:
                    i=1;
                    j=0;
                break;
                case 5:
                    i=1;
                    j=1;
                break;
                case 6:
                    i=1;
                    j=2;
                break;
                case 7:
                    i=2;
                    j=0;
                break;
                case 8:
                    i=2;
                    j=1;
                break;
                case 9:
                    i=2;
                    j=2;
                break;
                default:
                printf("Enter the correct value");
                
                }
                if(arr[i][j]== 'O' || arr[i][j]== 'X'){
                        printf("Already assigned");
                }else arr[i][j] = 'O';
                system("clear");
                output(arr);
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
                        random
                    }
                }
            }
    return 0;
}


//-------------------------------------------------------------------------------------------------------------------------------





#include <stdio.h>
#include <stdbool.h>
#include <string.h>
void tictac(char *arr){
    for(int i=0;i<9;i++){
        printf(" %c " ,arr[i]);
        if(i%3 <2) printf("|");
        if((i+1)%3==0){
            printf("\n");
            if(i<7) for(int j=0;j<3;j++)printf(" -- ");
            printf("\n");
        }
    }
}
bool check(char *arr){
    int a=0;
    for(int i=0;i<9;i++){
        if(arr[i] == 'X' || arr[i] == 'O'){
           a++; 
        }
    }
    if(a==9) return 0;
    return 1;
}
char winner(char *arr){
    if(arr[0] == arr[1] && arr[1] == arr[2]) return arr[0];
    if(arr[3] == arr[4] && arr[4] == arr[5]) return arr[3];  
    if(arr[6] == arr[7] && arr[7] == arr[8]) return arr[6]; 
    
    if(arr[0] == arr[3] && arr[3] == arr[6]) return arr[0]; 
    if(arr[1] == arr[4] && arr[4] == arr[7]) return arr[1]; 
    if(arr[2] == arr[5] && arr[5] == arr[8]) return arr[2]; 
    
    if(arr[0] == arr[4] && arr[4] == arr[8]) return arr[0]; 
    if(arr[2] == arr[4] && arr[4] == arr[6]) return arr[6]; 
    
    return 0;
    
}
bool posVal(char *arr, int n){
    if(arr[n-1]!='O' && arr[n-1] != 'X') return 1;
    return 0;
}
void multiplayer(char *arr){
    int player =1;
    int pos;
    do{
        tictac(arr);
        printf("Turn of player %d, Enter position ",player);
        scanf("%d",&pos);
        
        if(posVal(arr,pos)){
            if(player==1){
                arr[pos-1] = 'X';
                player++;
            }else{
                arr[pos-1] = 'O';
                player--;
            }
             
        }else{
            printf("Enter position again \n");
        }
        if(winner(arr)!=0) {
            printf("Winner is %c\n", winner(arr));
            return;
        }
    }while(check(arr));
    printf("Game Draw \n");
    return;
}
int computer(char *arr){
    if(arr[0] == arr[1] || arr[0] ==arr[2] || arr[1]==arr[2] == 'X')
    if(arr[3] == arr[4] || arr[3] ==arr[5] || arr[4]==arr[5] == 'X')
    if(arr[6] == arr[7] || arr[6] ==arr[8] || arr[7]==arr[8] == 'X')
    
    if(arr[0] == arr[3] || arr[0] ==arr[6] || arr[3]==arr[6] == 'X')
    if(arr[1] == arr[4] || arr[1] ==arr[7] || arr[4]==arr[7] == 'X')
    if(arr[2] == arr[5] || arr[2] ==arr[8] || arr[5]==arr[8] == 'X')
    
    if(arr[0] == arr[4] || arr[0] ==arr[8] || arr[4]==arr[8] == 'X')
    if(arr[2] == arr[4] || arr[2] ==arr[6] || arr[4]==arr[8] == 'X')
}
void hard(char *arr){
    int player =1;
    int pos;
    do{
        if(player ==1){
            printf("Enter position ");
            scanf("%d", &pos);
            player++;
        }else{
            pos = computer(arr);
            player--;
        }
        if(posVal(arr,pos)){
            if()
        }else{
            printf("Enter position again \n");
        }
    }while();
}
int main(){
    int difficulty;
    int game;
    
    do{
        char arr[] = {'1','2','3','4','5','6','7','8','9'};
        
        printf("Wanted to play  multiplayer or single \n Enter 1 for multiplayer and 0 for single ");
        scanf("%d",&game);    
        
        if(game){
            printf("X is for player 1 and O is for player 2\n");
            multiplayer(arr);
        }else{
            printf("Do you want to play easy or hard\n\nEnter 1 for Easy and 0 for Hard\n");
            scanf("%d",&difficulty);
            if(difficulty){
                
            }else{
                hard(arr);
            }
        }
        tictac(arr);
    
    }while();
    
}
