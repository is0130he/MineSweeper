#include "Bomb.h"
#include"Tile.h"
#include<time.h>
#include <windows.h>

//テーブル情報
extern Tile *table[];

//コンストラクタ
Bomb::Bomb() {}

//デストラクタ
Bomb::~Bomb() {}

/*
*機能概要 : ランダムに爆弾を生成するメソッド
*機能詳細 : ランダムにBOMB_NUMBERの数だけ爆弾を生成
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : なし
*/

	void Bomb::createBomb() {
		//重複チェック用の配列
		int check[BOMB_NUMBER] = { -1 };
		//乱数(爆弾の配置)
		int random;
		//カウンタ変数
		int i = 0;
		bool check_flag;

		//_____乱数生成_____
		srand((unsigned int)time(NULL));
		//ちゃんとした乱数を生成するための処理(5回目以降でないと乱数にならない)
		for (i = 0;i < 10;i++) {
			rand();
		}
		i = 0;
		//____________________

		while (i < BOMB_NUMBER) {
			//乱数生成
			random = locateBomb();
			//重複チェック
			check_flag = checkRepeat(check, random);
			//適した乱数であれば次に移る
			if (check_flag == true) {
				check[i] = random;
				i++;
			}
		}
		setBomb(check);
	}

/*
*機能概要 : 乱数生成用メソッド
*機能詳細 : 爆弾を生成するために乱数を生成するメソッド
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : random_number(乱数)
*/
	int Bomb::locateBomb() {
		//返り値
		int random_number;

		//(配列に合わせて)0 ~ (セルの数)-1 の乱数を生成
		random_number = rand() % (X_MAX * Y_MAX);

		return random_number;
	}

/*
*機能概要 : 重複チェック
*機能詳細 : 生成した乱数に重複があるかチェックするメソッド
*@author : 西村宗高
*@version : 1
*@param : *check(チェック対象の生成された乱数)
*@param : target(新しく生成された乱数)
*@return : 重複があれば"false", 重複がなければ"true"
*/

	bool Bomb::checkRepeat(int * check, int target) {
		//カウンタ変数
		int i;

		//重複チェック
		for (i = 0; i < BOMB_NUMBER; i++) {
			//生成された乱数とすでに生成されたものを比較
			if (check[i] == target) {
				return false;
			}
		}
		return true;
	}
/*
*機能概要 : 爆弾を設置
*機能詳細 : 生成された爆弾を一度に全てセットするメソッド
*@author : 西村宗高
*@version : 1
*@param : なし
*@param : *check(生成した爆弾の位置の配列)
*@return : なし
*/

	void Bomb::setBomb(int *check) {
		//カウンタ変数
		int i;
		//それぞれのタイルに爆弾をセット
		for (i = 0;i < BOMB_NUMBER;i++) {
			table[check[i]]->setStatus(bomb);
		}
	}