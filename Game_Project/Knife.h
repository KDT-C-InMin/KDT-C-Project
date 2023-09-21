#pragma once // 한번 읽어가면 추가     
#include "Weapon.h"
#ifndef KNIFE_H
#define KNIFE_H
using std::string;


class Knife : public Weapon {

public:
	Knife();
	void Attack();

	void initAttackChance(); //새로운 무기를 획득했을 때 무기 공격횟수 초기화.
	void get_AttackChance(); // 공격횟수를 나타내기 위함.
	int get_AttackDamage(); //데미지 
	int check_AttackChance(); //공격횟수 체크
};


#endif
