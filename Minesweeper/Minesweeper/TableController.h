#ifndef __TABLE_H
#define __TABLE_H

#pragma once
#include "Tile.h"

//�^�C���̕���
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
	//���݃`�F�b�N
	//��Ƀ^�C�������݂��邩�`�F�b�N���郁�\�b�h
	bool checkOnTile(int location);
	//���Ƀ^�C�������݂��邩�`�F�b�N���郁�\�b�h
	bool checkUnderTile(int location);
	//�E�Ƀ^�C�������݂��邩�`�F�b�N���郁�\�b�h
	bool checkRightTile(int location);
	//���Ƀ^�C�������݂��邩�`�F�b�N���郁�\�b�h
	bool checkLeftTile(int location);
	//�E��Ƀ^�C�������݂��邩�`�F�b�N���郁�\�b�h
	bool checkRightOnTile(int location);
	//����Ƀ^�C�������݂��邩�`�F�b�N���郁�\�b�h
	bool checkLeftOnTile(int location);
	//�E���Ƀ^�C�������݂��邩�`�F�b�N���郁�\�b�h
	bool checkRightUnderTile(int location);
	//�����Ƀ^�C�������݂��邩�`�F�b�N���郁�\�b�h
	bool checkLeftUnderTile(int location);
	//���͂̃^�C�������݂��邩�`�F�b�N���郁�\�b�h
	bool checkAroundTile(int location, bool *check);

	//��ԃ`�F�b�N(�������A�O��Ƃ��ă^�C�������݂��邱�Ƃ�ۏ�)
	//��̃^�C���̏�Ԃ��擾���郁�\�b�h
	tile_status checkOnStatus(int location);
	//���̃^�C���̏�Ԃ��擾���郁�\�b�h
	tile_status checkUnderStatus(int location);
	//�E�̃^�C���̏�Ԃ��擾���郁�\�b�h
	tile_status checkRightStatus(int location);
	//���̃^�C���̏�Ԃ��擾���郁�\�b�h
	tile_status checkLeftStatus(int location);
	//�E��̃^�C���̏�Ԃ��擾���郁�\�b�h
	tile_status checkRightOnStatus(int location);
	//����̃^�C���̏�Ԃ��擾���郁�\�b�h
	tile_status checkLeftOnStatus(int location);
	//�E���̃^�C���̏�Ԃ��擾���郁�\�b�h
	tile_status checkRightUnderStatus(int location);
	//�����̃^�C���̏�Ԃ��擾���郁�\�b�h
	tile_status checkLeftUnderStatus(int location);
	//���͂̃^�C���̏�Ԃ��擾���郁�\�b�h
	void checkAroundStatus(int location, tile_status check[8]);
	//���̐����J�E���g
	int checkFlagNumber();
};

#endif __TILE_H