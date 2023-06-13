#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

int d4( void )
{
	printf( "Rolling d4\n" );
	return ( ( rand() % 4 ) + 1 );
}

int d6( void )
{
	printf( "Rolling d6\n" );
	return ( ( rand() % 6 ) + 1 );
}

int d8( void )
{
	printf( "Rolling d8\n" );
	return ( ( rand() % 8 ) + 1 );
}

int d10( void )
{
	printf( "Rolling d10\n" );
	return ( ( rand() % 10 ) + 1 );
}

int d12( void )
{
	printf( "Rolling d12\n" );
	return ( ( rand() % 12 ) + 1 );
}

int d20( void )
{
	printf( "Rolling d20\n" );
	return ( ( rand() % 20 ) + 1 );
}

int main()
{
	srand( time( NULL ) );

	// Regular function call
	printf( "\t%d\n", d4() );
	printf( "\t%d\n", d6() );
	printf( "\t%d\n", d8() );
	printf( "\t%d\n", d10() );
	printf( "\t%d\n", d12() );
	printf( "\t%d\n", d20() );
	getchar();

	// Von Neumann architecture --> stored-program computer
	printf( "d4 @ %p\n", &d4 );
	printf( "d6 @ %p\n", &d6 );
	printf( "d8 @ %p\n", &d8 );
	printf( "d10 @ %p\n", &d10 );
	printf( "d12 @ %p\n", &d12 );
	printf( "d20 @ %p\n", &d20 );
	getchar();

	// Can we store and use that as a pointer ?
#ifdef CANNOT_DO_THIS
	void *pointer = &d20;
	pointer();
#endif
	// Normal variables to pointers
	int getal = 42;
	int *pointer_naar_getal = &getal;

	// Function to pointers
	int functie( void );
	int ( *pointer_naar_functie )( void ) = &functie;
	int *pointer_van_functie( void );

	printf( "%p : getal = %d\n", &getal, getal );
	printf( "%p : *pointer_naar_getal = %d\n", pointer_naar_getal, *pointer_naar_getal );
	printf( "%p : functie() = %d\n", &functie, functie() );
	printf( "%p : pointer_naar_functie() = %d\n", pointer_naar_functie, pointer_naar_functie() );
	getchar();

	// Typecast naar function pointer
	void *pointer = (void *)&d20;
	( (int ( * )( void ))pointer )();
	getchar();

	// Assignment van function pointer
	int ( *die )( void ) = &d4;
	die();
	die = &d6;
	die();
	die = &d8;
	die();
	die = &d10;
	die();
	die = &d12;
	die();
	die = &d20;
	die();
	getchar();

	// Function pointer as function argument
	int advantageRoll( int ( *dice )( void ) );
	printf( "\t%d\n", advantageRoll( &d4 ) );
	printf( "\t%d\n", advantageRoll( &d6 ) );
	printf( "\t%d\n", advantageRoll( &d8 ) );
	printf( "\t%d\n", advantageRoll( &d10 ) );
	printf( "\t%d\n", advantageRoll( &d12 ) );
	printf( "\t%d\n", advantageRoll( &d20 ) );
	getchar();

	// Function pointer array
	int ( *dice[] )( void ) = { &d4, &d6, &d8, &d10, &d12, &d20 };
	for( int i = 0; i < 42; i++ )
	{
		int random = rand() % 6;
		printf( "\t%d\n", dice[random]() );
	}
	getchar();

	// Function returning functions --> https://stackoverflow.com/questions/34548762/c-isnt-that-hard-void-f
	int ( *( getRandomDie( void ) ) )( void );
	for( int i = 0; i < 42; i++ )
	{
		printf( "\t%d\n", getRandomDie()() );
	}
	getchar();

	// Typedef
	typedef unsigned char byte;
	byte b1 = 42;
	printf( "byte b1 = %hhu, sizeof = %lu\n", b1, sizeof( b1 ) );

	typedef int *pint;
	pint p1 = &getal;
	printf( "pint p1 = %d, sizeof = %lu\n", *p1, sizeof( p1 ) );

	typedef int ( *func )( void );
	func f1 = &d20;
	printf( "func f1() = %d, sizeof = %lu\n", f1(), sizeof( f1 ) );

	func getRandomDie( void );
	for( int i = 0; i < 42; i++ )
	{
		printf( "\t%d\n", getRandomDie()() );
	}
	getchar();

	/********************************    keyHandlerDemo    ********************************/
	void keyHandlerDemo( void );
	keyHandlerDemo();
	return 0;
}

int functie( void )
{
	return 42;
}

int advantageRoll( int ( *dice )( void ) )
{
	int roll1 = dice();
	int roll2 = dice();
	printf( "Drop %d\n", ( roll1 < roll2 ) ? roll1 : roll2 );
	return ( roll1 > roll2 ) ? roll1 : roll2;
}

int ( *( getRandomDie( void ) ) )( void )
{
	static int ( *dice[] )( void ) = { &d4, &d6, &d8, &d10, &d12, &d20 };
	return dice[rand() % 6];
}

/********************************    keyHandlerDemo    ********************************/

// Replit overhead for direct input
void enable_raw_mode( struct termios *orig_termios )
{
	struct termios raw;
	tcgetattr( STDIN_FILENO, orig_termios );
	raw = *orig_termios;
	raw.c_lflag &= ~( ECHO | ICANON );
	tcsetattr( STDIN_FILENO, TCSAFLUSH, &raw );
}
// Replit overhead for direct input
void disable_raw_mode( struct termios *orig_termios )
{
	tcsetattr( STDIN_FILENO, TCSAFLUSH, orig_termios );
}

typedef void ( *handler )( void );

void nothing( void )
{
}

void key_b( void )
{
	printf( "MAGIC !!!\n" );
}

void key_v( void )
{
	printf( "Go go go !!!\n" );
}

void keyHandlerDemo( void )
{
	struct termios orig_termios;      // Replit overhead for direct input
	enable_raw_mode( &orig_termios ); // Replit overhead for direct input

	handler keyHandlers[256];
	for( int i = 0; i < 256; i++ )
	{
		keyHandlers[i] = nothing;
	}

	keyHandlers['b'] = key_b;
	keyHandlers['v'] = key_v;

	printf( "Press 'q' to exit...\n" );
	char c;
	while( read( STDIN_FILENO, &c, 1 ) == 1 && c != 'q' )
	{
		 printf( "You pressed: %c\n", c );
		keyHandlers[(int)c]();
	}

	disable_raw_mode( &orig_termios ); // Replit overhead for direct input
}
