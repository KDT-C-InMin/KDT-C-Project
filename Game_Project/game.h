#pragma once
#include "main.h"

enum MENU { GAME_STRAT, GAME_INFO, GAME_END };

enum KEY_CODE { UP, DOWN, LEFT, RIGHT, SUBMIT };

int MenuDraw();    // ���ӽ��� ��� ��ư ���� �Լ�
int keyControl();  // Ű���� �Է� �� ��Ʈ�� �Լ�
void infoGame();   // �������� ���
void MainMenu();
int Gaming_select();