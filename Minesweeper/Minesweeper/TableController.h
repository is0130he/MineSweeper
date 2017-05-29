#ifndef __TABLE_H
#define __TABLE_H

#pragma once
#include "Tile.h"

//タイルの方向
#define ON 0
#define UNDER 1
#define RIGHT 2
#define LEFT 3
#define RIGHT_ON 4
#define LEFT_ON 5
#define RIGHT_UNDER 6
#define LEFT_UNDER 7

class TableController : public Tile {
public:
	TableController();
	~TableController();
	//存在チェック
	//上にタイルが存在するかチェックするメソッド
	bool checkOnTile(int location);
	//下にタイルが存在するかチェックするメソッド
	bool checkUnderTile(int location);
	//右にタイルが存在するかチェックするメソッド
	bool checkRightTile(int location);
	//左にタイルが存在するかチェックするメソッド
	bool checkLeftTile(int location);
	//右上にタイルが存在するかチェックするメソッド
	bool checkRightOnTile(int location);
	//左上にタイルが存在するかチェックするメソッド
	bool checkLeftOnTile(int location);
	//右下にタイルが存在するかチェックするメソッド
	bool checkRightUnderTile(int location);
	//左下にタイルが存在するかチェックするメソッド
	bool checkLeftUnderTile(int location);
	//周囲のタイルが存在するかチェックするメソッド
	bool checkAroundTile(int location, bool *check);

	//状態チェック(ただし、前提としてタイルが存在することを保証)
	//上のタイルの状態を取得するメソッド
	tile_status checkOnStatus(int location);
	//下のタイルの状態を取得するメソッド
	tile_status checkUnderStatus(int location);
	//右のタイルの状態を取得するメソッド
	tile_status checkRightStatus(int location);
	//左のタイルの状態を取得するメソッド
	tile_status checkLeftStatus(int location);
	//右上のタイルの状態を取得するメソッド
	tile_status checkRightOnStatus(int location);
	//左上のタイルの状態を取得するメソッド
	tile_status checkLeftOnStatus(int location);
	//右下のタイルの状態を取得するメソッド
	tile_status checkRightUnderStatus(int location);
	//左下のタイルの状態を取得するメソッド
	tile_status checkLeftUnderStatus(int location);
	//周囲のタイルの状態を取得するメソッド
	void checkAroundStatus(int location, tile_status check[8]);
	//旗の数をカウント
	int checkFlagNumber();
};

#endif __TILE_H