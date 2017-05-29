#ifndef __SAFESPACE_H
#define __SAFESPACE_H

#pragma once
#include "TableController.h"
class SafeSpace : public TableController {
public:
	SafeSpace();
	~SafeSpace();
	//テーブル上に安全地帯を生成するメソッド
	void createSafeSpace();
	//安全地帯の確認をするメソッド
	bool checkSafeSpace(int location);
	//安全地帯がクリックされた際、隣接する安全地帯を表示するメソッド
	void searchAllSafeSpace(int location);

	//安全地帯がクリックされた際、安全地帯の左のタイルを探索するメソッド
	void searchLeftSafeSpace(int location);
	//安全地帯がクリックされた際、安全地帯の右のタイルを探索するメソッド
	void searchRightSafeSpace(int location);

	//安全地帯がクリックされた際、安全地帯の上のタイルを探索するメソッド
	void searchOnSafeSpace(int location);
	//安全地帯がクリックされた際、安全地帯の下のタイルを探索するメソッド
	void searchUnderSafeSpace(int location);

	//安全地帯がクリックされた際、安全地帯の右上のタイルを探索するメソッド
	void searchRightOnSafeSpace(int location);
	//安全地帯がクリックされた際、安全地帯の右下のタイルを探索するメソッド
	void searchRightUnderSafeSpace(int location);

	//安全地帯がクリックされた際、安全地帯の左上のタイルを探索するメソッド
	void searchLeftOnSafeSpace(int location);
	//安全地帯がクリックされた際、安全地帯の左下のタイルを探索するメソッド
	void searchLeftUnderSafeSpace(int location);
};

#endif __SAFESPACE_H