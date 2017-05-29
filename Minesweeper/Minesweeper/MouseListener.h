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

	//�}�E�X�Ŏ擾�����^�C���̈ʒu���v���O������̃^�C���̈ʒu�ɕϊ����郁�\�b�h
	int convertTileCoordinates(int x, int y);
	//�^�C���Ɋ��𗧂Ă����菜�����肷�郁�\�b�h
	void flagTile(int location);
	//�e�[�u����Ƀ}�E�X�����邩���肷�郁�\�b�h
	bool checkMousePointer(int x, int y);
	//���[�U�����N���b�N���s�����ꍇ�̃��\�b�h
	void inputLeftClick(int mouse_location);
	//���[�U���E�N���b�N���s�����ꍇ�̃��\�b�h
	void inputRightClick(int mouse_location);
	//���[�U�����삷��}�E�X�|�C���^�̈ʒu�Ɋւ��郁�\�b�h
	void inputMousePointer();
};
#endif __MOUSELISTENER_H