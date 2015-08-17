//
//  main.cpp
//  TicTacToe Game
//
//  Created by Ibraheem Nadeem on 8/17/15.
//  Copyright (c) 2015 Ibraheem Nadeem. All rights reserved.
//

//Prototypes:

void DisplayBoard (char board[3][3]);
void ResetBoard (char board [3][3]);
int SelectLocation (char turn, char board[3][3], int *location);
void setTurn (int *location, char turn, char board[3][3]);
int checkForWin (char board [3][3]);
int SelectLocation (char turn, char board[3][3], int *location);



#include <iostream>

int main(int argc, const char * argv[])
{
    
    int location, i, win=0; // Will make win = value returned from "CheckForWin" function
    int locationSelect; // Will make this = to value returned from "SelectLocation" function
    char board [3][3] = {'1','2','3','4','5','6','7','8','9'};
    char turn = 'X';  // Initialize the first player to Player X
    char playAgain;// Will let the user play again if they enter Y or y
    
    
    do {
        
        ResetBoard(board); // New Board from 1-9
        
        do
        {
            
            for (i=0; i<9; i++)
            {
            
                DisplayBoard(board); // Displays The Board
                locationSelect = SelectLocation (turn, board, &location); // Asks user for location
                setTurn(&location, turn, board); //Puts either X or O onto board
                win = checkForWin(board); // Checks if Win ==1 or 0
            
                if (win ==1) // if win ==1, then then the player wins
                {
                    std::cout << "\n\n*********************************";
                    std::cout << "\n\n Player ""'"<< turn <<"'" " Won! ";
                    DisplayBoard(board);
                    
                    std::cout << "\n\n*********************************";
                    
                    break;// Breaks the loop if the player wins

                }
                
                if (turn =='X')    // This statement switches the players once it loops again
                    turn ='O';
                else
                    turn = 'X';
            }
            
            if (win ==0 && i ==9)  // Will determine tie game
            {
                std::cout << "\n\n*********************************\n";

                std::cout << "\nIt was a tie game!\n";
                DisplayBoard(board);
                
                std::cout << "\n\n*********************************";

                break; // Breaks loop if it's a tie game
            }
      } while (win ==0);

            std::cout << "\n\nWould you like to play again? (Y or N) : ";
            std::cin >> playAgain;
        
    } while (playAgain == 'Y' || playAgain =='y'); // Will keep looping if player enters Y or y
    
    
    std::cout << "\n\nThank you for playing!";

    return 0;
}

// *****************************************************************
// Function that will Display the board

void DisplayBoard (char board[3][3])
{

    std::cout << "\n\n";
    std::cout << " " << board[0][0]<< " |" << " " << board[0][1]<< " |" << " " << board[0][2] << std::endl;
    std::cout << "---+---+---\n";
    std::cout << " " << board[1][0]<< " |" << " " << board[1][1]<< " |" << " " << board[1][2] << std::endl;
    std::cout << "---+---+---\n";
    std::cout << " " << board[2][0]<< " |" << " " << board[2][1]<< " |" << " " << board[2][2] << std::endl;

}
// *****************************************************************

// Function that will reset the board values
void ResetBoard (char board [3][3])

{
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';
}
// *****************************************************************

int SelectLocation (char turn, char board[3][3], int *location)
{
    
    int valid = 0; // Initilized to 0, will be used to validate if everything is correct

    // Do while loop that has a do while loop and a switch statement within.
    // First will ask user to enter location and it will keep asking if location <1 or location>9.
    /* It will then go to the switch statement and determine if the location of the board is == X or O.
     If it is, it will then set valid =-1 and will loop to the top again and ask them to enter another location.
     */

    
    
    do {
        
        do {

            std::cout << "\n\nPlayer ""'"<< turn << "'" " Please Enter a Location (1-9): ";
            std::cin >> *location;

    
            if (*location <1 || *location>9) // Checks if user entered a number less than 1 or greater than 9
            {
                std::cout << "\nInvalid Choice!";
                DisplayBoard(board); // Displays Board again!
                std::cout << "\n\nPlayer ""'"<< turn << "'" " Please Enter a Location (1-9): ";
                std::cin >> *location;
            }
            } while (*location <1 || *location>9);

    
    switch (*location) { // Checks the board to see if 'X' or 'O' are already there (if space already taken)
        case 1:
            if (board[0][0] =='X' || board[0][0] == 'O')
            {
                std::cout <<"\nInvalid Choice, please enter another location";
                DisplayBoard(board);
                valid = -1;
            } else
                valid = 1;
            break;
        case 2:
            if (board[0][1] =='X' || board[0][1] == 'O')
            {
                std::cout <<"\nInvalid Choice, please enter another location";
                DisplayBoard(board);
                valid = -1;
            } else
                valid = 1;
            break;
        case 3:
            if (board[0][2] =='X' || board[0][2] == 'O')
            {
                std::cout <<"\nInvalid Choice, please enter another location\n";
                DisplayBoard(board);
                valid = -1;
            } else
                valid = 1;
            break;
        case 4:
            if (board[1][0] =='X' || board[1][0] == 'O')
            {
                std::cout <<"\nInvalid Choice, please enter another location";
                DisplayBoard(board);
                valid = -1;
            } else
                valid = 1;
            break;
        case 5:
            if (board[1][1] =='X' || board[1][1] == 'O')
            {
                std::cout <<"\nInvalid Choice, please enter another location";
                DisplayBoard(board);
                valid = -1;
            } else
                valid = 1;
            break;
        case 6:
            if (board[1][2] =='X' || board[1][2] == 'O')
            {
                std::cout <<"\nInvalid Choice, please enter another location";
               DisplayBoard(board);
                valid = -1;
            } else
                valid = 1;
            break;
        case 7:
            if (board[2][0] =='X' || board[2][0] == 'O')
            {
                std::cout <<"\nInvalid Choice, please enter another location";
                DisplayBoard(board);
                valid = -1;
            } else
                valid = 1;
            break;
        case 8:
            if (board[2][1] =='X' || board[2][1] == 'O')
            {
                std::cout <<"\nInvalid Choice, please enter another location";
                DisplayBoard(board);
                valid = -1;
            } else
                valid = 1;
            break;
        case 9:
            if (board[2][2] =='X' || board[2][2] == 'O')
            {
                std::cout <<"\nInvalid Choice, please enter another location";
                DisplayBoard(board);
                valid = -1;
            } else
                valid = 1;
            break;
        default: std::cout <<"\nPlease enter a location between 1 and 9: ";
                DisplayBoard(board);
            break;
    }
        } while (valid == -1);

    
    return *location;

}
// *****************************************************************

// Will change the board and make it either X or O depending on the location selected by the user

void setTurn (int *location, char turn, char board[3][3])
{

    
    switch (*location) {
        case 1:
            board[0][0] = turn;
            break;
        case 2:
            board[0][1] = turn;
            break;
        case 3:
            board[0][2] = turn;
            break;
        case 4:
            board[1][0] = turn;
            break;
        case 5:
            board[1][1] = turn;
            break;
        case 6:
            board[1][2] = turn;
            break;
        case 7:
            board[2][0] = turn;
            break;
        case 8:
            board[2][1] = turn;
            break;
        case 9:
            board[2][2] = turn;
        default:
            break;
    }

}


// *****************************************************************
// This function will check All the 8 possible combinations of winning and will return either 1 or 0
int checkForWin (char board [3][3])

{
    
    if ((board [0][0] == board [1][1] && board [0][0] == board [2][2]) || (board [0][2] == board [1][1] && board [0][2] == board [2][0]) || (board [0][0] == board [0][1] && board [0][0] == board [0][2]) || (board [1][0] == board [1][1] && board [1][0] == board [1][2]) || (board [2][0] == board [2][1] && board [2][0] == board [2][2]) || (board [0][0] == board [1][0] && board [0][0] == board [2][0]) || (board [0][1] == board [1][1] && board [0][1] == board [2][1]) || (board [0][2] == board [1][2] && board [0][2] == board [2][2]))
        
        return 1;
    
    else
        return 0;
    
}
// *****************************************************************

