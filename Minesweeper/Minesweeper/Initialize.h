#ifndef __INITIALIZE_H
#define __INITIALIZE_H

#pragma once
class Initialize
{
public:
	Initialize();
	~Initialize();

	//DXライブラリの初期化関連処理
	void startUp();
	//画面出力におけるバックグラウンド処理
	void backGraund();
};
#endif __INITIALIZE_H