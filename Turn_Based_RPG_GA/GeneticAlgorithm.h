#pragma once

#include <iostream>
#include <string>
#include <map>
#include "Enemy.h"

using namespace std;

class GeneticAlgorithm {

	Enemy enemy;
	Player player;

public:
	GeneticAlgorithm(Enemy enemy, Player player);
	int Run();
	short Fitness(Attack attack, Player &player);
};
