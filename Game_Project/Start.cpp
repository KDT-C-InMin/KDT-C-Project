////////////////////////////////////////////////////////////////////////////
//      :: C++ 프로젝트 07 번 문제 ::
//      1. 캐릭터, 무기, 칼, 총 클래스를 만들어준다.
//      2. 캐릭터 클래스
//          -필드: ‘hp’, ‘level’, ‘무기들’
//          - 메소드 : 무기 줍기, 공격하기(공격하기 메소드에서는 가지고 있는
//          무기들만 사용해서
//            공격할 수 있으며, 공격당한 캐릭터의 hp가 해당하는 무기의
//            공격력만큼 감소한다.)
//      3. 무기 클래스
//          - 필드: 공격력, 공격 가능 횟수
//          - 메소드 : 공격하기
//      4. 총 & 칼 클래스(무기 클래스를 상속 받는 클래스)
//          - 칼 : 공격력 - 5, 공격가능횟수 - 3, 공격하기 - "찌르기" 출력
//          - 총 : 공격력 - 10, 공격가능횟수 - 1, 공격하기 - "총쏘기" 출력
//      5. 파일 분리하기.
//
///////////////////////////////////////////////////////////////////////////
#include <iostream>

#include "Character.h"
#include "Gun.h"
#include "Knife.h"
#include "game.h"  //키 컨트롤
#include "util.h"  //좌표 컨트롤

using namespace std;

int game_Start() {
  Character character("커다시");
  // 게임 캐릭터 생성 관련한 부분이 따로 있으면 좋을듯 (유저생성아이디 + 아이디
  // 저장 비밀번호.... 좀 게임 st)

  Character enemy("슬라임");  // ★★★★ 앤어미 생성 클래스가 따로 있었으면 좋겠다.

  Gun* gun = new Gun();
  Knife* knife = new Knife();

  while (1) {
    system("cls");  // 콘솔창을 클린 하란 의미

    cout << "\n";
    cout << " ■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n";
    cout << " ■"
         << "(●'ㅡ'●)캐릭터의 이름 : " << character.get_name() << "입니다."
         << endl;
    cout << " ■"
         << "(●'ㅡ'●)캐릭터의 HP : " << character.get_hp() << " 입니다."
         << endl;
    cout << " ■"
         << "(●'ㅡ'●)캐릭터의 Level : " << character.get_level() << "입니다."
         << endl;
    cout << " ■";
    character.get_weapon();
    cout << " ■";
    // 공격 횟수 나타내기
    if (character.get_weaponIndex() == 0) {  // 없음
      cout << "\n";
    }
    if (character.get_weaponIndex() == 1) {  // 총
      gun->get_AttackChance();
    }
    if (character.get_weaponIndex() == 2) {  // 칼
      knife->get_AttackChance();
    }
    cout << " ■-------------- 이걸 뭐라 했더라 --------------\n";
    cout << " ■ \n";
    // TODO : 게임 상황 메세지 출력
    cout << " ■"
         << "(●'ㅡ'●)적의 hp : " << enemy.get_hp() << "입니다." << endl;
    cout << " ■ \n";
    cout << " ■■■■■■■■■■■■■■■■■■■■■■■■■■■ \n";

    int userSelect = Gaming_select();  // 게임시작 버튼 생성
    cout << userSelect << endl;

    switch (userSelect) {
      case GAME_SELECT::GET_KNIFE: {
        character.Player_GetWeapon(1);
        gun->initAttackChance();
        cout << "\n";
        break;
      }
      case GAME_SELECT::GET_WEAPON: {
        character.Player_GetWeapon(2);
        knife->initAttackChance();  // 공격횟수 초기화.
        cout << "\n";
        break;
      }
      case GAME_SELECT::ATTACK: {
        if (character.get_weaponIndex() == 1) {  // 총
          if (gun->check_AttackChance() > 0) {
            gun->Attack();
            enemy.set_hp(enemy.get_hp() - gun->get_AttackDamage());
          } else {
            cout << "공격 횟수가 부족해서 공격에 실패했습니다," << endl;
          }
        } else if (character.get_weaponIndex() == 2) {  // 칼
          if (knife->check_AttackChance() > 0) {
            knife->Attack();
            enemy.set_hp(enemy.get_hp() - knife->get_AttackDamage());
          } else {
            cout << "공격 횟수가 부족해서 공격에 실패했습니다," << endl;
          }
        } else {
          cout << "아무런 무기가 없어서 공격에 실패했습니다," << endl;
        }
        cout << "적에게 남은 체력은 : " << enemy.get_hp() << endl;
      }
      case GAME_SELECT::EXIT: {
        cout << "게임을 종료하겠습니다. ㄴ(*°▽°*)ㄱ " << endl;
        break;
      }
    }
  }
  return 0;
};