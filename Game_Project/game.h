#pragma once
#include "main.h"

enum MENU { GAME_STRAT, GAME_INFO, GAME_END };

enum KEY_CODE { UP, DOWN, LEFT, RIGHT, SUBMIT };

enum GAME_SELECT { GET_KNIFE, GET_WEAPON, ATTACK, EXIT };

int MenuDraw();    // 게임시작 등등 버튼 생성 함수
int keyControl();  // 키보드 입력 값 컨트롤 함수
void infoGame();   // 게임정보 출력
void MainMenu();
int Gaming_select();