// KMZ_Team: Kaval ? (123456789), Moti ? (123456789), Zach ? (123456789)

/*
 ============================================================================
 Name        : tempreversi.c
 Description : TODO
 ============================================================================
 */

/*
 * This is a place to write GENERAL questions, notes,... If they relate to a SPECIFIC location in the code,
 * please place them next to that location rather than here.
 *
 *
 * NOTES
 * -----
 * - We are working with rectangular 8x14 boards: 8 rows and 14 columns.
 *
 * - To avoid confusion, we will use (i, j) to refer to input/output indexes and (row, col) to refer to the indexes
 *   of our "internal" board implementation. Note that only the COLUMN index has to be modified.
 *
 * - The mathematical relationship between the external and internal indexing is [col = j + abs(4 - i)]
 *   and [j = col - abs(4 - row)] (the inverse function).
 *
 * - I have implemented two helper functions to convert both ways between (i, j) and (row, col).
 *
 * - Cell values are -1: unused cell, 0: empty cell, 1: cell containing our disc, 2: cell containing opponent’s disc.
 *
 *
 * QUESTIONS
 * ---------
 * - Do cell indexes (i, j) start from 0 or 1? For now, I am going to assume 1.
 *
 *
 *
 */

// Included libraries
#include <stdio.h>
#include <stdlib.h>

// Constants
// TODO

// Data structures
// TODO

// Function prototypes
signed char toCol(signed char, signed char);
signed char toJ(signed char, signed char);


// Main function
int main(void) {

	/* VARIABLE DECLARATION */

/*
 *	Declare array to hold our move and initialize with zeros
 *	move[0] holds row index ('i' OR 'row') and move[1] holds column index ('j' OR 'col')
 *
 *	Note: The initial value of 0 tells us that the array has not been modified yet.
 *	However, if we find that the (i, j) indexes start from 0, then we will change this
 *	to initialize with -1.
 */
	signed char move[2] = {0, 0};


/*
 *	TODO read 8 lines (various lengths) from stdin, convert column indexes to match internal implementation,
 *	and store them in an instance of our rectangular board.
 */


	// TODO Using loops, scan the board for empty cells that represent a legal move and store them.


	// TODO This is where the logic starts for computing the best move


	// Convert move values to external format
	move[1] = toJ(move[0], move[1]);

	// Print move to stdout if legal
	if (move[0] < 1 || move[0] > 8 || move[1] < 1 || move[1] > 14) {

		printf("Invalid stdout move index!");
		return EXIT_FAILURE;
	} else {

		printf("%d %d\n", move[0], move[1]);
	}

	return EXIT_SUCCESS;
}


/* HELPER FUNCTIONS */

// Convert column index from external to internal implementation
signed char toCol(signed char i, signed char j) {

	return (j + abs(4 - i));
}

// Convert column index from internal to external implementation
signed char toJ(signed char row, signed char col) {

	return (col - abs(4 - row));
}
