#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Character {
protected:
	short strength, defense, magicAttack, magicDefense,
		fireResistance, iceResistance, waterResistance, thunderResistance, earthResistance,
		hp, mp, accuracy, evasion, speed;
public:
	Character();
	~Character() {}

	short GetStrength() const { return strength; }
	short GetDefense() const { return defense; }
	short GetMagicAttack() const { return magicAttack; }
	short GetMagicDefense() const { return magicDefense; }
	short GetFireResistance() const { return fireResistance; }
	short GetIceResistance() const { return iceResistance; }
	short GetWaterResistance() const { return waterResistance; }
	short GetThunderResistance() const { return thunderResistance; }
	short GetEarthResistance() const { return earthResistance; }
	short GetHP() const { return hp; }
	short GetMP() const { return mp; }
	short GetAccuracy() const { return accuracy; }
	short GetEvasion() const { return evasion; }
	short GetSpeed() const { return speed; }

	void SetStrength(short streng) { strength = streng; }
	void SetDefense(short def) { defense = def; }
	void SetMagicAttack(short magAtt) { magicAttack = magAtt; }
	void SetMagicDefense(short magDef) { magicDefense = magDef; }
	void SetFireResistance(short fireResis) { fireResistance = fireResis; }
	void SetIceResistance(short iceResis) { iceResistance = iceResis; }
	void SetWaterResistance(short waterResis) { waterResistance = waterResis; }
	void SetThunderResistance(short thunResis) { thunderResistance = thunResis; }
	void SetEarthResistance(short earthResis) { earthResistance = earthResis; }
	void SetHP(short hitPoints) { hp = hitPoints; }
	void SetMP(short magicPoints) { mp = magicPoints; }
	void SetAccuracy(short acc) { accuracy = acc; }
	void SetEvasion(short evade) { evasion = evade; }
	void SetSpeed(short sped) { speed = sped; }

	void DecreaseHP(short decrease) { hp -= decrease; }
};
