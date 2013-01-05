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

func(gametheory, NumberOfRewards);
func(gametheory, RewardIndex);

typedef struct gametheory_game game;

void test_NumberOfRewards1()
{
	game g = {.players = 2, .choices = 2};
	assert(NumberOfRewards(g) == 8);
}

void test_RewardIndex1()
{
	game g = {.players = 2, .choices = 2};
	assert(RewardIndex(g, 0, (int[]){0, 0}) == 0);
	assert(RewardIndex(g, 0, (int[]){1, 0}) == 1);
	assert(RewardIndex(g, 0, (int[]){0, 1}) == 2);
	assert(RewardIndex(g, 0, (int[]){1, 1}) == 3);
	
	assert(RewardIndex(g, 1, (int[]){0, 0}) == 4);
	assert(RewardIndex(g, 1, (int[]){1, 0}) == 5);
	assert(RewardIndex(g, 1, (int[]){0, 1}) == 6);
	assert(RewardIndex(g, 1, (int[]){1, 1}) == 7);
}

void test_RewardIndex2()
{
	game g = {.players = 3, .choices = 2};
	assert(RewardIndex(g, 0, (int[]){0, 0, 0}) == 0);
	assert(RewardIndex(g, 0, (int[]){1, 0, 0}) == 1);
	assert(RewardIndex(g, 0, (int[]){0, 1, 0}) == 2);
	assert(RewardIndex(g, 0, (int[]){1, 1, 0}) == 3);
	assert(RewardIndex(g, 0, (int[]){0, 0, 1}) == 4);
	assert(RewardIndex(g, 0, (int[]){1, 0, 1}) == 5);
	assert(RewardIndex(g, 0, (int[]){0, 1, 1}) == 6);
	assert(RewardIndex(g, 0, (int[]){1, 1, 1}) == 7);
		
	assert(RewardIndex(g, 1, (int[]){0, 0, 0}) == 8);
	assert(RewardIndex(g, 1, (int[]){1, 0, 0}) == 9);
	assert(RewardIndex(g, 1, (int[]){0, 1, 0}) == 10);
	assert(RewardIndex(g, 1, (int[]){1, 1, 0}) == 11);
	assert(RewardIndex(g, 1, (int[]){0, 0, 1}) == 12);
	assert(RewardIndex(g, 1, (int[]){1, 0, 1}) == 13);
	assert(RewardIndex(g, 1, (int[]){0, 1, 1}) == 14);
	assert(RewardIndex(g, 1, (int[]){1, 1, 1}) == 15);
	
	assert(RewardIndex(g, 2, (int[]){0, 0, 0}) == 16);
	assert(RewardIndex(g, 2, (int[]){1, 0, 0}) == 17);
	assert(RewardIndex(g, 2, (int[]){0, 1, 0}) == 18);
	assert(RewardIndex(g, 2, (int[]){1, 1, 0}) == 19);
	assert(RewardIndex(g, 2, (int[]){0, 0, 1}) == 20);
	assert(RewardIndex(g, 2, (int[]){1, 0, 1}) == 21);
	assert(RewardIndex(g, 2, (int[]){0, 1, 1}) == 22);
	assert(RewardIndex(g, 2, (int[]){1, 1, 1}) == 23);
}

int main(int argc, char *argv[])
{
	test_NumberOfRewards1();
	test_RewardIndex1();
	test_RewardIndex2();
	printf("Unit tests completed\r\n");
	
	return 0;
}
