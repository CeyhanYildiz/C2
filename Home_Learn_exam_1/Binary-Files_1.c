#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
	// Printing to console
	printf( "Hello World\n" );

	// initialize random seed
	srand( time( NULL ) );

	// Generate 100 random numbers and print to text file
	FILE *filePointer = fopen( "file.txt", "w" );                                                    // Ask Operating System to open a file on the file system to write
	int numbers[100];
	for( unsigned int i = 0; i < sizeof( numbers ) / sizeof( numbers[0] ); i++ )
	{
		numbers[i] = rand() % 100000000 + 1;
		printf( "%8d ", numbers[i] );
		fprintf( filePointer, "%d ", numbers[i] );                                                    // Print content into the given pointer to that open file
	}
	printf( "\n" );
	fclose( filePointer );                                                                          // Let de Operating System know we are no longer needing access to the file



	// Write to binary file
	filePointer = fopen( "file.bin", "wb" );                                                        // Ask Operating System to open a file on the file system to write
	fwrite( numbers, sizeof( numbers[0] ), sizeof( numbers ) / sizeof( numbers[0] ), filePointer ); // Print content into the given pointer to that open file
	fclose( filePointer );                                                                          // Let de Operating System know we are no longer needing access to the file

	getchar();

	// Read from binary file
	int input[100];
	filePointer = fopen( "file.bin", "rb" );                                                         // Ask Operating System to open a file on the file system to read
	(void)fread( &input[0], sizeof( input[0] ), sizeof( input ) / sizeof( input[0] ), filePointer ); // Read content from the given pointer to that open file
	fclose( filePointer );                                                                           // Let de Operating System know we are no longer needing access to the file
	for( unsigned int i = 0; i < sizeof( input ) / sizeof( input[0] ); i++ )
	{
		printf( "%8d ", input[i] );
	}

	getchar();

	// More info ? --> RTFM @ https://en.cppreference.com/w/c/io

	return 0;
}
