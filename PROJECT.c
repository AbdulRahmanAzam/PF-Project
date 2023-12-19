int main()
{
    char any[2];
	int choice;
    printf("Enter any key to continue: ");
    scanf("%s",any);
    system("cls");
	do{
        printf(CYAN"^^^^^^^^^"YELLOW" WELCOME" RESET" TO "RESET RED" T "GREEN"R "BLUE"I "YELLOW"P "GREEN"L "RED"E "RESET YELLOW" CHAL"GREEN"LENGE" CYAN" SHOW"RED"DOWN " CYAN"^^^^^^^^^\n"RESET);
        
        printf("\nChoose your interest: "
        "\n\t1. Tic Tac Toe (Multiplayer/Solo) "
        "\n\t2. Guessing the number "
        "\n\t3. Rock, paper, scissors, lizard, spock"
        "\n\t4. Exit game\n");
        scanf("%d",&choice);

        system("cls");

        if(choice==1)
        {
            int cont;
            int level;
            int mode;
            char name[20];
            srand(time(0));
            // printf(BLUE"^^^^^^^^^^"CYAN" WELCOME TO "RED"TIC "GREEN"TAC "CYAN"BOARD"" BATTLE "BLUE"^^^^^^^^^^^\n\n"RESET);
            tictac_name();
            do{
                char board[SIZE][SIZE] = {
                {'1','2','3'},
                {'4','5','6'},
                {'7','8','9'}
                };
                file_func();
                printf("1.Want to play with friend\n"
                "2.Want to play with computer in easy mode\n"
                "3.Want to play with computer in hard mode\n"
                "4.EXIT\n");

                scanf("%d",&mode);
                system("cls");
                if(mode == 1){
                    multiplayer(board);
                }else if(mode == 2){
                    computer(board,mode);//easy mode		
                }else if(mode == 3){
                    computer(board,mode);//hard mode
                }else break;

                printf("Do you want to play again\n"
                "1. To continue\n" 
                "0. To go back\n");
                scanf("%d", &cont);
                system("cls");
            }while(cont);
            
        }else if(choice == 2){
            guessing_the_number();
        }else if(choice == 3){
            rock_paper();
        }else if(choice == 4){
            break;
        }else{
            printf("\nMake a valid choice");
        }
    }while(1);

    printf("\n\n\t\tTHANKS FOR PLAYING! SEE YOU AGAIN");
    Sleep(3000);
    return 0;
}
