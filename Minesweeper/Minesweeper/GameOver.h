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
	//�Q�[���I�[�o�[�𔻒肷�郁�\�b�h
	//�Q�[���I�[�o�[�������s�����\�b�h
	void gameOverEnd(int location);
	int checkGameOver();
};
#endif __GAMEOVER_H