#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int globaal1, globaal2, globaal3, globaal4;
char *vasteStringGlobaal = "Hello global!!!";

void functie( void )
{
	getchar();
}

void functie2( void );

int main( void )
{
#if 0
	// What is this of Netwerken ?
	struct sockaddr *internet_address;
	internet_address = (struct sockaddr *) malloc( internet_address_result->ai_addrlen );
	memcpy( internet_address, internet_address_result->ai_addr, internet_address_result->ai_addrlen );
	//...
	free( internet_address );
#endif

#if 0
	// Memory location
	int lokaal1, lokaal2, lokaal3, lokaal4;
	int lijst[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	char *vasteString = "Hello local !!!";
	static int statisch1, statisch2, statisch3, statisch4;

	printf( "---- INSTRUCTIONS ----\n" );
	printf( "  void functie( void )  @ %16p\n", &functie );
	
	printf( "  \"Hello local !!!\"     @ %16p\n", vasteString );printf( "  int main( void )      @ %16p\n", &main );
	printf( "  void functie2( void ) @ %16p\n", &functie2 );
	printf( "---- LITERALS ----\n" );
	printf( "  \"Hello global!!!\"     @ %16p\n", vasteStringGlobaal );
	printf( "---- STATIC DATA ----\n" );
	printf( "  static int statisch1  @ %16p\n", &statisch1 );
	printf( "  static int statisch2  @ %16p\n", &statisch2 );
	printf( "  static int statisch3  @ %16p\n", &statisch3 );
	printf( "  static int statisch4  @ %16p\n", &statisch4 );
	printf( "---- GLOBAL DATA ----\n" );
	printf( "  int globaal1          @ %16p\n", &globaal1 );
	printf( "  int globaal2          @ %16p\n", &globaal2 );
	printf( "  int globaal3          @ %16p\n", &globaal3 );
	printf( "  int globaal4          @ %16p\n", &globaal4 );
	printf( "---- HEAP ----\n" );
	printf( "  Magic happens here !  @ %16p\n", malloc( 1 ) );
	printf( "            and here    @ %16p\n", malloc( 1 ) );
	printf( "  and here              @ %16p\n", malloc( 1 ) );
	printf( "    aaaand...  here !   @ %16p\n", malloc( 1 ) );
	printf( "---- STACK ----\n" );
	printf( "  int lokaal4           @ %16p\n", &lokaal4 );
	printf( "  int lokaal3           @ %16p\n", &lokaal3 );
	printf( "  int lokaal2           @ %16p\n", &lokaal2 );
	printf( "  int lokaal1           @ %16p\n", &lokaal1 );
	printf( "  int lijst[]           @ %16p\n", lijst );
	getchar();

	// Pointers to void
	void *purePointer = NULL;
	purePointer = &lokaal1;
	printf( "void * purePointer      @ %16p\n", purePointer );
	getchar();
	purePointer = lijst;
	printf( "void * purePointer      @ %16p\n", purePointer );
	getchar();
	purePointer = vasteStringGlobaal;
	printf( "void * purePointer      @ %16p\n", purePointer );
	getchar();

	// Memory Allocation
	void *purePointer1b = malloc( 1 ); //#include <stdlib.h>
	printf( "void * purePointer1b    @ %16p\n", purePointer1b );
	getchar();
	void *purePointer1k = malloc( 1024UL );
	printf( "void * purePointer1k    @ %16p\n", purePointer1k );
	getchar();
	void *purePointer1M = malloc( 1024UL * 1024UL );
	printf( "void * purePointer1M    @ %16p\n", purePointer1M );
	getchar();
	void *purePointer1G = malloc( 1024UL * 1024UL * 1024UL );
	printf( "void * purePointer1G    @ %16p\n", purePointer1G );
	getchar();
	void *purePointer32G = malloc( 1024UL * 1024UL * 1024UL * 32UL );
	printf( "void * purePointer32G   @ %16p\n", purePointer32G );
	getchar();
	void *purePointer64G = malloc( 1024UL * 1024UL * 1024UL * 64UL );
	printf( "void * purePointer64G   @ %16p\n", purePointer64G );
	getchar();

	purePointer = malloc( 1024UL * 1024UL * 1024UL * 32UL );
	printf( "void * purePointer      @ %16p\n", purePointer );
	getchar();

	// Memory Leak
	void *memoryLeak = NULL;
	do
	{
		memoryLeak = malloc( 1024UL * 1024UL * 1024UL * 32UL );
		printf( "void * memoryLeak       @ %16p\n", memoryLeak );
	} while( memoryLeak != NULL );
	getchar();

	purePointer = malloc( 1024UL * 1024UL * 1024UL * 32UL );
	printf( "void * purePointer      @ %16p\n", purePointer );
	getchar();
	purePointer = malloc( 1024UL * 1024UL * 1024UL );
	printf( "void * purePointer      @ %16p\n", purePointer );
	getchar();

	do
	{
		memoryLeak = malloc( 1024UL * 1024UL * 1024UL );
		printf( "void * memoryLeak       @ %16p\n", memoryLeak );
	} while( memoryLeak != NULL );
	getchar();

	// Memory Management ==> free allocated memory
	free( purePointer );
	purePointer = malloc( 1024UL * 1024UL * 1024UL );
	printf( "void * purePointer      @ %16p\n", purePointer );
	getchar();
	free( purePointer );
	purePointer = malloc( 1024UL * 1024UL * 1024UL );
	printf( "void * purePointer      @ %16p\n", purePointer );
	getchar();

	printf( "void * purePointer1b    @ %16p\n", purePointer1b );
	printf( "void * purePointer1k    @ %16p\n", purePointer1k );
	printf( "void * purePointer1M    @ %16p\n", purePointer1M );
	printf( "void * purePointer1G    @ %16p\n", purePointer1G );
	printf( "void * purePointer32G   @ %16p\n", purePointer32G );
	printf( "void * purePointer64G   @ %16p\n", purePointer64G );
	getchar();

	free( purePointer32G );
	free( purePointer );
	purePointer = malloc( 1024UL * 1024UL * 1024UL );
	printf( "void * purePointer      @ %16p\n", purePointer );
	getchar();
	free( purePointer );
	purePointer = malloc( 1024UL * 1024UL * 1024UL );
	printf( "void * purePointer      @ %16p\n", purePointer );
	getchar();

	purePointer32G = malloc( 1024UL * 1024UL * 1024UL * 32UL );
	printf( "void * purePointer32G   @ %16p\n", purePointer32G );
	getchar();

	free( purePointer );
	do
	{
		memoryLeak = malloc( 1024UL * 1024UL * 1024UL );
		printf( "void * memoryLeak       @ %16p\n", memoryLeak );
	} while( memoryLeak != NULL );
	getchar();

	do
	{
		memoryLeak = malloc( 1024UL * 1024UL );
		printf( "void * memoryLeak       @ %16p\n", memoryLeak );
	} while( memoryLeak != NULL );
	getchar();

	purePointer = malloc( 1024UL );
	do
	{
		memoryLeak = malloc( 1024UL );
		printf( "void * memoryLeak       @ %16p\n", memoryLeak );
	} while( memoryLeak != NULL );
	getchar();

	// Zombie Memory == Reference to freed memory
	printf( "void * purePointer      @ %16p\n", purePointer );
	memcpy( purePointer,
	        "Om te testen willen we wat gegevens bewaren in dit geheugen om te tonen dat free() niet echt leeg maakt, maar gewoon vrijgeeft en de gegevens blijven bestaan. Zo ontstaat er dus zombie geheugen, omdat er restanten van het oude geheugen "
	        "zichtbaar zijn en voornamelijk wanneer dat nu evengoed gebruikt gaat worden hebben we een probleem met het rekenen op zombies. En niet het leuke Michael Jakson type zombies die leuk dansen, maar van die zombies die je uren nacht kosten om "
	        "uit te zoeken.",
	        490 ); //#include <string.h>
	printf( "*purePointer == %s\n", purePointer );
	free( purePointer );
	printf( "*purePointer == \n" );
	for( int i = 0; i < 490; i++ )
	{
		char c = ( (char *)purePointer )[i];
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
	getchar();
	purePointer = malloc( 1024UL );
	printf( "void * purePointer      @ %16p\n", purePointer );
	printf( "*purePointer == \n" );
	for( int i = 0; i < 490; i++ )
	{
		char c = ( (char *)purePointer )[i];
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
	getchar();

	memcpy( purePointer1G, "Hello World !", 14 );
	printf( "void * purePointer1G    @ %16p\n", purePointer1G );
	printf( "*purePointer1G == %s\n", purePointer1G );
	free( purePointer1G );
	getchar();

	printf( "void * purePointer1G    @ %16p\n", purePointer1G );
	printf( "*purePointer1G == %s\n", purePointer1G );
	getchar();

#else
	printf( "****    ****   *    *   ****  *****\n*   *  *    *  *    *  *      *\n****   ******  *    *   ***   ***\n*      *    *  *    *      *  *\n*      *    *   ****   ****   *****\n" );
	/****    ****   *    *   ****  *****\
	 *   *  *    *  *    *  *      *
	 ****   ******  *    *   ***   ***
	 *      *    *  *    *      *  *
	\*      *    *   ****   ****   *****/
	getchar();

	int aantal = 0;
	void *min = NULL, *max = NULL, *memory[5000] = { NULL };

	min = malloc( 1 );
	max = min;
	printf( "Eating 32G" );
	do
	{
		memory[aantal] = malloc( 1024UL * 1024UL * 1024UL * 32UL );
		min = min < memory[aantal] ? min : memory[aantal] != NULL ? memory[aantal] : min;
		max = max > memory[aantal] ? max : memory[aantal];
		putchar( '.' );
	} while( memory[aantal++] != NULL );
	printf( "%d x 32G = %d TB\n", aantal, aantal * 32 / 1024 );
	for( int i = 0; i < aantal && memory[i]; i++ )
	{
		free( memory[i] );
	}

	// Memory location
	int lokaal1, lokaal2, lokaal3, lokaal4;
	int lijst[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	char *vasteString = "Hello local !!!";
	static int statisch1, statisch2, statisch3, statisch4;

	printf( "---- INSTRUCTIONS ----\n" );
	printf( "  void functie( void )  @ %16p\n", &functie );
	printf( "  int main( void )      @ %16p\n", &main );
	printf( "  void functie2( void ) @ %16p\n", &functie2 );
	printf( "---- LITERALS ----\n" );
	printf( "  \"Hello global!!!\"     @ %16p\n", vasteStringGlobaal );
	printf( "  \"Hello local !!!\"     @ %16p\n", vasteString );
	printf( "---- STATIC DATA ----\n" );
	printf( "  static int statisch1  @ %16p\n", &statisch1 );
	printf( "  static int statisch2  @ %16p\n", &statisch2 );
	printf( "  static int statisch3  @ %16p\n", &statisch3 );
	printf( "  static int statisch4  @ %16p\n", &statisch4 );
	printf( "---- GLOBAL DATA ----\n" );
	printf( "  int globaal1          @ %16p\n", &globaal1 );
	printf( "  int globaal2          @ %16p\n", &globaal2 );
	printf( "  int globaal3          @ %16p\n", &globaal3 );
	printf( "  int globaal4          @ %16p\n", &globaal4 );
	printf( "---- HEAP ----\n" );
	printf( "  Magic happens from    @ %16p\n", min );
	printf( "                   till @ %16p\n", max );
	printf( "---- STACK ----\n" );
	printf( "  int lokaal4           @ %16p\n", &lokaal4 );
	printf( "  int lokaal3           @ %16p\n", &lokaal3 );
	printf( "  int lokaal2           @ %16p\n", &lokaal2 );
	printf( "  int lokaal1           @ %16p\n", &lokaal1 );
	printf( "  int lijst[]           @ %16p\n", lijst );
	getchar();

	// Type casting pointers
	int *getal = (int *)malloc( sizeof( int ) );
	printf( "*getal value = %d ; sizeof = %lu ; address = %p -> %p\n", *getal, sizeof( getal ), &getal, getal );
	*getal = 42;
	printf( "*getal value = %d ; sizeof = %lu ; address = %p -> %p\n", *getal, sizeof( getal ), &getal, getal );
	getchar();

	float *komma = (float *)malloc( sizeof( float ) );
	printf( "*komma value = %f ; sizeof = %lu ; address = %p -> %p\n", *komma, sizeof( komma ), &komma, komma );
	*komma = 42.069f;
	printf( "*komma value = %f ; sizeof = %lu ; address = %p -> %p\n", *komma, sizeof( komma ), &komma, komma );
	getchar();

	int *array = (int *)malloc( sizeof( int ) * 10 );
	printf( "*array ; sizeof = %lu ; address = %p -> %p\n", sizeof( array ), &array, array );
	for( int i = 0; i < 10; i++ )
	{
		printf( "array[%d] value = %2d ; sizeof = %lu ; address = %p\n", i, array[i], sizeof( array[i] ), &array[i] );
	}
	for( int i = 0; i < 10; i++ )
	{
		array[i] = i + 1;
	}
	printf( "*array ; sizeof = %lu ; address = %p -> %p\n", sizeof( array ), &array, array );
	for( int i = 0; i < 10; i++ )
	{
		printf( "array[%d] value = %2d ; sizeof = %lu ; address = %p\n", i, array[i], sizeof( array[i] ), &array[i] );
	}
	getchar();

	struct naam
	{
		int getal;
		char letter;
		double komma;
		int *pointer;
	};
	struct naam *object = (struct naam *)malloc( sizeof( struct naam ) );
	printf( "object value = { %d, '%c', %.3f, %p (= %d) } ; sizeof = %lu ; address = %p -> %p\n", object->getal, object->letter, object->komma, object->pointer, *( object->pointer ), sizeof( object ), &object, object );
	object->getal = 42;
	object->letter = 'B';
	object->komma = 42.069;
	object->pointer = (int *)malloc( sizeof( int ) );
	*object->pointer = 69;
	printf( "object value = { %d, '%c', %.3f, %p (= %d) } ; sizeof = %lu ; address = %p -> %p\n", object->getal, object->letter, object->komma, object->pointer, *( object->pointer ), sizeof( object ), &object, object );
	getchar();

	free( object->pointer );
	free( object );
	free( array );
	free( komma );
	free( getal );
	getchar();

	// calloc
	getal = (int *)calloc( 1, sizeof( int ) );
	printf( "*getal value = %d ; sizeof = %lu ; address = %p -> %p\n", *getal, sizeof( getal ), &getal, getal );
	*getal = 42;
	printf( "*getal value = %d ; sizeof = %lu ; address = %p -> %p\n", *getal, sizeof( getal ), &getal, getal );
	getchar();

	komma = (float *)calloc( 1, sizeof( float ) );
	printf( "*komma value = %f ; sizeof = %lu ; address = %p -> %p\n", *komma, sizeof( komma ), &komma, komma );
	*komma = 42.069f;
	printf( "*komma value = %f ; sizeof = %lu ; address = %p -> %p\n", *komma, sizeof( komma ), &komma, komma );
	getchar();

	array = (int *)calloc( 10, sizeof( int ) );
	printf( "*array ; sizeof = %lu ; address = %p -> %p\n", sizeof( array ), &array, array );
	for( int i = 0; i < 10; i++ )
	{
		printf( "array[%d] value = %2d ; sizeof = %lu ; address = %p\n", i, array[i], sizeof( array[i] ), &array[i] );
	}
	for( int i = 0; i < 10; i++ )
	{
		array[i] = i + 1;
	}
	printf( "*array ; sizeof = %lu ; address = %p -> %p\n", sizeof( array ), &array, array );
	for( int i = 0; i < 10; i++ )
	{
		printf( "array[%d] value = %2d ; sizeof = %lu ; address = %p\n", i, array[i], sizeof( array[i] ), &array[i] );
	}
	getchar();

	object = (struct naam *)calloc( 1, sizeof( struct naam ) );
	printf( "object value = { %d, '%c', %.3f, %p (= %d) } ; sizeof = %lu ; address = %p -> %p\n", object->getal, object->letter, object->komma, object->pointer, *( object->pointer ), sizeof( object ), &object, object );
	object->getal = 42;
	object->letter = 'B';
	object->komma = 42.069;
	object->pointer = (int *)calloc( 1, sizeof( int ) );
	*object->pointer = 69;
	printf( "object value = { %d, '%c', %.3f, %p (= %d) } ; sizeof = %lu ; address = %p -> %p\n", object->getal, object->letter, object->komma, object->pointer, *( object->pointer ), sizeof( object ), &object, object );
	getchar();

	free( object->pointer );
	free( object );
	free( array );
	free( komma );
	free( getal );
	getchar();

#endif
	return 0;
}

void functie2( void )
{
	getchar();
}
