#ifndef __TILE_H
#define __TILE_H

#pragma once
#include "DxLib.h"

#define X_MAX 10
#define Y_MAX 10
//タイルの画像の比率
#define TILE_RATE 0.25
#define TILE_INTERVAL 26

//画像と座標とのずれ
#define GRAPHIC_GAP 13

//タイル描画の初期値
//(テーブル全体の移動が可能)
#define BEGIN_X 200
#define BEGIN_Y 100

//タイルの状態定義
enum tile_status {
	nothing = 0, /*未定義状態*/
	one = 1,
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	bomb = 9,
	safespace = 10,
	//flag = 11
};

class Tile
{
public:
	//ここからはメソッド

	//コピーコンストラクタ
	//コンストラクタで初期化可能にする(ただし、タイルの中身は除く)
	Tile(int x, int y, bool open, tile_status status, bool flag_status);

	//デフォルトコンストラクタ
	Tile();

	//デストラクタ
	~Tile();

	//1つのタイルの中身を出力
	void Tile::dispTile(int image);

	//全てのタイルの中身を出力
	void dispAll();

	//タイルの開放に関するセッター
	void Tile::setOpen(bool open);

	//タイルの開放に関するゲッター
	bool Tile::getOpen();

	//タイルの状態に関するセッター
	void Tile::setStatus(tile_status status);

	//タイルの状態に関するゲッター
	tile_status Tile::getStatus();

	//旗のセッター
	void Tile::setFlag(bool flag);

	//旗のゲッター
	bool Tile::getFlag();

private:
	//タイルの開放
	bool open;

	//旗の状態
	bool flag_status;

protected:
	//座標(ウィンドウ上の始点)
	int x;
	int y;
	//タイルの状態
	tile_status status;
};

#endif