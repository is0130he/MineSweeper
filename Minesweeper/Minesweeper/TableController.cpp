#include "TableController.h"

extern Tile *table[];

TableController::TableController(){}


TableController::~TableController(){}
/*
*�@�\�T�v : ��Ƀ^�C�������݂��邩�`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̏�Ƀ^�C�������݂���̂��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : true(���݂���ꍇ), false(���݂��Ȃ��ꍇ)
*/
bool TableController::checkOnTile(int location){
	int check = location / X_MAX;

	//if���̓^�C�������݂��Ȃ��ꍇ���L�q
	if (check == 0) {
		return false;
	}
	return true;
}

/*
*�@�\�T�v : ���Ƀ^�C�������݂��邩�`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̉��Ƀ^�C�������݂���̂��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : true(���݂���ꍇ), false(���݂��Ȃ��ꍇ)
*/

bool TableController::checkUnderTile(int location){
	int check = location / X_MAX;

	//if���̓^�C�������݂��Ȃ��ꍇ���L�q
	if (check == X_MAX - 1 ) {
		return false;
	}
	return true;
}

/*
*�@�\�T�v : �E�Ƀ^�C�������݂��邩�`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̉E�Ƀ^�C�������݂���̂��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : true(���݂���ꍇ), false(���݂��Ȃ��ꍇ)
*/
bool TableController::checkRightTile(int location){
	int check = location % X_MAX;

	//if���̓^�C�������݂��Ȃ��ꍇ���L�q
	if (check == X_MAX - 1) {
		return false;
	}
	return true;
}


/*
*�@�\�T�v : ���Ƀ^�C�������݂��邩�`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̍��Ƀ^�C�������݂���̂��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : true(���݂���ꍇ), false(���݂��Ȃ��ꍇ)
*/

bool TableController::checkLeftTile(int location) {
	int check = location % X_MAX;

	//if���̓^�C�������݂��Ȃ��ꍇ���L�q
	if (check == 0) {
		return false;
	}
	return true;
}

/*
*�@�\�T�v : �E��Ƀ^�C�������݂��邩�`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̉E��Ƀ^�C�������݂���̂��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : true(���݂���ꍇ), false(���݂��Ȃ��ꍇ)
*/

bool TableController::checkRightOnTile(int location){
	bool check;

	//��̕ӂ��`�F�b�N
	check = checkOnTile(location);


	if (check == false) {
		return false;
	}

	//�E�̕ӂ��`�F�b�N
	check = checkRightTile(location);

	if (check == false) {
		return false;
	}
	
	return true;
}

/*
*�@�\�T�v : ����Ƀ^�C�������݂��邩�`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̍���Ƀ^�C�������݂���̂��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : true(���݂���ꍇ), false(���݂��Ȃ��ꍇ)
*/

bool TableController::checkLeftOnTile(int location){
	bool check;

	//��̕ӂ��`�F�b�N
	check = checkOnTile(location);


	if (check == false) {
		return false;
	}

	//���̕ӂ��`�F�b�N
	check = checkLeftTile(location);

	if (check == false) {
		return false;
	}

	return true;
}
/*
*�@�\�T�v : �E���Ƀ^�C�������݂��邩�`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̉E���Ƀ^�C�������݂���̂��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : true(���݂���ꍇ), false(���݂��Ȃ��ꍇ)
*/

bool TableController::checkRightUnderTile(int location){
	bool check;

	//���̕ӂ��`�F�b�N
	check = checkUnderTile(location);


	if (check == false) {
		return false;
	}

	//�E�̕ӂ��`�F�b�N
	check = checkRightTile(location);

	if (check == false) {
		return false;
	}

	return true;
}
/*
*�@�\�T�v : �����Ƀ^�C�������݂��邩�`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̍����Ƀ^�C�������݂���̂��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : true(���݂���ꍇ), false(���݂��Ȃ��ꍇ)
*/

bool TableController::checkLeftUnderTile(int location){
	bool check;

	//���̕ӂ��`�F�b�N
	check = checkUnderTile(location);


	if (check == false) {
		return false;
	}

	//���̕ӂ��`�F�b�N
	check = checkLeftTile(location);

	if (check == false) {
		return false;
	}

	return true;
}


/*
*�@�\�T�v : ���͂Ƀ^�C�������݂��邩�`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̎��͂Ƀ^�C�������݂���̂��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : true(���݂���ꍇ), false(���݂��Ȃ��ꍇ)
*/

bool TableController::checkAroundTile(int location, bool *check){

	//��̃^�C�����`�F�b�N
	*(check++) = checkOnTile(location);
	//���̃^�C�����`�F�b�N
	*(check++) = checkUnderTile(location);
	//�E�̃^�C�����`�F�b�N
	*(check++) = checkRightTile(location);
	//���̃^�C�����`�F�b�N
	*(check++) = checkLeftTile(location);
	
	//�E��̃^�C�����`�F�b�N
	*(check++) = checkRightOnTile(location);
	//����̃^�C�����`�F�b�N
	*(check++) = checkLeftOnTile(location);
	//�E���̃^�C�����`�F�b�N
	*(check++) = checkRightUnderTile(location);
	//�����̃^�C�����`�F�b�N
	*(check++) = checkLeftUnderTile(location);

	return true;
}

/*
*�@�\�T�v : ��̃^�C���̏�Ԃ��`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̏�̏�Ԃ��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : ret(�w�肵���^�C���̏�̏��)
*/
tile_status TableController::checkOnStatus(int location){
	tile_status ret = table[location - X_MAX] -> getStatus();

	return ret;
}

/*
*�@�\�T�v : ���̃^�C���̏�Ԃ��`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̉��̏�Ԃ��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : ret(�w�肵���^�C���̉��̏��)
*/
tile_status TableController::checkUnderStatus(int location){

	tile_status ret = table[location + X_MAX]->getStatus();

	return ret;
}

/*
*�@�\�T�v : �E�̃^�C���̏�Ԃ��`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̉E�̏�Ԃ��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : ret(�w�肵���^�C���̉E�̏��)
*/
tile_status TableController::checkRightStatus(int location){

	tile_status ret = table[location + 1]->getStatus();

	return ret;
}

/*
*�@�\�T�v : ���̃^�C���̏�Ԃ��`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̍��̏�Ԃ��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : ret(�w�肵���^�C���̍��̏��)
*/

tile_status TableController::checkLeftStatus(int location){

	tile_status ret = table[location - 1]->getStatus();

	return ret;
}

/*
*�@�\�T�v : �E��̃^�C���̏�Ԃ��`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̉E��̏�Ԃ��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : ret(�w�肵���^�C���̉E��̏��)
*/

tile_status TableController::checkRightOnStatus(int location){

	tile_status ret = table[location -X_MAX + 1]->getStatus();

	return ret;
}

/*
*�@�\�T�v : ����̃^�C���̏�Ԃ��`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̍���̏�Ԃ��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : ret(�w�肵���^�C���̍���̏��)
*/

tile_status TableController::checkLeftOnStatus(int location){

	tile_status ret = table[location - X_MAX - 1]->getStatus();

	return ret;
}

/*
*�@�\�T�v : �E���̃^�C���̏�Ԃ��`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̉E���̏�Ԃ��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : ret(�w�肵���^�C���̉E���̏��)
*/

tile_status TableController::checkRightUnderStatus(int location){

	tile_status ret = table[location + X_MAX + 1]->getStatus();

	return ret;
}

/*
*�@�\�T�v : �����̃^�C���̏�Ԃ��`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̍����̏�Ԃ��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@return : ret(�w�肵���^�C���̍����̏��)
*/

tile_status TableController::checkLeftUnderStatus(int location){

	tile_status ret = table[location + X_MAX - 1]->getStatus();

	return ret;
}
/*
*�@�\�T�v : �S�����̃^�C���̏�Ԃ��`�F�b�N
*�@�\�ڍ� : �w�肵���^�C���̑S�����̏�Ԃ��`�F�b�N
*@author : �����@��
*@version : 1
*@param : location(��ƂȂ�^�C���̈ʒu)
*@param : check(�Ԃ��ׂ��l����͂���f�[�^)
*@return : �Ȃ�(check)
*/

void TableController::checkAroundStatus(int location, tile_status check[8]){
	
	//��̃^�C���̏�Ԃ��擾
	*(check++) = checkOnStatus(location);
	//���̃^�C���̏�Ԃ��擾
	*(check++) = checkUnderStatus(location);
	//�E�̃^�C���̏�Ԃ��擾
	*(check++) = checkRightStatus(location);
	//���̃^�C���̏�Ԃ��擾
	*(check++) = checkLeftStatus(location);
	
	//�E��̃^�C���̏�Ԃ��擾
	*(check++) = checkRightOnStatus(location);
	//����̃^�C���̏�Ԃ��擾
	*(check++) = checkLeftOnStatus(location);
	//�E���̃^�C���̏�Ԃ��擾
	*(check++) = checkRightUnderStatus(location);
	//�����̃^�C���̏�Ԃ��擾
	*(check++) = checkLeftUnderStatus(location);
}

int TableController::checkFlagNumber(){
	//�J�E���^�ϐ�
	int i;
	//���̏�ԃ`�F�b�N
	bool flag_check;
	//���̐����J�E���g
	int count = 0;
	for (i = 0;i < X_MAX *Y_MAX;i++) {
		flag_check = table[i]->getFlag();
		if (flag_check == true) {
			count++;
		}
	}
	return count;
}

