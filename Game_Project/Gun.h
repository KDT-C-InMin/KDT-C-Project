#pragma once  // �ѹ� �о�� �߰������� ���� �ʵ����ϴ� ���. ǥ���� �ƴϹǷ�
              // �۵����� ���� �� �ִ�.
#include <iostream>

#include "Weapon.h"
#ifndef GUN_H
#define GUN_H
using std::string;

class Gun : public Weapon {
 public:
  Gun();
  bool Attack();

  void initAttackChance();  // ���ο� ���⸦ ȹ������ �� ���� ����Ƚ�� �ʱ�ȭ.
  int get_AttackChance();
  int get_AttackDamage();    // ������
  int check_AttackChance();  // ����Ƚ�� üũ
};
#endif
