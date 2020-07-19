#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fiveConsecutive.h"
//O(n) complexity because at worse case will traverese each position in 2D array x1
//******* Function prototypes for the function that YOU MUST COMPLETE !!!!
bool HasVerticalWin(char board[N_ROWS][N_COLS]);

//Function prototypes for provided utility functions 
// *** These functions are fully implemented ***
void CheckBoard(const char *boardName, char board[N_ROWS][N_COLS]);

void WinFound(const char color, int column);

/*
-------------------------------------------------------------------------------
Function: main
Description: Checks several boards looking for win conditions and reports.
             Boards are defined in fiveConsecutive.h
        
Parameters: all ignored
			
Returns: EXIT_SUCCESS for a normal exit
		 	 	 	 
-------------------------------------------------------------------------------
*/
int main(int argc, char *argv[]) {
    // CheckBoard("white win column 4", whiteClear);
    // CheckBoard("black win column 4", blackClear);
    // CheckBoard("white win column 0, bracketed by black", whiteBracketed);
    // CheckBoard("black win column 8 at bottom edge", blackBottom);
    // CheckBoard("white win column 0 at top edge", whiteTop);
    // CheckBoard("four consecutive white, no win", whiteFour);
    // CheckBoard("six consecutive black, no win", blackSix);
    // CheckBoard("six consecutive white at bottom edge, no win", whiteSixBottom);
    // CheckBoard("black win column 4 with white sixes", blackWithWhiteSix);
    printf("\n\n");
    return EXIT_SUCCESS;
}

/*
-------------------------------------------------------------------------------
Function: CheckBoard
Description: Checks a single board for win condition by calling HasVerticalWin
			
Parameters: boardname:	a description of the board, to be displayed
					
            board:	a 2D char array representing a game board using BLACK, WHITE,
                  	and EMPTY characters (see fiveConsecutive.h)
                
-------------------------------------------------------------------------------
*/
void CheckBoard(const char *boardName, char board[N_ROWS][N_COLS]) {
    printf("\nChecking board \'%s\'...\n", boardName);
    if (!HasVerticalWin(board)) {
        printf("No win condition found.\n");
    }
    return;
}

/*
-------------------------------------------------------------------------------
Function: WinFound
Description:	Used to display a message if a win condition is found
				
Parameters:	color:	the winning colour; will be BLACK or WHITE
				
            column:	the column in which the winning condition was found
            		
-------------------------------------------------------------------------------
*/
void WinFound(const char color, int column) {
    const char *colorName = (color == BLACK) ? "black"
                                             : "white"; //if color is black print black, if not black then print white
    printf("Win for %s in column %d.\n", colorName, column);
    return;
}

/*
-------------------------------------------------------------------------------
Function: HasVerticalWin
Description: Checks for a win condition, which is exactly five consecutive BLACK 
             or five consecutive WHITE squares in a single column of the board.
             Starts checking from top left corner of the board, ie board[0][0].
             If there are more than five consecutive squares of a single colour
             in a column, that **DOES NOT** constitute a win.
             If a win condition is found, calls WinFound to display the details.
             Stops after finding the first win.
             
Parameters: board:	the board to be tested; a 2D char array representing a
				   	game board using BLACK, WHITE, and EMPTY constants
				   	(see fiveConsecutive.h)
				   	
Returns: 	true if a win condition was found,
			false otherwise

-------------------------------------------------------------------------------
*/
bool HasVerticalWin(char board[N_ROWS][N_COLS]) {

    //traverse 2D array with by going down row first for each column (hence the ordering of the for loops that way with col outer)
    for (int col = 0; col < N_COLS; col++) {
        printf("col %d\n", col);
        for (int row = 0; row < N_ROWS -
                                4; row++) { //can't go past N_ROWS - 4 to find a 5 match because then not enough space to fit at end
            if (board[row][col] !=
                EMPTY) { //because if on an empty there is no point checking that they same because not comparing same with empty
                int count = 1; //make var to store how many repeating letters of same (1 because the one just found is a letter counted towards that)
                printf("row %d\n", row);
                for (int i = (row + 1); i <
                                        N_ROWS; i++) { //i is row+1 because checking the row after the one on right now (to see if matching down the row).
                    printf("row %d col %d board %c\n", i, col, board[i][col]);
                    if (board[row][col] == board[i][col]) {
                        count++; //if current char on board is equal to next char on board, then count goes up 1 because now have one more in a row the same
                    } else {
                        row = i -
                              1; //if it turns out they not the same in following row, bring back to the last one checked (so can start checking from there)
                        break; //to get out of this for loop whose purpose is to check if more repeating down the rows
                    }
                    //check for a win, there 2 options: is at last row and have 5 consecutive same (so cant move further) OR only 5 same in row (next one is not same so counts as win)


//be after the count++. have a check that is already can't make the column have 5 same (because in N_ROWS-4 territory) and count > 5 which means that would be a loss with too many
                    if (count > 5 && i > (N_ROWS - 4)) {
                        row = N_ROWS; //moving to the new col forced because either way with i > N_ROWS, no chance be a 5 same without being too much/too little
                        break;
                    }


                    if (count == 5 && i == N_ROWS - 1) {
                        WinFound(board[row][col],
                                 col); //calls WinFound function passing the character currently on as winner and col where found the winner
                        return true;
                    } else if (count == 5 && (board[row][col] != board[i + 1][col])) {
                        WinFound(board[row][col],
                                 col); //calls WinFound function passing the character currently on as winner and col where found the winner
                        return true;
                    }
                }
            }
        }
    }
    return false;
}  
