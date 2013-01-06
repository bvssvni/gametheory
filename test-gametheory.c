#if 0
#!/bin/bash
gcc -o test-gametheory test-gametheory.c gametheory.c -Wall -Wfatal-errors -O3
if [ "$?" = "0" ]; then
	time ./test-gametheory
fi
exit
#endif

#include <stdio.h>
#include <assert.h>

#include "gametheory.h"

void test_symmetric_NumberOfPayoffs1()
{
	typedef struct gametheory_symmetric_game game;
	func(gametheory_symmetric, NumberOfPayoffs);
	
	game g = {.players = 2, .choices = 2};
	assert(NumberOfPayoffs(g) == 8);
}

void test_asymmetric_NumberOfPayoffs1()
{
	typedef struct gametheory_asymmetric_game game;
	func(gametheory_asymmetric, NumberOfPayoffs);
	
	game g = {.players = 2};
	assert(NumberOfPayoffs(g, (int[]){2, 2}) == 8);
}

void test_symmetric_PayoffIndex1()
{
	typedef struct gametheory_symmetric_game game;
	func(gametheory_symmetric, PayoffIndex);
	
	game g = {.players = 2, .choices = 2};
	assert(PayoffIndex(g, 0, (int[]){0, 0}) == 0);
	assert(PayoffIndex(g, 0, (int[]){1, 0}) == 1);
	assert(PayoffIndex(g, 0, (int[]){0, 1}) == 2);
	assert(PayoffIndex(g, 0, (int[]){1, 1}) == 3);
	
	assert(PayoffIndex(g, 1, (int[]){0, 0}) == 4);
	assert(PayoffIndex(g, 1, (int[]){1, 0}) == 5);
	assert(PayoffIndex(g, 1, (int[]){0, 1}) == 6);
	assert(PayoffIndex(g, 1, (int[]){1, 1}) == 7);
}

void test_symmetric_PayoffIndex2()
{
	typedef struct gametheory_symmetric_game game;
	func(gametheory_symmetric, PayoffIndex);
	
	game g = {.players = 3, .choices = 2};
	assert(PayoffIndex(g, 0, (int[]){0, 0, 0}) == 0);
	assert(PayoffIndex(g, 0, (int[]){1, 0, 0}) == 1);
	assert(PayoffIndex(g, 0, (int[]){0, 1, 0}) == 2);
	assert(PayoffIndex(g, 0, (int[]){1, 1, 0}) == 3);
	assert(PayoffIndex(g, 0, (int[]){0, 0, 1}) == 4);
	assert(PayoffIndex(g, 0, (int[]){1, 0, 1}) == 5);
	assert(PayoffIndex(g, 0, (int[]){0, 1, 1}) == 6);
	assert(PayoffIndex(g, 0, (int[]){1, 1, 1}) == 7);
		
	assert(PayoffIndex(g, 1, (int[]){0, 0, 0}) == 8);
	assert(PayoffIndex(g, 1, (int[]){1, 0, 0}) == 9);
	assert(PayoffIndex(g, 1, (int[]){0, 1, 0}) == 10);
	assert(PayoffIndex(g, 1, (int[]){1, 1, 0}) == 11);
	assert(PayoffIndex(g, 1, (int[]){0, 0, 1}) == 12);
	assert(PayoffIndex(g, 1, (int[]){1, 0, 1}) == 13);
	assert(PayoffIndex(g, 1, (int[]){0, 1, 1}) == 14);
	assert(PayoffIndex(g, 1, (int[]){1, 1, 1}) == 15);
	
	assert(PayoffIndex(g, 2, (int[]){0, 0, 0}) == 16);
	assert(PayoffIndex(g, 2, (int[]){1, 0, 0}) == 17);
	assert(PayoffIndex(g, 2, (int[]){0, 1, 0}) == 18);
	assert(PayoffIndex(g, 2, (int[]){1, 1, 0}) == 19);
	assert(PayoffIndex(g, 2, (int[]){0, 0, 1}) == 20);
	assert(PayoffIndex(g, 2, (int[]){1, 0, 1}) == 21);
	assert(PayoffIndex(g, 2, (int[]){0, 1, 1}) == 22);
	assert(PayoffIndex(g, 2, (int[]){1, 1, 1}) == 23);
}

void test_asymmetric_PayoffIndex1()
{
	typedef struct gametheory_asymmetric_game game;
	func(gametheory_asymmetric, PayoffIndex);
	
	int choices[] = {2, 2};
	game g = {.players = 2};
	assert(PayoffIndex(g, choices, 0, (int[]){0, 0}) == 0);
	assert(PayoffIndex(g, choices, 0, (int[]){1, 0}) == 1);
	assert(PayoffIndex(g, choices, 0, (int[]){0, 1}) == 2);
	assert(PayoffIndex(g, choices, 0, (int[]){1, 1}) == 3);
	
	assert(PayoffIndex(g, choices, 1, (int[]){0, 0}) == 4);
	assert(PayoffIndex(g, choices, 1, (int[]){1, 0}) == 5);
	assert(PayoffIndex(g, choices, 1, (int[]){0, 1}) == 6);
	assert(PayoffIndex(g, choices, 1, (int[]){1, 1}) == 7);
}

void test_asymmetric_PayoffIndex2()
{
	typedef struct gametheory_asymmetric_game game;
	func(gametheory_asymmetric, PayoffIndex);
	
	int choices[] = {2, 2, 2};
	game g = {.players = 3};
	assert(PayoffIndex(g, choices, 0, (int[]){0, 0, 0}) == 0);
	assert(PayoffIndex(g, choices, 0, (int[]){1, 0, 0}) == 1);
	assert(PayoffIndex(g, choices, 0, (int[]){0, 1, 0}) == 2);
	assert(PayoffIndex(g, choices, 0, (int[]){1, 1, 0}) == 3);
	assert(PayoffIndex(g, choices, 0, (int[]){0, 0, 1}) == 4);
	assert(PayoffIndex(g, choices, 0, (int[]){1, 0, 1}) == 5);
	assert(PayoffIndex(g, choices, 0, (int[]){0, 1, 1}) == 6);
	assert(PayoffIndex(g, choices, 0, (int[]){1, 1, 1}) == 7);
	
	assert(PayoffIndex(g, choices, 1, (int[]){0, 0, 0}) == 8);
	assert(PayoffIndex(g, choices, 1, (int[]){1, 0, 0}) == 9);
	assert(PayoffIndex(g, choices, 1, (int[]){0, 1, 0}) == 10);
	assert(PayoffIndex(g, choices, 1, (int[]){1, 1, 0}) == 11);
	assert(PayoffIndex(g, choices, 1, (int[]){0, 0, 1}) == 12);
	assert(PayoffIndex(g, choices, 1, (int[]){1, 0, 1}) == 13);
	assert(PayoffIndex(g, choices, 1, (int[]){0, 1, 1}) == 14);
	assert(PayoffIndex(g, choices, 1, (int[]){1, 1, 1}) == 15);
	
	assert(PayoffIndex(g, choices, 2, (int[]){0, 0, 0}) == 16);
	assert(PayoffIndex(g, choices, 2, (int[]){1, 0, 0}) == 17);
	assert(PayoffIndex(g, choices, 2, (int[]){0, 1, 0}) == 18);
	assert(PayoffIndex(g, choices, 2, (int[]){1, 1, 0}) == 19);
	assert(PayoffIndex(g, choices, 2, (int[]){0, 0, 1}) == 20);
	assert(PayoffIndex(g, choices, 2, (int[]){1, 0, 1}) == 21);
	assert(PayoffIndex(g, choices, 2, (int[]){0, 1, 1}) == 22);
	assert(PayoffIndex(g, choices, 2, (int[]){1, 1, 1}) == 23);
}

int main(int argc, char *argv[])
{
	test_symmetric_NumberOfPayoffs1();
	test_symmetric_PayoffIndex1();
	test_symmetric_PayoffIndex2();
	
	test_asymmetric_NumberOfPayoffs1();
	test_asymmetric_PayoffIndex1();
	test_asymmetric_PayoffIndex2();
	printf("Unit tests completed\r\n");
	
	return 0;
}
