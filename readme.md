# PF semester project Fall 2023

# Project Proposal


## Group members:

■ Abdul Rehman Azam [23K-0061]

■ Adina Faraz [23K-0008]

■ Syeda Sara Ali [23K-0070]

### Course title: Programming fundamentals [CS1002]
### Course instructor: Farooq Zaidi.
### Date of submission: 06-10-2023

# Project Illustration:

The project aims to create a classic game named as "CRYPTOGRAM BRAINDOM" using C programming language which includes three games, Tic Tac Toe, Guessing The Number and Rock Paper Scissors Lizard Spork. Firstly and most importantly, the user will be asked to choose any 1 of the tree metioned games.

## TIC TAC TOE:
First and Foremost, in Tic Tac Toe the user can play against a computer or against a person which is based upon user's choice. After that the user can choose the difficulty level to determine how easy or hard they want the game to be. While playing against a computer if he picks an easy level, there will be a posiblity that he might win, However, if he chooses hard then either he will lose or the game will be drawn.
Moreover, if the game is being played against the computer, the user will make their choice, and the computer will. The computer's move completely depends upon some functions and the mini-max algorithm. In this case, either the computer will win the game, or it will end in a draw.However, when the game is being played between two people, both of them will make their choices sequentially, and one of them will win the game. 

## ROCK PAPER SCISSOR LIZARD SPOCK:
Basically, in this game the user can choose amoung these 5 options (mainly Rock, Paper, Scissors, Lizard, Spork).Afterward, the user will make his choice, and then accordingly the computer will choose using a random function. Then the winner will be chosen using some functions. Either user will win or lose.

## GUESSIG THE NUMBER:
First'y, the computer will generate a number between 1-100 randomly using a function. Thereafter, the user will be asked to input his guesses this process will be continued till the user guesses correctly. When the user Will successfully guess the 
number, he'll win the game. The screen will also display the number of attempts made by the user in order guess the number.

## Further Project Description:

This project focuses on providing an interactive and engaging gaming experience, making it suitable for beginners in programming.
### Project Objectives:

Develop three games within a single functional game with a user-friendly interface.
Implement game rules to allow users to play against a computer opponent.First the user will be asked if he/she wants a multiplayer game or single player vs. computer game. Then an option will be provided to the user to choose the difficulty level. If the user chooses easy level, he/she may have the probability to win but if the user chooses hard level, then the user has no chances to win, either he/she will lose or the game will be drawn simply.(only for tic tac toe).
Ensure error handling to prevent crashes and handle invalid user input.

### Methods:
#### Decision Structures (if-else statements or switch-case):
It would be used to check for win conditions, draw scenarios, and valid user input. All the moves of the computer will be based on the game state. Also for the selected level whether hard or easy, otherwise it will generate random guesses. Appropriate messages to the user, such as "Player wins", "It's a draw." Or "Computer won"
#### Loops (for/while loops):
Implement the main game loop that allows players to take turns until the game ends. loops for input validation, ensuring that users enter valid moves. Check for win conditions and draws within loops after each move.
#### Arrays:
2D array would be used in tic tac toe game as the major part of this game will use2D array. Iteration of arrays would be occurred to update and display the game board. If needed array will be used to keep track of the performance of the computer and the player.
#### Filing:
File can be used for input and output to save and load game states, allowing players to resume previous games. Store player scores or game statistics in files for long-term tracking.
#### Functions:
Functions will be made to improve readability and to avoid repetition of same code. They will also make the code precise and handle specific tasks.

## Progress:

### Current Progress:
The 3 games that are the part of our project are almost completed. Just some functionalities are to be added including filing, adding UI to make our work look more attractive, merging the games and some other basic stuff are to be done.

### Main Modes Used:
Functions(recursive, user defined).
Minimax algorithm.
conditional structures.
Filing.
enhancing UI
   
## Contributions:

#### Abdul Rehman Azam: 
Minimax algo and Evaluation for tic tac toe

#### S. Sara Ali: 
Functions in tic tac toe and Guessing the number game

#### Adina Faraz:
Rock paper scissors and Functions for tic tac toe
