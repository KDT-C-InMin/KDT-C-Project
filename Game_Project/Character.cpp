#include "Character.h"
#include <iostream>
#include <vector>
using namespace std;

Character::Character(string name) {
	this->hp = 100;
	this->level = 1;
	this->name = name;
	this->weapons = { 0, }; //초기값 초기화

}

void Character::Player_Attack() {
	cout << "플레이어가 공격을 합니다." << endl;
}


void Character::Player_GetWeapon(int WeaponIndex) { //플레이어가 무기를 획득하는 과정.
	if (WeaponIndex == 1) {
		this->weapons.push_back(WeaponIndex);
		cout << "플레이어가 총기를 획득하셨습니다." << endl;
	}
	if (WeaponIndex == 2) {
		this->weapons.push_back(WeaponIndex);
		cout << "플레이어가 칼를 획득하셨습니다." << endl;
	}
}

int Character::get_hp() {
	return hp;
}

int Character::get_level() {
	return level;
}

string Character::get_name() {
	return name;
}

void Character::get_weapon() {
	if (weapons.back() == 1) {
		cout << "(●'ㅡ'●)플레이어가 총기를 들고있습니다." << endl;
	}
	else if (weapons.back() == 2) {
		cout << "(●'ㅡ'●)플레이어가 검검를 들고있습니다." << endl;
	}
	else {
		cout << "(●'ㅡ'●)플레이어가 거지에요." << endl;
	}
}

int Character::get_weaponIndex()
{
	return weapons.back(); //1 혹은 2가 배출됨.
}

void Character::set_hp(int hp)
{
	this->hp = hp;
}

