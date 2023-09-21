#pragma once
#include <iostream>
using std::string;

#ifndef __WEAPON_H__  // __PERSON_H__가 define 되지 않았다면,
#define __WEAPON_H__  // #endif가 나오기 전까지 포함시켜라

//- 필드: 공격력, 공격 가능 횟수
//- 메소드: 공격하기

class Weapon {
 protected:
  int attack_Damage;  // 공격력
  int attack_Chance;  // 공격 가능 횟수

 public:
  Weapon();
  virtual ~Weapon() {}

  virtual void Attack() = 0;
};

#endif
