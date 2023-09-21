#include "main.h"

#include <iostream>

#include "Start.h"
#include "game.h"
#include "util.h"

using namespace std;

int main() {
  init();
  while (1) {
    MainMenu();  // 메인 메뉴 그리기 생성자 호출
    MENU menuCode = static_cast<MENU>(MenuDraw());  // 게임시작 버튼 생성
    // printf("메뉴 코드는 %d ", menuCode);

    switch (menuCode) {
      case MENU::GAME_STRAT:
        game_Start();  // 게임시작
        break;
      case MENU::GAME_INFO:
        infoGame();  // 게임정보
        break;
      case MENU::GAME_END: {
        cout << "\n\n\n";
        return 0;  // 게임 종료
        break;
      }
      default:
        cout << "올바른 키를 입력해주세요.";
        continue;
    }
    system("cls");  // 콘솔창을 클린 하란 의미
  }
}
