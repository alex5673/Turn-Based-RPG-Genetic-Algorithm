#pragma once

#include "Enemy.h"

using namespace std;

class HandMadeAI {

	Enemy enemy;
	Player player;

public:
	HandMadeAI(Enemy enemy, Player player);
	int Run();
};