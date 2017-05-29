#ifndef __SAFESPACE_H
#define __SAFESPACE_H

#pragma once
#include "TableController.h"
class SafeSpace : public TableController {
public:
	SafeSpace();
	~SafeSpace();
	//�e�[�u����Ɉ��S�n�т𐶐����郁�\�b�h
	void createSafeSpace();
	//���S�n�т̊m�F�����郁�\�b�h
	bool checkSafeSpace(int location);
	//���S�n�т��N���b�N���ꂽ�ہA�אڂ�����S�n�т�\�����郁�\�b�h
	void searchAllSafeSpace(int location);

	//���S�n�т��N���b�N���ꂽ�ہA���S�n�т̍��̃^�C����T�����郁�\�b�h
	void searchLeftSafeSpace(int location);
	//���S�n�т��N���b�N���ꂽ�ہA���S�n�т̉E�̃^�C����T�����郁�\�b�h
	void searchRightSafeSpace(int location);

	//���S�n�т��N���b�N���ꂽ�ہA���S�n�т̏�̃^�C����T�����郁�\�b�h
	void searchOnSafeSpace(int location);
	//���S�n�т��N���b�N���ꂽ�ہA���S�n�т̉��̃^�C����T�����郁�\�b�h
	void searchUnderSafeSpace(int location);

	//���S�n�т��N���b�N���ꂽ�ہA���S�n�т̉E��̃^�C����T�����郁�\�b�h
	void searchRightOnSafeSpace(int location);
	//���S�n�т��N���b�N���ꂽ�ہA���S�n�т̉E���̃^�C����T�����郁�\�b�h
	void searchRightUnderSafeSpace(int location);

	//���S�n�т��N���b�N���ꂽ�ہA���S�n�т̍���̃^�C����T�����郁�\�b�h
	void searchLeftOnSafeSpace(int location);
	//���S�n�т��N���b�N���ꂽ�ہA���S�n�т̍����̃^�C����T�����郁�\�b�h
	void searchLeftUnderSafeSpace(int location);
};

#endif __SAFESPACE_H