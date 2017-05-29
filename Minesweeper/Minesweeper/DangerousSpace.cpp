#include "DangerousSpace.h"

extern Tile *table[];

DangerousSpace::DangerousSpace(){}


DangerousSpace::~DangerousSpace(){}
/*
*�@�\�T�v : ���͂̔��e�̌����m�F
*�@�\�ڍ� : �Ώۂ̃^�C���ɑ΂��Ď��͂̔��e�̌����m�F
*@author : �����@��
*@version : 1
*@param : *tile (�^�C���̉摜���̔z��)
*@param : location(�m�F�Ώۂ̈ʒu)
*@return : bomb_number(�w��^�C�����ӂɂ����锚�e�̌�)
*/

int DangerousSpace::checkBombNumber(int location){
	//�^�C�������݂��邩�`�F�b�N

	bool check[8] = { false };
	//�S�Ẵ^�C�������݂��邩�`�F�b�N
	//bool ret = false;
	//���͂̃^�C���̏�Ԋm�F
	tile_status check_status[8], bomb_judge;
	//���͂̔��e�̐�
	int bomb_number = 0;
	//�J�E���^�ϐ�
	int i;

	//�w��^�C���ɔ��e�����邩�m�F
	bomb_judge = table[location]->getStatus();
	//�w��̃^�C���ɔ��e������΁A�댯�n�тłȂ�
	if (bomb_judge == bomb) {
		return 0;
	}

	//���\�b�h�Ăяo���̂��߂ɐ���
	TableController *dummy;
	dummy  = new TableController();

	//�^�C���̑��݂��`�F�b�N
	dummy->checkAroundTile(location, check);
	
	getAroundStatus(location, check, check_status);

	//���e�̐����J�E���g
	for (i = 0;i < 8;i++) {
		if (check_status[i] == bomb) {
			bomb_number++;
		}
	}
		return bomb_number;
}


/*
*�@�\�T�v : �^�C���̎���̏�Ԃ��擾
*�@�\�ڍ� : �^�C���̎���̏��(��A���A�E�A���A�E��A�E���A����A����)���擾���A�Q�Ɠn���Ō��ʂ�Ԃ����\�b�h
*@author : �����@��
*@version : 1
*@param : *tile (�e�[�u�����)
*@param : location(���S�ƂȂ�^�C���̈ʒu)
*@param  : *check(���͂̃^�C���̗L�����i�[����Ă���z��)
*@param : *check_status(���͂̃^�C���̏�Ԃ��i�[����z��)
*@return : �Ȃ�(�Ԃ��Ă��炢�������̂�*check_status�̒��g)
*/

void DangerousSpace::getAroundStatus(int location, bool * check, tile_status * check_status){
	TableController *dummy;
	dummy = new TableController();
	
	//��Ƀ^�C�������݂���ꍇ
	if (check[ON] == true) {
		check_status[ON] = dummy->checkOnStatus(location);
	}

	//���̃^�C�������݂���ꍇ
	if (check[UNDER] == true) {
		check_status[UNDER] = dummy->checkUnderStatus(location);
	}

	//�E�̃^�C�������݂���ꍇ
	if (check[RIGHT] == true) {
		check_status[RIGHT] = dummy->checkRightStatus(location);
	}

	//���̃^�C�������݂���ꍇ
	if (check[LEFT] == true) {
		check_status[LEFT] = dummy->checkLeftStatus(location);
	}

	//�E��̃^�C�������݂���ꍇ
	if (check[RIGHT_ON] == true) {
		check_status[RIGHT_ON] = dummy->checkRightOnStatus(location);
	}

	//����̃^�C�������݂���ꍇ
	if (check[LEFT_ON] == true) {
		check_status[LEFT_ON] = dummy->checkLeftOnStatus(location);
	}

	//�E���̃^�C�������݂���ꍇ
	if (check[RIGHT_UNDER] == true) {
		check_status[RIGHT_UNDER] = dummy->checkRightUnderStatus(location);
	}

	//�����̃^�C�������݂���ꍇ
	if (check[LEFT_UNDER] == true) {
		check_status[LEFT_UNDER] = dummy->checkLeftUnderStatus(location);
	}
}


//�댯�n�т̏�Ԃ��Z�b�g���郁�\�b�h
/*
*�@�\�T�v : �댯�n�т̏�Ԃ��Z�b�g���郁�\�b�h
*�@�\�ڍ� : �^�C���̎���̔��e�����擾���A�e�[�u���ɃZ�b�g
*@author : �����@��
*@version : 1
*@param : *tile (�e�[�u�����)
*@return : �Ȃ�
*/
void DangerousSpace::createDangerousSpace(){
	
	//�J�E���^�ϐ�
	int i, j;
	//���e�̐�
	int bomb_number = 0;
	//�^�C���̏��
	tile_status status;

	//��Ԃ��Z�b�g
	for (j = 0;j < Y_MAX;j++) {
		for (i = 0;i < X_MAX; i++) {
			//���͂̔��e�̌����擾
			bomb_number = checkBombNumber(X_MAX * j + i);
			
			//���e������ꍇ (�Ȃ��ꍇ�͉������Ȃ�)
			if (bomb_number > 0) {
					status = convertBombNumber(bomb_number);
					table[X_MAX * j + i]->setStatus(status);
			}
		}
	}

}

/*
*�@�\�T�v : ���e������tile_status�^�ɕϊ�
*�@�\�ڍ� : tile_status��enum�^�ł��邽�߁A�l�̕ϊ������s
*@author : �����@��
*@version : 1
*@param : bomb_number(���e��)
*@return : tile_status�^�ւ̕ϊ�����(�� : 1��one)
*/

tile_status DangerousSpace::convertBombNumber(int bomb_number){
	
	if (bomb_number == 1) {
		return one;
	}
	else if (bomb_number == 2) {
		return two;
	}
	else if (bomb_number == 3) {
		return three;
	}
	else if (bomb_number == 4) {
		return four;
	}
	else if (bomb_number == 5) {
		return five;
	}
	else if (bomb_number == 6) {
		return six;
	}
	else if (bomb_number == 7) {
		return seven;
	}
	else if (bomb_number == 8) {
		return eight;
		}
			//�\���`�F�b�N�\�t�g�p�̑΍�
	else {
			return nothing;
		}
	}