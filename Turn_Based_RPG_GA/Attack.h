#pragma once

#ifndef ATTACK_H
#define ATTACK_H

#include <string>

typedef struct attack {
	attack() : name(""), strength(0), mpRequired(0) {}
	attack(std::string nam, short streng) : name(nam), strength(streng), mpRequired(0) {}
	attack(std::string nam, short streng, short mpReq) : name(nam), strength(streng), mpRequired(mpReq) {}
	std::string name;
	short strength;
	short mpRequired;

	bool operator==(attack& otherAttack) {
		if ((name.compare(otherAttack.name) == 0)){
			return true;
		}
		else {
			return false;
		}
	}
} Attack;

typedef struct magicAttack : attack {
	magicAttack(std::string nam, short streng, short mpReq) : attack::attack(nam, streng, mpReq) {}
} MagicAttack;

#endif
