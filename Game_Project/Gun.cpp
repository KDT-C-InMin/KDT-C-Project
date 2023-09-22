
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
    // cout << "빵야 빵야- 데미지 " << attack_Damage << " 를 입혔습니다." ;
    this->attack_Chance = attack_Chance - 1;
    return true;
  } else {
    cout << "공격 횟수가 부족하다.";
    return false;
  }
}

void Gun::initAttackChance() { this->attack_Chance = 1; }

int Gun::get_AttackChance() {
  cout << "해당 무기(총)의 남은 공격 횟수는 " << attack_Chance
       << "번 입니다.\n";
  return attack_Chance;
}

int Gun::get_AttackDamage() { return attack_Damage; }

int Gun::check_AttackChance() { return attack_Chance; }
