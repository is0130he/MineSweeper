#include "PlayMode.h"

//��������e�[�u��
Tile *table[X_MAX * Y_MAX];
//�^�C���֘A�̉摜
int tile_graph[12];

//�R���X�g���N�^
PlayMode::PlayMode(){}
PlayMode::~PlayMode(){}

/*
*�@�\�T�v : �^�C���̉摜�����[�h
*�@�\�ڍ� : �^�C���̉摜�����ꂼ��̔z��Ƀ��[�h
*@author : �����@��
*@version : 1
*@param : *tile (�^�C���̉摜���̔z��)
*@return : �Ȃ�
*/
void PlayMode::loadTileGraphics(int * tile){
	//�摜�����[�h
	//�^�C��(������Ԃ̉摜)
	tile[0] = LoadGraph("Tile0.png");
	//�^�C��(�댯�n�т̉摜) ���ԍ��͎���̔��e�̐�
	tile[1] = LoadGraph("Tile1.png");
	tile[2] = LoadGraph("Tile2.png");
	tile[3] = LoadGraph("Tile3.png");
	tile[4] = LoadGraph("Tile4.png");
	tile[5] = LoadGraph("Tile5.png");
	tile[6] = LoadGraph("Tile6.png");
	tile[7] = LoadGraph("Tile7.png");
	tile[8] = LoadGraph("Tile8.png");
	//���e
	tile[9] = LoadGraph("Bomb.png");
	//���S�n��
	tile[10] = LoadGraph("SafeSpace.png");
	//��
	tile[11] = LoadGraph("Flag.png");
}

//�e�[�u���𐶐����郁�\�b�h
/*
*�@�\�T�v : �e�[�u���𐶐����郁�\�b�h
*�@�\�ڍ� : �쐬�����e�[�u���ɓ��I�������m��
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : �Ȃ�
*/

void PlayMode::createTable(void){
	//�^�C�����o�͂�����ʒu(�����l��(0,0)�̈ʒu)
	int start_x = BEGIN_X, start_y = BEGIN_Y;
	double size = 0.25;
	int i, j;
	//�^�C���̊Ԋu
	int interval = 25;

	//���\�b�h�����p�̃C���X�^���X
	Bomb *dummy;
	dummy = new Bomb();
	DangerousSpace *dummy2;
	dummy2 = new DangerousSpace();
	SafeSpace *dummy3;
	dummy3 = new SafeSpace();
	MouseListener * dummy4;
	dummy4 = new MouseListener();

	//�^�C���̐���
	for (j = 0;j < Y_MAX;j++, start_y += TILE_INTERVAL) {
		for (i = 0;i < X_MAX; i++, start_x += TILE_INTERVAL) {
			table[X_MAX * j + i] = new Tile(start_x, start_y, false, nothing, false);
		}
		//x���W�����ɖ߂�
		start_x = 200;
	}

	//�Վ��p
	//���e����
	dummy->createBomb();
	//�댯�n�ѐݒ�
	dummy2->createDangerousSpace();
	//���S�n�ѐݒ�
	dummy3->createSafeSpace();
}

/*
*�@�\�T�v : ���C�����[�`��
*�@�\�ڍ� : ��ȏ������s�����\�b�h(�قƂ�ǂ̏�������������X�^�[�g����)
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : �Ȃ�
*/

void PlayMode::mainRoutine(){
	//���\�b�h�Ăяo���p�̃C���X�^���X����
	MouseListener * dummy5;
	dummy5 = new MouseListener();
	Initialize * dummy6;
	dummy6 = new Initialize();
	PlayMode *dummy7;
	dummy7 = new PlayMode();
	GameOver *dummy8;
	dummy8 = new GameOver();
	GameClear *dummy9;
	dummy9 = new GameClear();
	//�I���t���O(0:�Ȃ�,1:game vlear, 2:game over)
	int end_flag = 0;
	//�����ݒ���s��
	dummy6->startUp();
	//�摜�f�[�^�����[�h
	dummy7->loadTileGraphics(tile_graph);
	//�e�[�u���𐶐�
	dummy7->createTable();


	//ESC�����͂����܂Ŏ��s
	while (CheckHitKey(KEY_INPUT_ESCAPE) != 1) {
		//�^�C�����o��
		table[0]->dispAll();
		//�}�E�X�֘A�̏���
		dummy5->inputMousePointer();
		
		//�Q�[���N���A������
		end_flag = dummy9->checkGameClear();
		//�Q�[���N���A�̏ꍇ
		if (end_flag == 1) {
			//�Q�[���N���A����
			dummy9->gameClearEnd();
			break;
		}
		//�Q�[���I�[�o�[������
		end_flag = dummy8->checkGameOver();
		//�Q�[���I�[�o�[�̏ꍇ
		if (end_flag == 2) {
			//�Q�[���I�[�o�[�����́A���ʂ̎����UserInterface��
			break;
		}
		//�ꎞ�I�Ɍ��Ɉړ�
		dummy6->backGraund();
	}
}
