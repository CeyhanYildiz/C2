#include <stdio.h>

#if 1
void verdeelPriemInGroepen( int *priemGetallen, int aantalGetallen, int **priemGroepen, int aantalGroepen );
void printPriemInGroepen( int **priemGroepen, int aantalGroepen );

int main( int argc, char *argv[] )
{
	int local = 42;
	if( local / 42 < argc )
	{
		printf( "local @ %p\n", &local );
	}
  
	// Argument Count & Argument Vector
	printf( "argc = %d\n", argc );
	for( int i = 0; i < argc; i++ )
	{
		printf( "argv[%i] = %s\n", i, argv[i] );
	}
	getchar();

	printf( "argv[%i] = %s\n", argc, argv[argc] );
	// printf( "sizeof argv = %lu\n", sizeof( argv ) );
	getchar();

	printf( "argc    @%p = %d\n", &argc, argc );
	printf( "argv    @%p\n", &argv );
	for( int i = 0; i < argc; i++ )
	{
		printf( "argv[%i] @%p = @%p -> %s\n", i, &argv[i], argv[i], argv[i] );
	}
	getchar();

	printf( "argv memory\n" );
	for( int i = 0; i < 1024; i++ )
	{
		char c = ( (char *)*argv )[i];
		if( c < 10 )
		{
			c += '0';
		}
		if( c < 16 )
		{
			c += 'A' - 10;
		}
		putchar( c );
	}
	printf( "\n" );
	getchar();

	// NOTE : check getopt of argp for POSIX (GNU) solutions parsing arguments

	// Ragged arrays

	double row0[] = { 6.9, 8.2, 9.3, 8.7, 6.5, 3.7 };
	double row1[] = { 1.1, 1.7, 2.3, 4, 6.6, 6.8 };
	double row2[] = { 6.1, 6.5, 7.2, 8.7, 10.6, 9.9, 8.5, 7 };
	double *data[] = { row0, row1, row2 };
	for( int i = 0; i < 3; i++ )
	{
		printf( "data[%i] @%p -> @%p\n", i, &data[i], data[i] );
	}
	getchar();

	int priemGetallen[] = { 2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191,
	                        193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443,
	                        449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727,
	                        733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009 };
	int *priemGroepen[11];
	verdeelPriemInGroepen( priemGetallen, sizeof( priemGetallen ) / sizeof( int ), priemGroepen, 11 );
	printPriemInGroepen( priemGroepen, 10 );
	getchar();

	return 0;
}

void verdeelPriemInGroepen( int *priemGetallen, int aantalGetallen, int **priemGroepen, int aantalGroepen )
{
	priemGroepen[0] = priemGetallen;
	for( int i = 1; i < aantalGetallen; i++ )
	{
		if( ( priemGetallen[i - 1] / 100 ) < ( priemGetallen[i] / 100 ) )
		{
			priemGroepen[( priemGetallen[i] / 100 )] = &priemGetallen[i];
			if( ( priemGetallen[i] / 100 ) == aantalGroepen )
			{ // We handled the last possible group, so return now
				return;
			}
		}
	}
}

void printPriemInGroepen( int **priemGroepen, int aantalGroepen )
{
	for( int i = 0; i < 25; i++ )
	{
		for( int j = 0; j < aantalGroepen; j++ )
		{
			if( i < (int)( priemGroepen[j + 1] - priemGroepen[j] ) )
			{
				printf( " %3d", priemGroepen[j][i] );
			}
			else
			{
				printf( "    " );
			}
		}
		printf( "\n" );
	}
}

#else // Not for exam, just nice to know !
int main( int argc, char *argv[], char **env_var_ptr )
{
	int i = 0;

	printf( "argc = %d\n", argc );
	for( i = 0; i < argc; i++ )
	{
		printf( "argv[%i] = %s\n", i, argv[i] );
	}
	printf( "\n\n" );
	getchar();

	i = 0;
	while( *env_var_ptr != NULL )
	{
		i++;
		printf( "\nenv var%d=>%s", i, *( env_var_ptr++ ) );
	}
	printf( "\n\n" );
	getchar();

	printf( "memory\n" );
	for( int i = 0; i < 8192 + 4096 + 1024; i++ )
	{
		char c = ( (char *)*argv )[i];
		if( c == 0 )
		{
			printf( "\\0" );
			c = '\n';
		}
		else if( c < 10 )
		{
			c += '0';
		}
		else if( c < 16 )
		{
			c += 'A' - 10;
		}
		putchar( c );
	}
	printf( "\n" );
	getchar();
}
#endif
