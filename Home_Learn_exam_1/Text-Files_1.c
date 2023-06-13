#include <stdio.h>

int main( void )
{
	// Printing to console
	printf( "Hello World\n" );

	// Printing to file
	FILE *filePointer = fopen( "file.txt", "w" ); // Ask Operating System to open a file on the file system to write
	fprintf( filePointer, "Hello World\n" );      // Print content into the given pointer to that open file
	fclose( filePointer );                        // Let de Operating System know we are no longer needing access to the file

	getchar();

	char input[16];
	printf( "Reading from console : " );
	// Reading from console
	(void)fgets( input, sizeof input, stdin );
	printf( "Read = %s", input );

	// Reading from file
	filePointer = fopen( "file.txt", "r" );          // Ask Operating System to open a file on the file system to read
	(void)fgets( input, sizeof input, filePointer ); // Read content from the given pointer to that open file
	fclose( filePointer );                           // Let de Operating System know we are no longer needing access to the file
	printf( "Read = %s", input );

	getchar();

	// More info ? --> RTFM @ https://en.cppreference.com/w/c/io

	return 0;
}