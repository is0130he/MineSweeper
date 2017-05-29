#ifndef __MOUSELISTENER_H
#define __MOUSELISTENER_H
#pragma once
#include "Tile.h"
#include"TableController.h"
#include"SafeSpace.h"
#include"GameOver.h"
#include"Bomb.h"
class MouseListener :
	public Tile
{
public:
	MouseListener();
	~MouseListener();

	//マウスで取得したタイルの位置をプログラム上のタイルの位置に変換するメソッド
	int convertTileCoordinates(int x, int y);
	//タイルに旗を立てたり取り除いたりするメソッド
	void flagTile(int location);
	//テーブル上にマウスがあるか判定するメソッド
	bool checkMousePointer(int x, int y);
	//ユーザが左クリックを行った場合のメソッド
	void inputLeftClick(int mouse_location);
	//ユーザが右クリックを行った場合のメソッド
	void inputRightClick(int mouse_location);
	//ユーザが操作するマウスポインタの位置に関するメソッド
	void inputMousePointer();
};
#endif __MOUSELISTENER_H