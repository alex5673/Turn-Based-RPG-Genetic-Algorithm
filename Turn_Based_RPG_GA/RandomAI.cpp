
#include "stdafx.h"

#include <time.h>
#include <fstream>
#include <iostream>

#include "RandomAI.h"

RandomAI::RandomAI(Enemy e, Player p) {
	enemy = e;
	player = p;
}

int RandomAI::Run() {
	player.SetHP(3000);
	int numOfTurns = 0;
	// while player is alive randomly pick moves from the move set
	while (player.GetHP() > 0) {
		srand(time(0));
		int randomIndex = rand() % enemy.GetMoves().size();
		enemy.AttackPlayer(enemy.GetMoves()[randomIndex], player);
		numOfTurns++;
	}
	return numOfTurns;
}