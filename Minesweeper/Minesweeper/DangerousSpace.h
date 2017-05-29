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

	//1�̃^�C���ɔ��e�������邩�`�F�b�N���郁�\�b�h
	int checkBombNumber(int location);

	//1�̃^�C���ɂ��������̏�Ԃ��擾���郁�\�b�h
	void getAroundStatus(int location,bool *check, tile_status *check_status);

	//�댯�n�т̏�Ԃ��Z�b�g���郁�\�b�h
	void createDangerousSpace();
	//�댯�n�т̏�Ԃ����߂郁�\�b�h
	tile_status convertBombNumber(int bomb_number);


};

#endif __DANGEROUSSPACE_H