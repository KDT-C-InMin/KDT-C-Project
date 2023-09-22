
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
	cout << "�ش� ����(Į)�� ���� ���� Ƚ���� " << attack_Chance << "�� �Դϴ�." << endl;
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
		cout << "���� �ξ�- ������ " << attack_Damage << " �� �������ϴ�.";
		this->attack_Chance = attack_Chance - 1;
		return true;
	}
	else {
		cout << "���� Ƚ���� �����ϴ�.";
		return false;
	}
}
