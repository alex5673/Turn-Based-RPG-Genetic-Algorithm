
#include "stdafx.h"

#include "GeneticAlgorithm.h"
#include <time.h>
#include <random>
#include <map>

GeneticAlgorithm::GeneticAlgorithm(Enemy e, Player p) {
	enemy = e;
	player = p;
}

int GeneticAlgorithm::Run() {
	player.SetHP(3000); // Reset player health
	int numOfTurns = 0;

	int recentAttackIndex = 0;
	vector<Attack> recentAttacks(5);
	Attack lastAttack;
    
	// while player is alive keep selecting a move 
	while (player.GetHP() > 0) {
		cout << "" << player.GetHP() << endl;
		int randomIndex = 0;
		vector<Attack> rouletteWheel;
		// use this move set if health is not critical
		if (enemy.GetHP() > (enemy.GetHP() * 0.1)) {
			// Move set definitely needs to be better than 4 otherwise following for loop won't work
			// Pick four distinct moves from the move set
			for (int i = 0; i < 4;) {
				srand(time(0));
				randomIndex = rand() % enemy.GetMoves().size();
				Attack attack = enemy.GetMoves()[randomIndex];
				// see if AI has enough mp to actually execute the move - if the move if a magic attack which requires mp
				bool enoughMP = false;
				while (enoughMP == false)
				{
					if (attack.mpRequired > 0) {
						if (enemy.GetMP() >= attack.mpRequired) {
							enoughMP = true;
						}
						else {
							randomIndex = rand() % enemy.GetMoves().size();
							attack = enemy.GetMoves()[randomIndex];
						}
					}
					else {
						enoughMP = true;
					}
				}
				// Mutation - if move has been used 3/5 of the last times then select another move to give the other moves a chance of being picked
				vector<Attack>::iterator it = begin(recentAttacks);
				bool usedTooMuch = true;
				while (usedTooMuch == true) {
					int attackCount = 0;
					for (it; it != end(recentAttacks); it++) {
						if (*it == attack) {
							attackCount++;
						}
					}
					if (attackCount >= 3) {
						randomIndex = rand() % enemy.GetMoves().size();
						attack = enemy.GetMoves()[randomIndex];
					}
					else
					{
						usedTooMuch = false;
					}
				}
				bool attackUsed = false;
				if (lastAttack.name != "") {
					rouletteWheel.push_back(lastAttack);
					i++;
					vector<Attack>::iterator iter = begin(rouletteWheel);
					for (iter; iter != end(rouletteWheel); iter++) {
						if (*iter == attack) {
							attackUsed = true;
						}
					}
					if (attackUsed == false) {
						rouletteWheel.push_back(attack);
						i++;
					}
				}
				else {
					if (rouletteWheel.size() >= 1) {
						vector<Attack>::iterator iter = begin(rouletteWheel);
						for (iter; iter != end(rouletteWheel); iter++) {
							if (*iter == attack) {
								attackUsed = true;
							}
						}
						if (attackUsed == false) {
							rouletteWheel.push_back(attack);
							i++;
						}
					}
					else {
						rouletteWheel.push_back(attack);
						i++;
					}
				}
			}
		}
		else {
			// use this move set if hp is critical e.g. health is lower than 10%
			// Move set definitely needs to be better than 4 otherwise following for loop won't work
			// pick 4 distinct moves from the move set
			for (int i = 0; i < 4;) {
				srand(time(0));
				randomIndex = rand() % enemy.GetCriticalMoves().size();
				Attack attack = enemy.GetCriticalMoves()[randomIndex];
				// check to see if AI has enough mp to execute the move if the move is a magic attack that requires mp
				bool enoughMP = false;
				while (enoughMP == false)
				{
					if (attack.mpRequired > 0) {
						if (enemy.GetMP() >= attack.mpRequired) {
							enoughMP = true;
						}
						else {
							randomIndex = rand() % enemy.GetCriticalMoves().size();
							attack = enemy.GetCriticalMoves()[randomIndex];
						}
					}
					else {
						enoughMP = true;
					}
				}
				// Mutation - if move has been used 3/5 of the last times then select another move to give the other moves a chance of being picked
				vector<Attack>::iterator it = begin(recentAttacks);
				bool usedTooMuch = true;
				while (usedTooMuch == true) {
					int attackCount = 0;
					for (it; it != end(recentAttacks); it++) {
						if (*it == attack) {
							attackCount++;
						}
					}
					if (attackCount >= 3) {
						randomIndex = rand() % enemy.GetCriticalMoves().size();
						attack = enemy.GetCriticalMoves()[randomIndex];
					}
					else
					{
						usedTooMuch = false;
					}
				}
				bool cattackUsed = false;
				if (lastAttack.name != "") {
					rouletteWheel.push_back(lastAttack);
					i++;
					vector<Attack>::iterator iter = begin(rouletteWheel);
					for (iter; iter != end(rouletteWheel); iter++) {
						if (*iter == attack) {
							cattackUsed = true;
						}
					}
					if (cattackUsed == false) {
						rouletteWheel.push_back(attack);
						i++;
					}
				}
				else {
					if (rouletteWheel.size() >= 1) {
						vector<Attack>::iterator iter = begin(rouletteWheel);
						for (iter; iter != end(rouletteWheel); iter++) {
							if (*iter == attack) {
								cattackUsed = true;
							}
						}
						if (cattackUsed == false) {
							rouletteWheel.push_back(attack);
							i++;
						}
					}
					else {
						rouletteWheel.push_back(attack);
						i++;
					}
				}
			}
		}

		// Calulate Fitness function for each attack and order appropriately
		
		vector<Attack> rouletteWheelOrdered;

		vector<Attack>::iterator iter = begin(rouletteWheel);
		for (iter; iter != end(rouletteWheel); iter++) {
			if (rouletteWheelOrdered.size() >= 1) {
				bool inserted = false;
				vector<Attack>::iterator index;
				vector<Attack>::iterator iter2 = begin(rouletteWheelOrdered);
				for (iter2; iter2 != end(rouletteWheelOrdered); iter2++) {
					if (inserted != true) {
						if (Fitness(*iter, player) > Fitness(*iter2, player)) {
							index = iter2;
							inserted = true;
						}
					}
					
				}
				if (inserted == true) {
					rouletteWheelOrdered.insert(index, *iter);
				}
				else {
					rouletteWheelOrdered.push_back(*iter);
				}
			}
			else {
				rouletteWheelOrdered.push_back(*iter);
			}
		}

		// Attacks are ordered now ordered, so now just need to work out which one will be selected
		// from the roulette wheel depending on the appropriate probability

		random_device rd;  //Will be used to obtain a seed for the random number engine
		mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
		uniform_int_distribution<> dis(1, 10);

		Attack currentAttack;

		if (dis(gen) <= 4) {
			enemy.AttackPlayer(rouletteWheelOrdered[0], player);
			currentAttack = rouletteWheelOrdered[0];
		}
		else if (dis(gen) <= 7) {
			enemy.AttackPlayer(rouletteWheelOrdered[1], player);
			currentAttack = rouletteWheelOrdered[1];
		}
		else if (dis(gen) <= 9) {
			enemy.AttackPlayer(rouletteWheelOrdered[2], player);
			currentAttack = rouletteWheelOrdered[2];
		}
		else {
			enemy.AttackPlayer(rouletteWheelOrdered[3], player);
			currentAttack = rouletteWheelOrdered[3];
		}

		// Use last attack next time
		lastAttack = currentAttack;

		// keep a track of the last 5 attacks executed - to use for Mutation purposes
		if (recentAttackIndex <= 4) {
			recentAttacks[recentAttackIndex] = currentAttack;
			recentAttackIndex++;
		}
		else {
			recentAttackIndex = 0;
			recentAttacks[recentAttackIndex] = currentAttack;
		}
		numOfTurns++;
	}
	cout << "" << numOfTurns << endl;
	return numOfTurns;
}

short GeneticAlgorithm::Fitness(Attack attack, Player &player) {
	return enemy.CalculateDamage(attack, player);
}