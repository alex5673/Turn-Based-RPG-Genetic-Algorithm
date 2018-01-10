
#include "stdafx.h"

#include <fstream>
#include <iostream>

#include "HandMadeAI.h"

HandMadeAI::HandMadeAI(Enemy e, Player p) {
	enemy = e;
	player = p;
}

int HandMadeAI::Run() {
	player.SetHP(3000);
	int numOfTurns = 0;
	// while player is alive AI will pick the fire attack if it has enough mp because in the test scenario the player is weakest against fire
	// and when the AI runs out of mp, the AI will pick attack 3 because that has the most power - so this AI should pick the strongest moves
	// therefore defeating the player the quickest
	while (player.GetHP() > 0) {
		if (enemy.GetMP() >= 40) {
			enemy.AttackPlayer(enemy.GetMoves()[5], player);
			numOfTurns++;
		}
		else {
			enemy.AttackPlayer(enemy.GetMoves()[2], player);
			numOfTurns++;
		}
	}
	cout << "" << numOfTurns << endl;
	return numOfTurns;
}