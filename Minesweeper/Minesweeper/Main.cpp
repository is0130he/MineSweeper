//�e�[�u���֘A�̏������s���֐����K�{
#include"Tile.h"
#include"PlayMode.h"

/*
*�@�\�T�v : ���C���֐�
*�@�\�ڍ� : DX���C�u�����̋N���ƏI��
*@author : �����@��
*@version : 1
*@param : ����(�ڍוs��)
*@return : �Ȃ�
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�C���X�^���X�����p
	PlayMode *play;
	play = new PlayMode();

	play->mainRoutine();
	//�L�[���͑҂�(���[�U�̔F���҂�)
	WaitKey();
	//DX���C�u�����̏I��
	DxLib_End();
	//�������J��
	return 0;
}
