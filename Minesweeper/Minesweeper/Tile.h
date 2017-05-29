#ifndef __TILE_H
#define __TILE_H

#pragma once
#include "DxLib.h"

#define X_MAX 10
#define Y_MAX 10
//�^�C���̉摜�̔䗦
#define TILE_RATE 0.25
#define TILE_INTERVAL 26

//�摜�ƍ��W�Ƃ̂���
#define GRAPHIC_GAP 13

//�^�C���`��̏����l
//(�e�[�u���S�̂̈ړ����\)
#define BEGIN_X 200
#define BEGIN_Y 100

//�^�C���̏�Ԓ�`
enum tile_status {
	nothing = 0, /*����`���*/
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
	//��������̓��\�b�h

	//�R�s�[�R���X�g���N�^
	//�R���X�g���N�^�ŏ������\�ɂ���(�������A�^�C���̒��g�͏���)
	Tile(int x, int y, bool open, tile_status status, bool flag_status);

	//�f�t�H���g�R���X�g���N�^
	Tile();

	//�f�X�g���N�^
	~Tile();

	//1�̃^�C���̒��g���o��
	void Tile::dispTile(int image);

	//�S�Ẵ^�C���̒��g���o��
	void dispAll();

	//�^�C���̊J���Ɋւ���Z�b�^�[
	void Tile::setOpen(bool open);

	//�^�C���̊J���Ɋւ���Q�b�^�[
	bool Tile::getOpen();

	//�^�C���̏�ԂɊւ���Z�b�^�[
	void Tile::setStatus(tile_status status);

	//�^�C���̏�ԂɊւ���Q�b�^�[
	tile_status Tile::getStatus();

	//���̃Z�b�^�[
	void Tile::setFlag(bool flag);

	//���̃Q�b�^�[
	bool Tile::getFlag();

private:
	//�^�C���̊J��
	bool open;

	//���̏��
	bool flag_status;

protected:
	//���W(�E�B���h�E��̎n�_)
	int x;
	int y;
	//�^�C���̏��
	tile_status status;
};

#endif