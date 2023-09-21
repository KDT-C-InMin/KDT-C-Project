#include "main.h"
#include "util.h"
#include "game.h"
#include "Start.h"
#include <iostream>


using namespace std;

int main()
{
	init();
    while (1) {
        MainMenu(); // 메인 메뉴 그리기 생성자 호출
        int menuCode = MenuDraw(); // 게임시작 버튼 생성
        //printf("메뉴 코드는 %d ", menuCode);

        if (menuCode == 0) {
            game_Start();// 게임시작 
        }
        else if (menuCode == 1) {
            infoGame();// 게임정보
        }
        else if (menuCode == 2) {
            cout << "\n\n\n";
            return 0; // 게임 종료
        }
        system("cls"); // 콘솔창을 클린 하란 의미
    }
}
