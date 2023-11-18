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
void tictac(int arr[9]){
    for(int i=0;i<9;i++){
        printf(" %d " ,arr[i]);
        if(i%3 <2) printf("|");
        if((i+1)%3==0){
            printf("\n");
            if(i<7) for(int j=0;j<3;j++)printf(" -- ");
            printf("\n");
        }
    }
}

int main(){
    int n=1;
    int game;
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    printf("Wanted to play  multiplayer or single \n Enter 1 for multiplayer and 0 for single ");
    scanf("%d",&game);
    if(game){
        
    }else{
        
    }
    tictac(arr);
    
}

