#include "SafeSpace.h"

extern Tile *table[];

SafeSpace::SafeSpace(){
}


SafeSpace::~SafeSpace(){
}
/*
*�@�\�T�v : ���S�n�т𐶐�
*�@�\�ڍ� : ���e�̂��鏊�Ɗ댯�n�т̂���Ƃ���ȊO�Ɉ��S�n�т��Z�b�g
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : �Ȃ�
*/
void SafeSpace::createSafeSpace(){
	//�J�E���^�ϐ�
	int i, j;
	//�댯�n�сE���e�̊m�F
	bool check;
	
	//��Ԃ��Z�b�g
	for (j = 0;j < Y_MAX;j++) {
		for (i = 0;i < X_MAX; i++) {
			//�댯�n�сE���e�̊m�F
			check = checkSafeSpace(X_MAX * j + i);
			//���S�n�т̍쐬
			if (check == true) {
				table[X_MAX * j + i] -> setStatus(safespace);
			}
		}
	}
}
/*
*�@�\�T�v : ���S�n�тł��邩�`�F�b�N
*�@�\�ڍ� : status��nothing�ł��邩���m�F
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : true(nothing), false(nothing����Ȃ�)
*/
bool SafeSpace::checkSafeSpace(int location){
	tile_status check;
	check = table[location]->getStatus();
	if (check != 0) {
		return false;
	}
	return true;
}

/*
*�@�\�T�v : ���S�n�т��N���b�N���ꂽ�ہA�אڂ�����S�n�т�\�����郁�\�b�h
*�@�\�ڍ� : ���S�n�т��N���b�N���ꂽ�ہA�אڂ�����S�n�т���C�ɕ\��
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : �Ȃ�
*/
void SafeSpace::searchAllSafeSpace(int location){
	//�e�[�u���N���X�Ăяo���p
	TableController *dummy;
	dummy = new TableController();
	//�����玞�v���ɒT��
	
	//��
	if (dummy->checkLeftTile(location) == true) {
		searchLeftSafeSpace(location);
	}
	//����
	if (dummy->checkLeftOnTile(location) == true) {
		searchLeftOnSafeSpace(location);
	}
	//��
	if (dummy->checkOnTile(location) == true) {
		searchOnSafeSpace(location);
	}
	//�E��
	if (dummy->checkRightOnTile(location) == true) {
		searchRightOnSafeSpace(location);
	}
	//�E
	if (dummy->checkRightTile(location) == true) {
		searchRightSafeSpace(location);
	}
	//�E��
	if (dummy->checkRightUnderTile(location) == true) {
		searchRightUnderSafeSpace(location);
	}
	//��
	if (dummy->checkUnderTile(location) == true) {
		searchUnderSafeSpace(location);
	}
	//����
	if (dummy->checkLeftUnderTile(location) == true) {
		searchLeftUnderSafeSpace(location);
	}
}

/*
*�@�\�T�v : ���Ɉ��S�n�т�����̂��[���D��T��
*�@�\�ڍ� : ���Ɉ��S�n�т�����̂��[���D��T�����A����΍ċN
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : �Ȃ�
*/
void SafeSpace::searchLeftSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//�ꏊ�����ɐݒ�
	location--;

	//���S�n�т̊m�F
	if (table[location]->getStatus() == safespace) {

		//�J������Ă���^�C���̊m�F
		if (table[location]->getOpen() == true);

		//�^�C�����J������Ă��炸,���Ƀ^�C�������݂���ꍇ
		else {
			//�^�C�����J��
			table[location]->setOpen(true);
			//�ċN
			searchAllSafeSpace(location);
		}
	}
	//���e�̏ꍇ
	//�������Ȃ�
	else if (table[location]->getStatus() == bomb);
	//�댯�n�т̏ꍇ
	else{
		//�^�C�����J��
		table[location]->setOpen(true);
	}
}

/*
*�@�\�T�v : �E�Ɉ��S�n�т�����̂��[���D��T��
*�@�\�ڍ� : �E�Ɉ��S�n�т�����̂��[���D��T�����A����΍ċN
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : �Ȃ�
*/
void SafeSpace::searchRightSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//�ꏊ���E�ɐݒ�
	location++;

	//���S�n�т̊m�F
	if (table[location]->getStatus() == safespace) {
		//�J������Ă���^�C���̊m�F
		if (table[location]->getOpen() == true);
		//�T�����p������ꍇ
		else {
			//�^�C�����J��
			table[location]->setOpen(true);
			//�ċN
			searchAllSafeSpace(location);
		}
	}
	//���e�̏ꍇ,�������Ȃ�
	else if (table[location]->getStatus() == bomb);

	//�댯�n�т̏ꍇ
	else {
		//�^�C�����J��
		table[location]->setOpen(true);
	}
}
/*
*�@�\�T�v : ��Ɉ��S�n�т�����̂��[���D��T��
*�@�\�ڍ� : ��Ɉ��S�n�т�����̂��[���D��T�����A����΍ċN
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : �Ȃ�
*/
void SafeSpace::searchOnSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//�ꏊ����ɐݒ�
	location -= X_MAX;

	//���S�n�т̊m�F
	if (table[location]->getStatus() == safespace) {
		//�J������Ă���^�C���̊m�F
		if (table[location]->getOpen() == true);
		//�T�����p������ꍇ
		else {
			//�^�C�����J��
			table[location]->setOpen(true);
			//�ċN
			searchAllSafeSpace(location);
		}
	}
	//���e�̏ꍇ
	else if (table[location]->getStatus() == bomb);
	//�댯�n�т̏ꍇ
	else {
		//�^�C�����J��
		table[location]->setOpen(true);
	}
}
/*
*�@�\�T�v : ���Ɉ��S�n�т�����̂��[���D��T��
*�@�\�ڍ� : ���Ɉ��S�n�т�����̂��[���D��T�����A����΍ċN
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : �Ȃ�
*/
void SafeSpace::searchUnderSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//�ꏊ�����ɐݒ�
	location += X_MAX;

	//���S�n�т̊m�F
	if (table[location]->getStatus() == safespace) {

		//�J������Ă���^�C���̊m�F
		if (table[location]->getOpen() == true);
		//�T�����p������ꍇ
		else {
			//�^�C�����J��
			table[location]->setOpen(true);
			//�ċN
			searchAllSafeSpace(location);
		}
	}
	//���e�̏ꍇ
	else if (table[location]->getStatus() == bomb);
	//�댯�n�т̏ꍇ
	else {
		//�^�C�����J��
		table[location]->setOpen(true);
	}
}
/*
*�@�\�T�v : �E��Ɉ��S�n�т�����̂��[���D��T��
*�@�\�ڍ� : �E��Ɉ��S�n�т�����̂��[���D��T�����A����΍ċN
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : �Ȃ�
*/
void SafeSpace::searchRightOnSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//�ꏊ���E��ɐݒ�
	location = location - X_MAX + 1;

	//���S�n�т̊m�F
	if (table[location]->getStatus() == safespace) {

		//�J������Ă���^�C���̊m�F
		if (table[location]->getOpen() == true);
		//�T�����p������ꍇ
		else {
			//�^�C�����J��
			table[location]->setOpen(true);
			//�ċN
			searchAllSafeSpace(location);
		}
	}
	//���e�̏ꍇ
	else if (table[location]->getStatus() == bomb);
	//�댯�n�т̏ꍇ
	else {
		//�^�C�����J��
		table[location]->setOpen(true);
	}
}
/*
*�@�\�T�v : �E���Ɉ��S�n�т�����̂��[���D��T��
*�@�\�ڍ� : �E���Ɉ��S�n�т�����̂��[���D��T�����A����΍ċN
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : �Ȃ�
*/
void SafeSpace::searchRightUnderSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//�ꏊ���E���ɐݒ�
	location = location + X_MAX + 1;

	//���S�n�т̊m�F
	if (table[location]->getStatus() == safespace) {

		//�J������Ă���^�C���̊m�F
		if (table[location]->getOpen() == true);
		//�T�����p������ꍇ
		else {
			//�^�C�����J��
			table[location]->setOpen(true);
			//�ċN
			searchAllSafeSpace(location);
		}
	}
	//���e�̏ꍇ
	else if (table[location]->getStatus() == bomb);
	//�댯�n�т̏ꍇ
	else {
		//�^�C�����J��
		table[location]->setOpen(true);
	}
}
/*
*�@�\�T�v : ����Ɉ��S�n�т�����̂��[���D��T��
*�@�\�ڍ� : ����Ɉ��S�n�т�����̂��[���D��T�����A����΍ċN
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : �Ȃ�
*/
void SafeSpace::searchLeftOnSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//�ꏊ������ɐݒ�
	location = location - X_MAX - 1;

	//���S�n�т̊m�F
	if (table[location]->getStatus() == safespace) {
		//�J������Ă���^�C���̊m�F
		if (table[location]->getOpen() == true);
		//�T�����p������ꍇ
		else {
			//�^�C�����J��
			table[location]->setOpen(true);
			//�ċN
			searchAllSafeSpace(location);
		}
	}
	//���e�̏ꍇ,�������Ȃ�
	else if (table[location]->getStatus() == bomb);
	//�댯�n�т̏ꍇ
	else {
		//�^�C�����J��
		table[location]->setOpen(true);
	}
}
/*
*�@�\�T�v : �����Ɉ��S�n�т�����̂��[���D��T��
*�@�\�ڍ� : �����Ɉ��S�n�т�����̂��[���D��T�����A����΍ċN
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : �Ȃ�
*/
void SafeSpace::searchLeftUnderSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	
	//�ꏊ�������ɐݒ�
	location = location + X_MAX - 1;

	//���S�n�т̊m�F
	if (table[location]->getStatus() == safespace) {

		//�J������Ă���^�C���̊m�F
		if (table[location]->getOpen() == true);

		//�T�����p������ꍇ
		else {
			//�^�C�����J��
			table[location]->setOpen(true);
			searchAllSafeSpace(location);
		}
	}
	//���e�̏ꍇ�A�������Ȃ�
	else if (table[location]->getStatus() == bomb);
	//�댯�n�т̏ꍇ
	else {
		//�^�C�����J��
		table[location]->setOpen(true);
	}
}

