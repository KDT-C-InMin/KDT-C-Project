#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>

#include "Weapon.h"
//- 필드: ‘hp’, ‘level’, ‘무기들’
//- 메소드 : 무기 줍기, 공격하기(공격하기 메소드에서는 가지고 있는 무기들만
// 사용해서 공
//    격할 수 있으며, 공격당한 캐릭터의 hp가 해당하는 무기의 공격력만큼
//    감소한다.
using namespace std;

class Character {
 private:
  string name;
  int hp;
  int level;
  vector<int> weapons;  // 포인터 선언으로, 객체 생성 필요

 public:
  Character(string name);
  virtual ~Character() {}

  void Player_Attack();
  void Player_GetWeapon(int WeaponIndex);
  int get_hp();
  int get_level();
  string get_name();
  void get_weapon();
  int get_weaponIndex();
  void delete_Weapon();  // inah
  void set_hp(int hp);   // 공격받고 피 깎인거 저장
};

#endif
