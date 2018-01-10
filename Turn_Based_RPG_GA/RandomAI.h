#pragma once

#include "Enemy.h"

using namespace std;

class RandomAI {

	Enemy enemy;
	Player player;

public:
	RandomAI(Enemy enemy, Player player);
	int Run();
};