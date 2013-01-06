
#include <math.h>
#include <stdio.h>
#include <assert.h>

#include "gametheory.h"

int gametheory_symmetric_NumberOfPayoffs(const gametheory_symmetric_game g)
{
	return g.players * (int)pow(g.choices, g.players);
}

int gametheory_asymmetric_NumberOfPayoffs
(const gametheory_asymmetric_game g, const int choices[])
{
	assert(g.players >= 0);
	assert(choices != NULL);
	
	int res = g.players;
	int i;
	for (i = 0; i < g.players; i++) {
		res *= choices[i];
	}
	return res;
}

int gametheory_symmetric_PayoffIndex
(const gametheory_symmetric_game g, int player, int playerChoices[])
{
	assert(player >= 0);
	assert(player < g.players);
	assert(playerChoices != NULL);
	
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

int gametheory_asymmetric_PayoffIndex
(const gametheory_asymmetric_game g, int choices[],
 int player, int playerChoices[])
{
	assert(player >= 0);
	assert(choices != NULL);
	assert(player < g.players);
	assert(playerChoices != NULL);
	
	int index = 0;
	int i;
	int stride = 1;
	for (i = 0; i < g.players; i++) {
		assert(playerChoices[i] >= 0);
		assert(playerChoices[i] < choices[i]);
		
		index += stride * playerChoices[i];
		stride *= choices[i];
	}
	return index + stride * player;
}

