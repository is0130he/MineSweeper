//��d�C���N���[�h�������
#ifndef __BOMB_H
#define __BOMB_H

#pragma once
#include "Tile.h"
#include<time.h>

//���e�̐�
#define BOMB_NUMBER 10
class Bomb : public Tile {
public:
	Bomb();
	~Bomb();
	//�������s�����\�b�h(�����\��)

	//���e�𐶐����郁�\�b�h
	void Bomb::createBomb();

	//���������p�̃��\�b�h
	int locateBomb();
	//�����̏d���`�F�b�N���s�����\�b�h
	bool checkRepeat(int *check, int target);
	//���������������甚�e���Z�b�g���郁�\�b�h
	void Bomb::setBomb(int *check);
};
#endif __BOMB_H