#ifndef __DANGEROUSSPACE_H
#define __DANGEROUSSPACE_H

#pragma once
#include "TableController.h"
class DangerousSpace :
	public TableController
{
public:
	DangerousSpace();
	~DangerousSpace();

	//1つのタイルに爆弾が何個あるかチェックするメソッド
	int checkBombNumber(int location);

	//1つのタイルにおける周りの状態を取得するメソッド
	void getAroundStatus(int location,bool *check, tile_status *check_status);

	//危険地帯の状態をセットするメソッド
	void createDangerousSpace();
	//危険地帯の状態を決めるメソッド
	tile_status convertBombNumber(int bomb_number);


};

#endif __DANGEROUSSPACE_H