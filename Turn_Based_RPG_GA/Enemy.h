#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include <memory>

#include "Character.h"
#include "Player.h"
#include "Attack.h"

class Enemy : public Character {
	bool normalMode;

	Attack attack1 = { "attack1", 20 }, attack2 = { "attack2", 10 }, attack3 = { "attack3", 90 }, attack4 = { "attack4", 5 }, attack5 = { "attack5", 50 };
	Attack fire = { "fire", 60, 40 }, ice = { "ice", 60, 40 }, water = { "water", 60, 40 }, thunder = { "thunder", 60, 40 }, earth = { "earth", 60, 40 };

	Attack cattack1 = { "cattack1", 50 }, cattack2 = { "cattack2", 80 }, cattack3 = { "cattack3", 65 }, cattack4 = { "cattack4", 190 }, cattack5 = { "cattack5", 100 };
	Attack advancedMagic1 = { "advancedMagic1", 120, 80 }, advancedMagic2 = { "advancedMagic2", 90, 65 }, advancedMagic3 = { "advancedMagic3", 220, 100 }, advancedMagic4 = { "advancedMagic4", 75, 50 }, advancedMagic5 = { "advancedMagic5", 65, 30 };


	//shared_ptr<Attack> attptr1 = shared_ptr<Attack>(&attack1), attptr2 = shared_ptr<Attack>(&attack2), attptr3 = shared_ptr<Attack>(&attack3), attptr4 = shared_ptr<Attack>(&attack4), attptr5 = shared_ptr<Attack>(&attack5);
	//shared_ptr<MagicAttack> magptr1 = shared_ptr<MagicAttack>(&fire), magptr2 = shared_ptr<MagicAttack>(&ice), magptr3 = shared_ptr<MagicAttack>(&water), magptr4 = shared_ptr<MagicAttack>(&thunder), magptr5 = shared_ptr<MagicAttack>(&earth);

	//shared_ptr<Attack> cattptr1 = shared_ptr<Attack>(&cattack1), cattptr2 = shared_ptr<Attack>(&cattack2), cattptr3 = shared_ptr<Attack>(&cattack3), cattptr4 = shared_ptr<Attack>(&cattack4), cattptr5 = shared_ptr<Attack>(&cattack5);
	//shared_ptr<MagicAttack> advmagptr1 = shared_ptr<MagicAttack>(&advancedMagic1), advmagptr2 = shared_ptr<MagicAttack>(&advancedMagic2), advmagptr3 = shared_ptr<MagicAttack>(&advancedMagic3), advmagptr4 = shared_ptr<MagicAttack>(&advancedMagic4), advmagptr5 = shared_ptr<MagicAttack>(&advancedMagic5);

	// Both these move sets need to bigger than 4
	vector<Attack> moves = { attack1, attack2, attack3, attack4, attack5, fire, ice, water, thunder, earth };
	vector<Attack> criticalMoves = { cattack1, cattack2, cattack3, cattack4, cattack5, advancedMagic1, advancedMagic2, advancedMagic3, advancedMagic4, advancedMagic5 };

public:
	Enemy();
	Enemy(short stengthv, short defensev, short magicAttackv, short magicDefensev,
		short fireResistancev, short iceResistancev, short waterResistancev, short thunderResistancev, short earthResistancev,
		short hpv, short mpv, short accuracyv, short evasionv, short speedv);
	~Enemy();

	void AttackPlayer(Attack attack, Player &player);
	short CalculateDamage(Attack attack, Player player);

	bool GetNormalMode() const { return normalMode; }
	vector<Attack> GetMoves() const { return moves; }
	vector<Attack> GetCriticalMoves() const { return criticalMoves; }
	vector<Attack>& GetMoves() { return moves; }
	vector<Attack>& GetCriticalMoves() { return criticalMoves; }

	void SetNormalMode(bool mode) { normalMode = mode; }
};

#endif 
