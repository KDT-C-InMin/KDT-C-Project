
#include "Gun.h"

#include <iostream>

#include "Weapon.h"

using namespace std;

Gun::Gun() {
  this->attack_Damage = 10;
  this->attack_Chance = 1;
}

bool Gun::Attack() {
  if (attack_Chance > 0) {
    // cout << "���� ����- ������ " << attack_Damage << " �� �������ϴ�." ;
    this->attack_Chance = attack_Chance - 1;
    return true;
  } else {
    cout << "���� Ƚ���� �����ϴ�.";
    return false;
  }
}

void Gun::initAttackChance() { this->attack_Chance = 1; }

int Gun::get_AttackChance() {
  cout << "�ش� ����(��)�� ���� ���� Ƚ���� " << attack_Chance
       << "�� �Դϴ�.\n";
  return attack_Chance;
}

int Gun::get_AttackDamage() { return attack_Damage; }

int Gun::check_AttackChance() { return attack_Chance; }
