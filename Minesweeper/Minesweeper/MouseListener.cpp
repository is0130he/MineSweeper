#include "MouseListener.h"
//#if DEBUG

extern Tile *table[];

MouseListener::MouseListener(){}


MouseListener::~MouseListener(){}

/*
*�@�\�T�v : �f�[�^�̎󂯓n�����s�����\�b�h
*�@�\�ڍ� : �}�E�X�o�R�Ŏ擾�����e�[�u���̈ʒu���W��z��ɍ��킹���`�ŕϊ�
*@author : �����@��
*@version : 1
*@param : x(x���W)
*@param : y(y���W)
*@return : �e�[�u���̍��W(�z��p)
*/
int MouseListener::convertTileCoordinates(int x, int y){
	//�߂�l
	int ans = 0;

	//���������W�ł��邩����p�̕ϐ�
	bool judge_coordinate = checkMousePointer(x,y);

	//���炩�ɐ������Ȃ����W�ł����false
	if (judge_coordinate == false) {
		return -1;
	}

	//�����l���猴�_�ɖ߂�
	x -= (BEGIN_X - GRAPHIC_GAP);
	y -= (BEGIN_Y - GRAPHIC_GAP);

	//�����l���牡�ɂ����炸��Ă邩�m�F
	x /= TILE_INTERVAL;

	//�����l����c�ɂ����炸��Ă��邩�m�F
	y /= TILE_INTERVAL;

	ans = X_MAX * y + x;

	//�z��̒l�ɕϊ�
	return ans;
}
/*
*�@�\�T�v : ���𗧂Ă��������肷�郁�\�b�h
*�@�\�ڍ� : ��������Ύ�菜���A�����Ȃ���Ί����Z�b�g���邽�߂̃��\�b�h
*@author : �����@��
*@version : 1
*@param : location(�w����W)
*@return : �Ȃ�
*/
void MouseListener::flagTile(int location){
	bool flag;

	flag = table[location] -> getFlag();
	
	//�������łɗ����Ă���ꍇ
	if (flag == true) {
		table[location]->setFlag(false);
	}
	else {
		table[location]->setFlag(true);
	}
}
/*
*�@�\�T�v : �}�E�X�|�C���^���e�[�u����ɂ��邩�m�F���郁�\�b�h
*�@�\�ڍ� : GUI��ɂ����ă}�E�X�|�C���^���e�[�u����ɂ���̂��m�F
*@author : �����@��
*@version : 1
*@param : x(x���W)
*@param : y(y���W)
*@return : true(�e�[�u����ɂ���ꍇ), false(�e�[�u����ɂȂ��ꍇ)
*/
bool MouseListener::checkMousePointer(int x, int y) {
	//x���W���e�[�u����ɂȂ��ꍇ
	//���[������
	if (x < (BEGIN_X - GRAPHIC_GAP)) {
		return false;
	}

	//�E�[�����E
	//GUI�𔽉f�����邽�߂Ɏ��������Ȃ������A�ł���ΏC��������
	else if (x >(BEGIN_X + TILE_INTERVAL * (X_MAX - 1) + GRAPHIC_GAP - 1)) {
		return false;
	}

	//y���W���e�[�u����ɂȂ��ꍇ
	//��ԏ������
	else if (y < (BEGIN_Y - GRAPHIC_GAP)) {
		return false;
	}

	//��ԉ�������
	//GUI�𔽉f�����邽�߂Ɏ��������Ȃ������A�ł���ΏC��������
	else if (y > (BEGIN_Y + TILE_INTERVAL * (Y_MAX - 1) + GRAPHIC_GAP - 1)) {
		return false;
	}

	//�Ō�܂ŃK�[�h���p�X���Ȃ����true
	return true;
}
/*
*�@�\�T�v : ���N���b�N�����s�����ۂ̋@�\
*�@�\�ڍ� : ���N���b�N���s�����ۂ̋@�\
*@author : �����@��
*@version : 1
*@param : location(�e�[�u����̎w����W)
*@return : �Ȃ�
*/

void MouseListener::inputLeftClick(int mouse_location){
	//���\�b�h����
	SafeSpace *dummy3;
	dummy3 = new SafeSpace();
	GameOver *gameover;
	gameover = new GameOver();

	//���S�n�т̏ꍇ
	if (table[mouse_location]->getStatus() == safespace) {
		//���̈��S�n�т��J��
		table[mouse_location]->setOpen(true);
		dummy3->searchAllSafeSpace(mouse_location);
	}
	//���e�̏ꍇ
	else if (table[mouse_location]->getStatus() == bomb) {
		table[mouse_location]->setOpen(true);
		//�e�[�u���o��
		dispAll();
		ScreenFlip();
		//���b�Z�[�W����
		ProcessMessage();
		//�Q�[���I�[�o�[
		gameover->gameOverEnd(mouse_location);
	}
	//�댯�n�т̏ꍇ
	else {
		//���̃^�C�����J���邾��
		table[mouse_location]->setOpen(true);
	}
}
/*
*�@�\�T�v : �E�N���b�N���s�����ۂ̋@�\
*�@�\�ڍ� : �E�N���b�N���s�����ۂ̋@�\
*@author : �����@��
*@version : 1
*@param : location(�e�[�u����̎w����W)
*@return : �Ȃ�
*/
void MouseListener::inputRightClick(int mouse_location){
	MouseListener *dummy;
	dummy = new MouseListener();

	//�^�C�����J������Ă����牽�����Ȃ�
	if (table[mouse_location]->getOpen() == true);
	//�^�C�������Ă�������̑���
	else {
		dummy->flagTile(mouse_location);
	}
}
/*
*�@�\�T�v : �}�E�X�|�C���^���擾����@�\
*�@�\�ڍ� : �}�E�X�̈ړ�����N���b�N���s����܂ł̋@�\
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : �Ȃ�
*/

void MouseListener::inputMousePointer(){
	//�}�E�X�̍��W
	int mouse_x, mouse_y, mouse_location;
	//�}�E�X�̓��͔���
	int mouse_input;
	//�J�E���^�ϐ�
	int i = 0;
	//���̐�
	int flag_number;
	//�C���X�^���X����
	MouseListener *dummy;
	dummy = new MouseListener();
	TableController *table_instance;
	table_instance = new TableController();
	
	//�}�E�X�̍��W���擾
	GetMousePoint(&mouse_x, &mouse_y);

	//�}�E�X�̍��W��ϊ�
	mouse_location = dummy->convertTileCoordinates(mouse_x, mouse_y);

	//�}�E�X�̍��W�ɍ������̂̂ݔ���(�e�[�u���O�̂��͔̂��肵�Ȃ�)
	if (mouse_location >= 0) {
		//�}�E�X�̓��͂��擾
		mouse_input = GetMouseInput();
#if DEBUG
		DrawFormatString(0, 50, 100, "���W[%d,%d]", mouse_x, mouse_y);
		DrawFormatString(0, 100, 100, "mouse_location : %d", mouse_location);
		DrawFormatString(0, 150, 100, "mouse_input : %d", mouse_input);
#endif
		//���̐����J�E���g
		flag_number = table_instance->checkFlagNumber();
		//���e�����o��
		DrawFormatString(0, 50, 100, "���e�� : %d", BOMB_NUMBER);
		DrawFormatString(0, 100, 100, "���̐� : %d", flag_number);
		//�^�C���̏��


		//�}�E�X�̍��N���b�N�����͂��ꂽ�ꍇ
		if (mouse_input == MOUSE_INPUT_LEFT) {
			i++;
			inputLeftClick(mouse_location);
		}
		//�}�E�X�̉E�N���b�N�����͂��ꂽ�ꍇ
		else if (mouse_input == MOUSE_INPUT_RIGHT) {
			inputRightClick(mouse_location);
		}
		//�}�E�X���N���b�N����Ă���΁A�L���b�`
		do {
			mouse_input = GetMouseInput();
		} while (mouse_input != 0);
	}
}
