# PF semester project Fall 2023

# Project Proposal

Group members:
■ Abdul Rehman Azam [23K-0061]

■ Adina Faraz [23K-0008]

■ Syeda Sara Ali [23K-0070]



Course title: Programming fundamentals [CS1002]

Course instructor: Farooq Zaidi.

Date of submission: 06-10-2023

Project Description:

The project aims to create a classic game in C programming language which has further three games, tic tac toe, guessing the number and rock paper scissors, where the user can play against a computer opponent and multiple players can also play. This project is focused on providing an engaging and interactive gaming experience without specific Al techniques, making it suitable for beginners in programming.
Project Objectives
1. Develop three games within a single functional game with a user-friendly interface.
2. Implement game rules to allow users to play against a computer opponent.
3. First the user will be asked if he/she wants a multiplayer game or single player vs. computer.
4. An option will be provided to the user to choose between the difficulty level, If the user chooses easy level, he/she may have the probability to win but if the user chooses hard level, then the user has the least chances to win, either he/she will lose or the game will be drawn simply.
5. Ensure error handling to prevent crashes and handle invalid user input.
Methods:
Decision Structures (if-else statements or switch-case):
It would be used to check for win conditions, draw scenarios, and valid user input. All the moves of the computer will be based on the game state. Also for the selected level whether hard or easy, otherwise it will generate random guesses. Appropriate messages to the user, such as "Player wins", "It's a draw." Or "Computer won"
Loops (for/while loops):
Implement the main game loop that allows players to take turns until the game ends. loops for input validation, ensuring that users enter valid moves. Check for win conditions and draws within loops after each move.
Arrays:
Arrays are going to store the game data such as player scores, move history. May be 2D array would be used to keep tracking the performance of the computer and a player. Iteration of arrays would be occurred to update and display the game board.
Pointers:
Pointers can be used to pass the values of the arrays to functions, as functions are efficient for the making of game. Infact dynamic memory allocation can also be used with pointers when necessary to manage memory resources.
Files:
File can be used for input and output to save and load game states, allowing players to resume previous games. Store player scores or game statistics in files for long-term tracking.
Functions:
Functions will be made to improve readability and to avoid repetition of same code. They will also make the code precise and handle specific tasks.

## Current progress:
# Introduction
We have created a game with further 3 games in it using C language
The game begins with prompting the user to choose their desired game and difficulty level.
Our TIC TAC TOE game has a significant feature which is:The user can play in two modes either multiplayer or single player vs computer, the second mode will never let the user to win. However, there is a chance of user to win in the first mode.
# work done uptil yet:
3 of all our games are ready.
# Contributions:
Abdul Rehman: Minimax algo, evaluation for tic tac toe
Sara functions in tic tac toe, guessing the number game
Adina : Rock paper scissors, functions

 # The modes we have used in these games are
 Functions(recursive, user defined).
 Minimax algorithm.
 conditional structures.

# What is left to be done?
1. Filing to enhance the functionality.
2. Dynamic handling of memory for multidimentional array manipulation.
3. Adding colors.
