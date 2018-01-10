
#include "stdafx.h"

#include "Player.h"

Player::Player() {}

Player::Player(short strengthv, short defensev, short magicAttackv, short magicDefensev,
	short fireResistancev, short iceResistancev, short waterResistancev, short thunderResistancev, short earthResistancev,
	short hpv, short mpv, short accuracyv, short evasionv, short speedv)
{
	strength = strengthv, defense = defensev, magicAttack = magicAttackv, magicAttack = magicDefensev,
		fireResistance = fireResistancev, iceResistance = iceResistancev, waterResistance = waterResistancev, thunderResistance = thunderResistancev, earthResistance = earthResistancev,
		hp = hpv, mp = mpv, accuracy = accuracyv, evasion = evasionv, speed = speedv;
}

Player::~Player() {}