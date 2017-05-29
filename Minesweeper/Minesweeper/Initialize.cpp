#include "Initialize.h"
#include "DxLib.h"

Initialize::Initialize(){}
Initialize::~Initialize(){}

/*
*�@�\�T�v : ����������
*�@�\�ڍ� : DX���C�u�����ɂ����鏉��������
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : �Ȃ�
*/
void Initialize::startUp(){
	/*DX���C�u�����Ɋ֘A���鏈��*/

	//�E�B���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1){		// �c�w���C�u��������������
		DxLib_End();				// �c�w���C�u�����g�p�̏I������
		exit(0);			// �G���[���N�����璼���ɏI��
	}
	//����ʏ���
	SetDrawScreen(DX_SCREEN_BACK);
	//�w�i�𔒂�
	SetBackgroundColor(255, 255, 255);
}

/*
*�@�\�T�v : �摜�o�͌�̌㏈��
*�@�\�ڍ� : �摜�o�͌�ɉ�ʃN���A�◠��ʕ\���Ȃǂ����s
*@author : �����@��
*@version : 1
*@param : *tile (�e�[�u�����)
*@return : �Ȃ�
*/

void Initialize::backGraund(){
	//����ʂ�\��ʂɔ��f
	ScreenFlip();
	//��ʃN���A
	ClearDrawScreen();
	//���b�Z�[�W����
	ProcessMessage();
}
