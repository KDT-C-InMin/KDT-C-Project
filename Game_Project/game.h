#pragma once
#include "main.h"

enum MENU { GAME_STRAT, GAME_INFO, GAME_END };

enum KEY_CODE { UP, DOWN, LEFT, RIGHT, SUBMIT };

enum GAME_SELECT { GET_KNIFE, GET_WEAPON, ATTACK, EXIT };

int MenuDraw();    // ���ӽ��� ��� ��ư ���� �Լ�
int keyControl();  // Ű���� �Է� �� ��Ʈ�� �Լ�
void infoGame();   // �������� ���
void MainMenu();
int Gaming_select();