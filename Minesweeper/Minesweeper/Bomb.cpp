#include "Bomb.h"
#include"Tile.h"
#include<time.h>
#include <windows.h>

//�e�[�u�����
extern Tile *table[];

//�R���X�g���N�^
Bomb::Bomb() {}

//�f�X�g���N�^
Bomb::~Bomb() {}

/*
*�@�\�T�v : �����_���ɔ��e�𐶐����郁�\�b�h
*�@�\�ڍ� : �����_����BOMB_NUMBER�̐��������e�𐶐�
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : �Ȃ�
*/

	void Bomb::createBomb() {
		//�d���`�F�b�N�p�̔z��
		int check[BOMB_NUMBER] = { -1 };
		//����(���e�̔z�u)
		int random;
		//�J�E���^�ϐ�
		int i = 0;
		bool check_flag;

		//_____��������_____
		srand((unsigned int)time(NULL));
		//�����Ƃ��������𐶐����邽�߂̏���(5��ڈȍ~�łȂ��Ɨ����ɂȂ�Ȃ�)
		for (i = 0;i < 10;i++) {
			rand();
		}
		i = 0;
		//____________________

		while (i < BOMB_NUMBER) {
			//��������
			random = locateBomb();
			//�d���`�F�b�N
			check_flag = checkRepeat(check, random);
			//�K���������ł���Ύ��Ɉڂ�
			if (check_flag == true) {
				check[i] = random;
				i++;
			}
		}
		setBomb(check);
	}

/*
*�@�\�T�v : ���������p���\�b�h
*�@�\�ڍ� : ���e�𐶐����邽�߂ɗ����𐶐����郁�\�b�h
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@return : random_number(����)
*/
	int Bomb::locateBomb() {
		//�Ԃ�l
		int random_number;

		//(�z��ɍ��킹��)0 ~ (�Z���̐�)-1 �̗����𐶐�
		random_number = rand() % (X_MAX * Y_MAX);

		return random_number;
	}

/*
*�@�\�T�v : �d���`�F�b�N
*�@�\�ڍ� : �������������ɏd�������邩�`�F�b�N���郁�\�b�h
*@author : �����@��
*@version : 1
*@param : *check(�`�F�b�N�Ώۂ̐������ꂽ����)
*@param : target(�V�����������ꂽ����)
*@return : �d���������"false", �d�����Ȃ����"true"
*/

	bool Bomb::checkRepeat(int * check, int target) {
		//�J�E���^�ϐ�
		int i;

		//�d���`�F�b�N
		for (i = 0; i < BOMB_NUMBER; i++) {
			//�������ꂽ�����Ƃ��łɐ������ꂽ���̂��r
			if (check[i] == target) {
				return false;
			}
		}
		return true;
	}
/*
*�@�\�T�v : ���e��ݒu
*�@�\�ڍ� : �������ꂽ���e����x�ɑS�ăZ�b�g���郁�\�b�h
*@author : �����@��
*@version : 1
*@param : �Ȃ�
*@param : *check(�����������e�̈ʒu�̔z��)
*@return : �Ȃ�
*/

	void Bomb::setBomb(int *check) {
		//�J�E���^�ϐ�
		int i;
		//���ꂼ��̃^�C���ɔ��e���Z�b�g
		for (i = 0;i < BOMB_NUMBER;i++) {
			table[check[i]]->setStatus(bomb);
		}
	}