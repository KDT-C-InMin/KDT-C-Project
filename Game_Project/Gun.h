#pragma once  // 한번 읽어가면 추가적으로 읽지 않도록하는 기능. 표준이 아니므로
              // 작동하지 않을 수 있다.
#include <iostream>

#include "Weapon.h"
#ifndef GUN_H
#define GUN_H
using std::string;

class Gun : public Weapon {
 public:
  Gun();
  bool Attack();

  void initAttackChance();  // 새로운 무기를 획득했을 때 무기 공격횟수 초기화.
  int get_AttackChance();
  int get_AttackDamage();    // 데미지
  int check_AttackChance();  // 공격횟수 체크
};
#endif
