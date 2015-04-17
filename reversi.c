// KMZ: Kaval Patel (111783892), Moti Gulman (112188733), Zach Portnoff (123456789)

/*
 ============================================================================
 Name        : reversi.c
 Description : CMSC474 + TODO
 ============================================================================
 */

/*
 * This is a place to write GENERAL questions, notes,... If they relate to a SPECIFIC location in the code,
 * please place them next to that location rather than here.
 *
 *
 * NOTES
 * -----
 *
 * - I paid and setup this repository as private so that we don't have to worry about the code being found on the web.
 *   I've already imported the repository.
 *
 * - Please check out the first line in this file. Verify your name and update your UID.
 *
 * - Things to do before submitting: Add a description, and remove all comments used to collaborate.
 *
 * - We are working with rectangular 8x14 boards: 8 rows and 14 columns.
 *
 * - To avoid confusion, we will use (i, j) to refer to input/output indexes and (row, col) to refer to the indexes
 *   of our "internal" board implementation. Note that only the COLUMN index has to be modified.
 *
 * - Input indexes start from 1 (i range is 1-8 and j range is 1-14)
 *
 * - Internal indexes start from 0 (row range is 0-7 and col range is 0-13)
 *
 * - I have implemented two helper functions to convert both ways between (i, j) and (row, col).
 *
 * - Cell values are -1: unused cell, 0: empty cell, 1: cell containing our disc, 2: cell containing opponent’s disc.
 *
 *
 * QUESTIONS
 * ---------
 * -
 *
 *
 *
 */

// Included libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
// TODO

// Data structures

typedef struct {

	signed char isTop;
	signed char isBottom;
	// signed char isLeft; // In case we'll need it
	// signed char isRight; // In case we'll need it
	signed char isEmpty;
	signed char isMy;
	signed char isOp;
	signed char coord[2];

} Cell;

typedef struct {

    Cell cells[88];
    signed int numMy;
    signed int numOp;
    signed int numEm;

} Board;

// Keeping this in case we'll need it
/* struct to hold disc locations (both ours and opponent's)
typedef struct {
    signed char row;
    signed char col;
} Idx;*/

// Function prototypes
// TODO?


// Main function
int main(void) {



	/* VARIABLE DECLARATION & INITIALIZATION */


	/*
	 *	Declare array to hold our move and initialize with zeros
	 *	move[0] holds row index and move[1] holds column index
	 *
	 *	Note: Since 0 is not a valid index, we can use these initial 0 values to indicate/check that
	 *	      the array has not been modified yet.
	 */
	signed char move[2] = {0, 0};

	// Declare input board
	Board b;

	// Zero out all cells in board (7 bytes). CHANGE IF CHANGING struct Cell.
	memset(&b.cells, 0, 7 * 88 * sizeof(signed char));

	// Zero out board parameters
	b.numMy = 0;
	b.numOp = 0;
	b.numEm = 0;


	/* Declare loop variables */

	// Row and Column indexes
	int r, c;

	// Array to hold row dimensions
	int rowDim[] = {8, 10, 12, 14, 14, 12, 10, 8};

	// Number of rows to be read
	int numRows = 8;

	// Temporarily holds values read from stdin
	int getDisc = 0;

	// Holds total values read so far
	int numRead = 0;


	/* PART 1 - READING THE INPUT BOARD FROM STDIN */

	//Read 8 lines (various lengths) from stdin, and update input Board and Cell parameters.
	for (r = 1; r <= numRows; r++) {

		for (c = 1; c <= rowDim[r - 1]; c++) {

			// Read cell disc value
			scanf("%d", &getDisc);

			// Set coords
			b.cells[numRead].coord[0] = r;
			b.cells[numRead].coord[1] = c;

			// Update cell parameters and increment totals in input Board
			if (getDisc == 0) {

				b.cells[numRead].isEmpty = 1;
				b.numEm++;
			} else if (getDisc == 1) {

				b.cells[numRead].isMy = 1;
				b.numMy++;
			} else if (getDisc == 2) {

				b.cells[numRead].isOp = 1;
				b.numOp++;
			} else {

				printf("Invalid disc value read from stdin!");
				return -1;
			}

			// Check if Top/Bottom and update cells' parameters
			if (r == 1)
				b.cells[numRead].isTop = 1;
			else if (r == 8)
				b.cells[numRead].isBottom = 1;

			// increment total number of cell values read (should be 88 in the end)
			numRead++;
		}
	}


	// TODO Determine empty cells that represent a legal move and store them.


	// At this point we are done with the requirements for the five submit server tests.


	// TODO This is where the logic starts for computing the best move


	// Print move to stdout if legal
	if (move[0] < 1 || move[0] > 8 || move[1] < 1 || move[1] > 14) {

		printf("Attempted to send invalid move index to stdout!");
		// Return value 0 indicates FAILURE
		return -1;
	} else {

		printf("%d %d\n", move[0], move[1]);
	}

	// Return value 0 indicates SUCCESS
	return 0;
}


/* HELPER FUNCTIONS */


