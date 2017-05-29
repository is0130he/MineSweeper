//二重インクルード回避処理
#ifndef __BOMB_H
#define __BOMB_H

#pragma once
#include "Tile.h"
#include<time.h>

//爆弾の数
#define BOMB_NUMBER 10
class Bomb : public Tile {
public:
	Bomb();
	~Bomb();
	//爆発を行うメソッド(実装予定)

	//爆弾を生成するメソッド
	void Bomb::createBomb();

	//乱数生成用のメソッド
	int locateBomb();
	//乱数の重複チェックを行うメソッド
	bool checkRepeat(int *check, int target);
	//生成した乱数から爆弾をセットするメソッド
	void Bomb::setBomb(int *check);
};
#endif __BOMB_H