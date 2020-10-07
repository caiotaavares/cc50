/***************************************************************************
 * fifteen.c
 *
 * CC50
 * Pset 3
 *
 * Implements The Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 ***************************************************************************/
 
#define _XOPEN_SOURCE 500

#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// constants
#define DIM_MIN 3
#define DIM_MAX 9


// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);


int
main(int argc, char *argv[])
{
    // greet user with instructions
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: %s d\n", argv[0]);
        return 1;// prototypes
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %d x %d and %d x %d, inclusive.\n",
         DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

	//GOD mode
	if (tile = GOD)
	{
		
	}


        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}


/*
 * Clears screen using ANSI escape sequences.
 */

void
clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}


/*
 * Greets player.
 */

void
greet(void)
{
    clear();
    printf("WELCOME TO THE GAME OF FIFTEEN\n");
    usleep(2000000);
}


/*
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void
init(void)
{
    	// total_spaces get the number of spaces
	int total_spaces = d * d;

	//tho for cicles to get the tiles to board[i][j]
	for(int i = 0; i < d; i ++)
	{
		for(int j = 0; j < d; j ++)
		{
			board[i][j] = --total_spaces;
		}
	}

	//if the number os spaces even, swap 2 and 1
	if ((d * d) % 2 == 0)
	{
		board[d - 1][d - 3] = 1;
		board[d - 1][d - 2] = 2;
	}
}


/* 
 * Prints the board in its current state.
 */

void
draw(void)
{
    	//to loop through the game numbers
	for (int i = 0; i < d; i ++)
	{
		for (int j = 0; j < d; j ++)
		{
			//to print the space when board == 0
			if (board[i][j] == 0)
			{
				printf("    ");
			}
			//to print the respective board[d][d] numbers
			else
			{
				printf("%4i", board[i][j]);
			}
		}
		printf("\n");
	}
}


/*
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */

bool
move(int tile)
{
    	//verify if the tile command its valid
	if (tile < 1 || tile > d * d)
	{
		printf("Whrong command\n");
		return false;
	}

	int row, column = 0;

	//search in board for row  and column
	for (int i = 0; i < d; i ++)
	{
		for (int j = 0; j < d; j ++)
		{
			if (board[i][j] == tile)
			{
				row = i;
				column = j;
			}
		}
	}

	//chec if in row and column empty spaces
	if (row - 1 >= 0 &&board[row -1][column] == 0)
	{
		board[row -1][column] = board[row][column];
		board[row][column] = 0;
		return true;
	}

	if (column - 1 >= 0 && board[row][column - 1] == 0)
	{
		board[row][column - 1] = board[row][column];
		board[row][column] = 0;
		return true;
	}

	if (row + 1 < d && board[row + 1][column] == 0)
	{
		board[row + 1][column] = board[row][column];
		board[row][column] = 0;
		return true;
	}

	if (column + 1 < d && board[row][column + 1] == 0)
	{
		board[row][column +1] = board[row][column];
		board[row][column] = 0;
		return true;
	}

    	return false;
}


/*
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool
won(void)
{
	int count = 0;

	//search for board values in their correct spaces
	for (int i = 0; i < d; i ++)
	{
		for (int j = 0; j < d; j ++)
		{
			if (++ count != (d * d) && board[i][j] != count)
			{
				return false;
			}
		}
	}
    	return true;
}
