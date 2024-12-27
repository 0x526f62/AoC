// # DAY01 part 1
// includes the standard input/output library
#include <stdio.h>
#define ARENA_IMPLEMENTATION
#include <arena.h>

// Day01 will take a file called Day01Input.txt and display a count of the  number of characters.


// here are some static variables and structs we may like to use

static 
int main( int argc, char const *argv[] ) {
	// sanity check the command arguments
	if ( argc != 2 ) {
		printf( "Usage: Day01 <filename>\n" );
		return 1;
	}
	else {
		// open the input file
		FILE *fp = fopen( argv[1], "r" );
		if ( fp == NULL ) {
			printf( "Failed to open file: %s\n", argv[1] );
			return 1;
		}
		else { 
			// read the file into a buffer
			char buffer[1024];
			int count = 0;
			while ( fgets( buffer, 1024, fp ) != NULL ) {
				count += strlen( buffer );
			}
			printf( "%d\n", count );
		}
	}
	


	
	
	





	return 0;
}
