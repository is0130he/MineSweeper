#ifndef __GAMEOVER_H
#define __GAMEOVER_H
#pragma once
#include"Tile.h"
#include"Initialize.h"
class GameOver
{
public:
	GameOver();
	~GameOver();
	//ゲームオーバーを判定するメソッド
	//ゲームオーバー処理を行うメソッド
	void gameOverEnd(int location);
	int checkGameOver();
};
#endif __GAMEOVER_H