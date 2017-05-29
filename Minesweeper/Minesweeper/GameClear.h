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
	//ゲームクリアを判定するメソッド
	int checkGameClear();
	//ゲームクリア処理
	void gameClearEnd();
};

#endif __GAMECLEAR_H