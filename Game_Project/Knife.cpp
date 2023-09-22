
#include "Weapon.h"
#include "Knife.h"
#include <iostream>

using namespace std;

Knife::Knife() {
	this->attack_Damage = 5;
	this->attack_Chance = 3;
}

void Knife::initAttackChance()
{
	this->attack_Chance = 3;
}

int Knife::get_AttackChance() {
	cout << "해당 무기(칼)의 남은 공격 횟수는 " << attack_Chance << "번 입니다." << endl;
        return attack_Chance;
}

int Knife::get_AttackDamage()
{
	return attack_Damage;
}

int Knife::check_AttackChance()
{
	return attack_Chance;
}

bool Knife::Attack() {
	if (attack_Chance > 0) {
		cout << "쓰윽 싸악- 데미지 " << attack_Damage << " 를 입혔습니다.";
		this->attack_Chance = attack_Chance - 1;
		return true;
	}
	else {
		cout << "공격 횟수가 부족하다.";
		return false;
	}
}
