#ifndef __GAMECLEAR_H
#define __GAMECLEAR_H

#pragma once
#include"DxLib.h"
#include"Tile.h"
#include"Bomb.h"

class GameClear
{
public:
	GameClear();
	~GameClear();
	//�Q�[���N���A�𔻒肷�郁�\�b�h
	int checkGameClear();
	//�Q�[���N���A����
	void gameClearEnd();
};

#endif __GAMECLEAR_H