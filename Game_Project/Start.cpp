////////////////////////////////////////////////////////////////////////////
//      :: C++ ������Ʈ 07 �� ���� ::
//      1. ĳ����, ����, Į, �� Ŭ������ ������ش�.
//      2. ĳ���� Ŭ����
//          -�ʵ�: ��hp��, ��level��, ������顯
//          - �޼ҵ� : ���� �ݱ�, �����ϱ�(�����ϱ� �޼ҵ忡���� ������ �ִ�
//          ����鸸 ����ؼ�
//            ������ �� ������, ���ݴ��� ĳ������ hp�� �ش��ϴ� ������
//            ���ݷ¸�ŭ �����Ѵ�.)
//      3. ���� Ŭ����
//          - �ʵ�: ���ݷ�, ���� ���� Ƚ��
//          - �޼ҵ� : �����ϱ�
//      4. �� & Į Ŭ����(���� Ŭ������ ��� �޴� Ŭ����)
//          - Į : ���ݷ� - 5, ���ݰ���Ƚ�� - 3, �����ϱ� - "���" ���
//          - �� : ���ݷ� - 10, ���ݰ���Ƚ�� - 1, �����ϱ� - "�ѽ��" ���
//      5. ���� �и��ϱ�.
//
///////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "Character.h"
#include "Gun.h"
#include "Knife.h"
#include "game.h"  //Ű ��Ʈ��
#include "util.h"  //��ǥ ��Ʈ��

using namespace std;

int game_count;

int game_Start() {
  Character character("Ŀ�ٽ�");
  // ���� ĳ���� ���� ������ �κ��� ���� ������ ������ (�����������̵� + ���̵�
  // ���� ��й�ȣ.... �� ���� st)

  Character enemy("������");  // �ڡڡڡ� �ؾ�� ���� Ŭ������ ���� �־����� ���ڴ�.

  Gun* gun = new Gun();
  Knife* knife = new Knife();
  game_count = 0;

  while (1) {
    system("cls");  // �ܼ�â�� Ŭ�� �϶� �ǹ�

    cout << "\n";
    cout << " ���������������������������� \n";
    cout << " ��"
         << "(��'��'��)ĳ������ �̸� : " << character.get_name() << "�Դϴ�."
         << endl;
    cout << " ��"
         << "(��'��'��)ĳ������ HP : " << character.get_hp() << " �Դϴ�."
         << endl;
    cout << " ��"
         << "(��'��'��)ĳ������ Level : " << character.get_level() << "�Դϴ�."
         << endl;
    cout << " ��";
    cout << " ��";
    // ���� Ƚ�� ��Ÿ����
    if (character.get_weaponIndex() == 0) {  // ����

      if (game_count > 1) character.delete_Weapon();
      cout << character.get_weaponIndex() << "\n";
    }
    if (character.get_weaponIndex() == 1) {  // ��
      character.Player_GetWeapon(1);
      gun->get_AttackChance() > 0;
    }
    if (character.get_weaponIndex() == 2) {  // Į
      character.Player_GetWeapon(2);
      knife->get_AttackChance();
    }
    cout << " ��-------------- �̰� ���� �ߴ��� --------------\n";
    cout << " �� \n";
    // TODO : ���� ��Ȳ �޼��� ���
    cout << " ��"
         << "(��'��'��)���� hp : " << enemy.get_hp() << "�Դϴ�." << endl;
    cout << " �� \n";
    cout << " ���������������������������� \n";

    int userSelect = Gaming_select();  // ���ӽ��� ��ư ����
    cout << userSelect << endl;

    switch (userSelect) {
      case GAME_SELECT::GET_KNIFE: {
        game_count++;
        character.Player_GetWeapon(1);
        gun->initAttackChance();
        cout << "\n";
        break;
      }
      case GAME_SELECT::GET_WEAPON: {
        game_count++;
        character.Player_GetWeapon(2);
        knife->initAttackChance();  // ����Ƚ�� �ʱ�ȭ.
        cout << "\n";
        break;
      }
      case GAME_SELECT::ATTACK: {
        if (character.get_weaponIndex() == 1) {  // ��
          if (gun->check_AttackChance() > 0) {
            gun->Attack();
            enemy.set_hp(enemy.get_hp() - gun->get_AttackDamage());
          } else {
            game_count--;
            character.delete_Weapon();
            cout << "���� Ƚ���� �����ؼ� ���ݿ� �����߽��ϴ�," << endl;
          }
        } else if (character.get_weaponIndex() == 2) {  // Į
          if (knife->check_AttackChance() > 0) {
            knife->Attack();
            enemy.set_hp(enemy.get_hp() - knife->get_AttackDamage());
          } else {
            game_count--;
            character.delete_Weapon();
            cout << "���� Ƚ���� �����ؼ� ���ݿ� �����߽��ϴ�," << endl;
          }
        } else {
          cout << "�ƹ��� ���Ⱑ ��� ���ݿ� �����߽��ϴ�," << endl;
        }
        cout << "������ ���� ü���� : " << enemy.get_hp() << endl;
      }
      case GAME_SELECT::EXIT: {
        cout << "������ �����ϰڽ��ϴ�. ��(*�ơ��*)�� " << endl;
        break;
      }
    }
  }
  return 0;
};