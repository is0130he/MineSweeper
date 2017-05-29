#ifndef __PLAYMODE_H
#define __PLAYMODE_H
#pragma once

#include"Tile.h"
#include"Bomb.h"
#include"SafeSpace.h"
#include"DangerousSpace.h"
#include"MouseListener.h"
#include"Initialize.h"
#include"GameOver.h"
#include"GameClear.h"

class PlayMode
{
public:
	PlayMode();
	~PlayMode();

	//�^�C���̉摜�����[�h
	void loadTileGraphics(int *tile);
	//�e�[�u������
	void createTable(void);
	//���C�����[�`��
	void mainRoutine();
};

#endif __PLAYMODE_H