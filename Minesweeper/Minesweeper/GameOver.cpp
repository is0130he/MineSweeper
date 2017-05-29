#include "GameOver.h"

#include"DxLib.h"

extern Tile *table[];

GameOver::GameOver(){}
GameOver::~GameOver(){}

/*
*�@�\�T�v : �Q�[���I�[�o�[����
*�@�\�ڍ� : �Q�[���I�[�o�[�摜���o��
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : �Ȃ�
*/
void GameOver::gameOverEnd(int location){

	//�摜�����[�h
	int gameover_graphic = LoadGraph("game_over.png");
	//3�b��(���e��)�\��
	WaitTimer(3000);
	//��ʂ��N���A
	ClearDrawScreen();
	
	//�Q�[���I�[�o�[��ʂ��o��
	DrawGraph(0, 0, gameover_graphic, FALSE);
	ScreenFlip();
	//���b�Z�[�W����
	ProcessMessage();
}
/*
*�@�\�T�v : �Q�[���I�[�o�[���m�F
*�@�\�ڍ� : �e�[�u����ɂ����Ĕ��e�������J������Ă���^�C�������݂���(�Q�[���I�[�o�[�ƂȂ��Ă���)���m�F
*@author : �����@��
*@version : 1
*@param : *tile (�e�[�u�����)
*@return : 2(�Q�[���I�[�o�[), 0(�Q�[���I�[�o�[�Ȃ炸)
*/

int GameOver::checkGameOver(){
	//�J�E���^�ϐ�
	int i;
	//�^�C���̏�Ԃ��擾����ϐ�
	tile_status status;
	//�^�C���̊J���擾����ϐ�
	bool open;
	for (i = 0;i < (X_MAX * Y_MAX);i++) {
		//�^�C���̏�Ԃ��m�F
		status = table[i]->getStatus();
		//�^�C���̊J���擾
		open = table[i]->getOpen();
		//�^�C���̒��g�����e�̏ꍇ
		if (status == bomb) {
			//�^�C�����J������Ă���ꍇ
			if (open == true) {
				//�Q�[���I�[�o�[
				return 2;
			}
		}
	}
	//���Ȃ�
	return 0;
}
