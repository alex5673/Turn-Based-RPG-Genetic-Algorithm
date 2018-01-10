
#include "stdafx.h"

#include "Enemy.h"

Enemy::Enemy() : normalMode(true) {}

Enemy::Enemy(short strengthv, short defensev, short magicAttackv, short magicDefensev,
	short fireResistancev, short iceResistancev, short waterResistancev, short thunderResistancev, short earthResistancev,
	short hpv, short mpv, short accuracyv, short evasionv, short speedv)
{
	strength = strengthv, defense = defensev, magicAttack = magicAttackv, magicAttack = magicDefensev,
		fireResistance = fireResistancev, iceResistance = iceResistancev, waterResistance = waterResistancev, thunderResistance = thunderResistancev, earthResistance = earthResistancev,
		hp = hpv, mp = mpv, accuracy = accuracyv, evasion = evasionv, speed = speedv;
	normalMode = true;
}

Enemy::~Enemy() {}

void Enemy::AttackPlayer(Attack attack, Player &player)
{
	short damageDealt = CalculateDamage(attack, player);
	cout << "" << damageDealt << endl;
	player.DecreaseHP(damageDealt);
	cout << player.GetHP() << endl;
	if (attack.mpRequired > 0) {
		SetMP(GetMP() - attack.mpRequired);
	}
}

short Enemy::CalculateDamage(Attack attack, Player player)
{
	if (attack.mpRequired == 0) {
		return (((strength + (attack.strength)) * 4) - player.GetDefense());
	}
	else if (attack.mpRequired > 0) {
		switch (attack.name[0]) {
		case 'f':
			return ((((magicAttack + (attack.strength)) * 4) - player.GetMagicDefense()) * (1 - (player.GetFireResistance() / 100)));
			break;

		case 'i':
			return ((((magicAttack + (attack.strength)) * 4) - player.GetMagicDefense()) * (1 - (player.GetIceResistance() / 100)));
			break;

		case 'w':
			return ((((magicAttack + (attack.strength)) * 4) - player.GetMagicDefense()) * (1 - (player.GetWaterResistance() / 100)));
			break;

		case 't':
			return ((((magicAttack + (attack.strength)) * 4) - player.GetMagicDefense()) * (1 - (player.GetThunderResistance() / 100)));
			break;

		case 'e':
			return ((((magicAttack + (attack.strength)) * 4) - player.GetMagicDefense()) * (1 - (player.GetEarthResistance() / 100)));
			break;

		default:
			return 0;
			break;
		}
	}
	else {
		cout << "something went wrong" << endl;
		return 0;
	}
}