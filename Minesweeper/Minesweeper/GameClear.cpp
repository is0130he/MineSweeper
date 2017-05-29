#include "GameClear.h"

extern Tile *table[];

GameClear::GameClear(){}


GameClear::~GameClear(){}

//�Q�[���N���A�𔻒肷�郁�\�b�h
/*
*�@�\�T�v : �Q�[���N���A�𔻒肷�郁�\�b�h
*�@�\�ڍ� : �e�[�u���ɂ����Ĕ��e�����^�C�����������ׂẴ^�C�����J������Ă���(�N���A���Ă���)���m�F
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : 1(�Q�[���N���A)�A0(�Q�[���N���A�Ȃ炸)
*/

int GameClear::checkGameClear(){
	//�J�E���^�ϐ�
	int i, open_count = X_MAX * Y_MAX - BOMB_NUMBER;
	//�^�C���̏�Ԃ��擾����ϐ�
	tile_status status;
	//�^�C���̊J���擾����ϐ�
	bool open;
	//�J������Ă���^�C����(�^�C���̐�) - (���e�̐�)���邩�m�F
	for (i = 0;i < (X_MAX * Y_MAX);i++) {
		//�^�C���̏�Ԃ��m�F
		status = table[i]->getStatus();
		//�^�C���̊J���擾
		open = table[i]->getOpen();
		//�^�C���̒��g�����e�łȂ��ꍇ
		if (status != bomb) {
			//�^�C�����J������Ă���ꍇ
			if (open == true) {
				//�J�E���g
				open_count--;
			}
		}
	}
	//�N���A�Ȃ炸
	if (open_count > 0) {
		return 0;
	}
	//�N���A
	return 1;
}
/*
*�@�\�T�v : �Q�[���N���A����
*�@�\�ڍ� : �Q�[���N���A�摜���o��
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : �Ȃ�
*/
void GameClear::gameClearEnd(){
	
	//�摜�����[�h
	int gameclear_graphic = LoadGraph("game_clear.png");

	//��ʂ��N���A
	ClearDrawScreen();
	//�Q�[���N���A��ʂ��o��
	DrawGraph(0, 0, gameclear_graphic, FALSE);
	ScreenFlip();
	//���b�Z�[�W����
	ProcessMessage();
}