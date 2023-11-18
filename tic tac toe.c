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
