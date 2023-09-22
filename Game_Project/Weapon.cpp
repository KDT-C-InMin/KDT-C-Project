#include "Weapon.h"

#include <iostream>

using namespace std;

Weapon::Weapon() {
  this->attack_Chance = 0;
  this->attack_Damage = 0;
}

bool Weapon::Attack() {
  cout << "무기로 공격합니다." << endl;
  return true;
}