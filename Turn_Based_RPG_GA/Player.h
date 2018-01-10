#pragma once

#include "Character.h"

using namespace std;

class Player : public Character {

public:
	Player();
	Player(short strength, short defense, short magicAttack, short magicDefense,
		short fireResistance, short iceResistance, short waterResistance, short thunderResistance, short earthResistance,
		short hp, short mp, short accuracy, short evasion, short speed);
	~Player();
};
