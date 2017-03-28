#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
	for(int rows = 0; rows < BOARD_ROWS; rows++)
	{
		std::vector <Piece> temp;
		for(int columns = 0; columns < BOARD_COLS; columns++)
		{
			temp.push_back(Blank);
		}
		board.push_back(temp);
	}
	turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/

void Piezas::reset()
{
	for(int rows = 0; rows < BOARD_ROWS; rows++)
	{
		for(int columns = 0; columns < BOARD_COLS; columns++)
		{
			board[rows][columns] = Blank;		
		}
	}

}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 

Piece Piezas::dropPiece(int column)
{
	if(column > BOARD_COLS || column < 0)
	{
		return Invalid;
		if(turn == X)
		{	
			turn = O;
			return X;
		}
		else if(turn  == O)
		{
			turn = X;
			return O;
		}
	}
	else
	{
		if(board[0][column] == Blank)
		{
			board[0][column] = turn;
			if(turn == X)
			{
				turn = O;
				return X;
			}
			else if(turn  == O)
			{
				turn = X;
				return O;
			}
		}
		else if(board[1][column] == Blank)
		{
			board[1][column] = turn;
			if(turn == X)
			{
				turn = O;
				return X;
			}
			else if(turn  == O)
			{
				turn = X;
				return O;
			}
		}
		else if(board[2][column] == Blank)
		{
			board[2][column] = turn;
			if(turn == X)
			{
				turn = O;
				return X;
			}
			else if(turn  == O)
			{
				turn = X;
				return O;
			}
		}
		else
		{
			return Blank;
		}
	}
		return turn;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/

Piece Piezas::pieceAt(int row, int column)
{
	if(column > BOARD_COLS || column < 0 || row > BOARD_ROWS || row < 0)
	{
		return Invalid;
	}
	else if(board[row][column] == Blank)
	{
		return Blank;
	}
	else
	{
		return board[row][column];
	}
}


/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/

Piece Piezas::gameState()
{
	for(int rows = 0; rows < BOARD_ROWS; rows++)
	{
		for(int columns = 0; columns < BOARD_COLS; columns++)
		{
			if(board[rows][columns] == Blank)		
			{
				return Invalid;
			}
		}
	}	
	
	int xWinnerCount = 0;
	int oWinnerCount = 0;
	for(int rows = 0; rows < BOARD_ROWS; rows++)
	{
		int xCount = 0;
		int oCount = 0;
		for(int columns = 0; columns < BOARD_COLS; columns++)
		{
			if(board[rows][columns] == X)		
			{
				xCount++;
			}
			else if(board[rows][columns] == O)		
			{
				oCount++;
			}
		}
		if(xCount == 4)
			xWinnerCount++;
		else if(oCount == 4)
			oWinnerCount++;
	}	
	for(int columns = 0; columns < BOARD_COLS; columns++)
	{
		int xCount = 0;
		int oCount = 0;
		for(int rows = 0; rows < BOARD_ROWS; rows++)
		{
			if(board[rows][columns] == X)		
			{
				xCount++;
			}
			else if(board[rows][columns] == O)		
			{
				oCount++;
			}
		}
		if(xCount == 3)
			xWinnerCount++;
		else if(oCount == 3)
			oWinnerCount++;
	}	
	if(xWinnerCount > oWinnerCount)
		return X;
	else if(oWinnerCount > xWinnerCount)
		return O;
	else if(xWinnerCount == oWinnerCount)
		return Blank;
return Invalid;	
}
