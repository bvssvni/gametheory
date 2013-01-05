
#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "gametheory.h"

int gametheory_NumberOfRewards(const gametheory_game g)
{
	return g.players * (int)pow(g.choices, g.players);
}

int gametheory_RewardIndex
(const gametheory_game g, int player, int playerChoices[])
{
	assert(player >= 0);
	assert(player < g.players);
	
	int index = 0;
	int i;
	int stride = 1;
	for (i = 0; i < g.players; i++) {
		assert(playerChoices[i] >= 0);
		assert(playerChoices[i] < g.choices);
		
		index += stride * playerChoices[i];
		stride *= g.choices;
	}
	return index + stride * player;
}

