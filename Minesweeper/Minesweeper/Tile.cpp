#include"Tile.h"

//�f�o�b�O�p
//#define DEBUG true

//�^�C���֘A�̉摜
extern int tile_graph[12];
//�e�[�u�����
extern Tile *table[];
//�f�t�H���g�R���X�g���N�^
Tile::Tile() {}

//�R�s�[�R���X�g���N�^
Tile::Tile(int x, int y, bool open, tile_status status, bool flag_status) {
	this->x = x;
	this->y = y;
	this->open = open;
	this->status = status;
}

//�f�X�g���N�^
Tile::~Tile() {}


/*
*�@�\�T�v : 1�̃^�C���̒��g���o��
*�@�\�ڍ� : 1�̃^�C���̒��g�ɑΉ������摜���o��
*@author : �����@��
*@version : 1
*@param : image(�摜�f�[�^)
*@return : �Ȃ�(DX���C�u������ɂ̓^�C���̉摜)
*/
void Tile::dispTile(int image) {
	//�f�o�b�O��
#if DEBUG == true
	//�f�o�b�O��
	//�^�C�����J�����Ă���ꍇ�͒��g���o��
	DrawRotaGraph((this->x), (this->y), TILE_RATE, 0, image, FALSE);
#else
	//�{�Ԏ�
	//��������^�C���͊����o��
	if ((this->flag_status == true) && (this->open == false)) {
		DrawRotaGraph((this->x), (this->y), TILE_RATE, 0, tile_graph[11], FALSE);
	}
	//�^�C���������Ă���ꍇ�͕��Ă���^�C�����o��
	else if (this->open == false) {
		DrawRotaGraph((this->x), (this->y), TILE_RATE, 0, tile_graph[0], FALSE);
	}
	//�^�C�����J�����Ă���ꍇ�͒��g���o��
	else {
		DrawRotaGraph((this->x), (this->y), TILE_RATE, 0, image, FALSE);
	}
#endif
}

/*
*�@�\�T�v : �S�Ẵ^�C�����o��
*�@�\�ڍ� : �S�Ẵ^�C���ɑΉ������摜�����o��
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : �Ȃ�(DX���C�u������ɂ̓e�[�u���̉摜)
*/
void Tile::dispAll() {
	//�J�E���^�ϐ�
	int i;
	tile_status image;
	for (i = 0;i < X_MAX * Y_MAX;i++) {
		image = table[i]->getStatus();
		table[i]->dispTile(tile_graph[image]);
	}
}

/*
*�@�\�T�v : open�̃Z�b�^�[
*�@�\�ڍ� : open�̃Z�b�^�[
*@author : �����@��
*@version : 1
*@param : open(�^�C���̊J�t���O)
*@return : �Ȃ�
*/
void Tile::setOpen(bool open) {
	this->open = open;
}


/*
*�@�\�T�v : open�̃Q�b�^�[
*�@�\�ڍ� : open�̃Q�b�^�[
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : open(�^�C���̊J�t���O)
*/

bool Tile::getOpen() {
	return this->open;
}

/*
*�@�\�T�v : status�̃Z�b�^�[
*�@�\�ڍ� : status�̃Z�b�^�[
*@author : �����@��
*@version : 1
*@param : status(�^�C���̏��)
*@return : �Ȃ�
*/
void Tile::setStatus(tile_status status) {
	this->status = status;
}


/*
*�@�\�T�v : status�̃Z�b�^�[
*�@�\�ڍ� : status�̃Z�b�^�[
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : status(�^�C���̏��)
*/
tile_status Tile::getStatus() {
	return (this->status);
}


/*
*�@�\�T�v : flag�̃Z�b�^�[
*�@�\�ڍ� : flag�̃Z�b�^�[
*@author : �����@��
*@version : 1
*@param : flag_status(���̗L���t���O)
*@return : �Ȃ�
*/
void Tile::setFlag(bool flag) {
	this->flag_status = flag;
}
/*
*�@�\�T�v : flag�̃Q�b�^�[
*�@�\�ڍ� : flag�̃Q�b�^�[
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : flag_status(���̗L���t���O)
*/
//���̃Q�b�^�[
bool Tile::getFlag() {
	return this->flag_status;
}