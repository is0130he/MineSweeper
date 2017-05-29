#include "DangerousSpace.h"

extern Tile *table[];

DangerousSpace::DangerousSpace(){}


DangerousSpace::~DangerousSpace(){}
/*
*機能概要 : 周囲の爆弾の個数を確認
*機能詳細 : 対象のタイルに対して周囲の爆弾の個数を確認
*@author : 西村宗高
*@version : 1
*@param : *tile (タイルの画像情報の配列)
*@param : location(確認対象の位置)
*@return : bomb_number(指定タイル周辺における爆弾の個数)
*/

int DangerousSpace::checkBombNumber(int location){
	//タイルが存在するかチェック

	bool check[8] = { false };
	//全てのタイルが存在するかチェック
	//bool ret = false;
	//周囲のタイルの状態確認
	tile_status check_status[8], bomb_judge;
	//周囲の爆弾の数
	int bomb_number = 0;
	//カウンタ変数
	int i;

	//指定タイルに爆弾があるか確認
	bomb_judge = table[location]->getStatus();
	//指定のタイルに爆弾があれば、危険地帯でない
	if (bomb_judge == bomb) {
		return 0;
	}

	//メソッド呼び出しのために生成
	TableController *dummy;
	dummy  = new TableController();

	//タイルの存在をチェック
	dummy->checkAroundTile(location, check);
	
	getAroundStatus(location, check, check_status);

	//爆弾の数をカウント
	for (i = 0;i < 8;i++) {
		if (check_status[i] == bomb) {
			bomb_number++;
		}
	}
		return bomb_number;
}


/*
*機能概要 : タイルの周りの状態を取得
*機能詳細 : タイルの周りの状態(上、下、右、左、右上、右下、左上、左下)を取得し、参照渡しで結果を返すメソッド
*@author : 西村宗高
*@version : 1
*@param : *tile (テーブル情報)
*@param : location(中心となるタイルの位置)
*@param  : *check(周囲のタイルの有無が格納されている配列)
*@param : *check_status(周囲のタイルの状態を格納する配列)
*@return : なし(返してもらいたいものは*check_statusの中身)
*/

void DangerousSpace::getAroundStatus(int location, bool * check, tile_status * check_status){
	TableController *dummy;
	dummy = new TableController();
	
	//上にタイルが存在する場合
	if (check[ON] == true) {
		check_status[ON] = dummy->checkOnStatus(location);
	}

	//下のタイルが存在する場合
	if (check[UNDER] == true) {
		check_status[UNDER] = dummy->checkUnderStatus(location);
	}

	//右のタイルが存在する場合
	if (check[RIGHT] == true) {
		check_status[RIGHT] = dummy->checkRightStatus(location);
	}

	//左のタイルが存在する場合
	if (check[LEFT] == true) {
		check_status[LEFT] = dummy->checkLeftStatus(location);
	}

	//右上のタイルが存在する場合
	if (check[RIGHT_ON] == true) {
		check_status[RIGHT_ON] = dummy->checkRightOnStatus(location);
	}

	//左上のタイルが存在する場合
	if (check[LEFT_ON] == true) {
		check_status[LEFT_ON] = dummy->checkLeftOnStatus(location);
	}

	//右下のタイルが存在する場合
	if (check[RIGHT_UNDER] == true) {
		check_status[RIGHT_UNDER] = dummy->checkRightUnderStatus(location);
	}

	//左下のタイルが存在する場合
	if (check[LEFT_UNDER] == true) {
		check_status[LEFT_UNDER] = dummy->checkLeftUnderStatus(location);
	}
}


//危険地帯の状態をセットするメソッド
/*
*機能概要 : 危険地帯の状態をセットするメソッド
*機能詳細 : タイルの周りの爆弾数を取得し、テーブルにセット
*@author : 西村宗高
*@version : 1
*@param : *tile (テーブル情報)
*@return : なし
*/
void DangerousSpace::createDangerousSpace(){
	
	//カウンタ変数
	int i, j;
	//爆弾の数
	int bomb_number = 0;
	//タイルの状態
	tile_status status;

	//状態をセット
	for (j = 0;j < Y_MAX;j++) {
		for (i = 0;i < X_MAX; i++) {
			//周囲の爆弾の個数を取得
			bomb_number = checkBombNumber(X_MAX * j + i);
			
			//爆弾がある場合 (ない場合は何もしない)
			if (bomb_number > 0) {
					status = convertBombNumber(bomb_number);
					table[X_MAX * j + i]->setStatus(status);
			}
		}
	}

}

/*
*機能概要 : 爆弾数からtile_status型に変換
*機能詳細 : tile_statusがenum型であるため、値の変換を実行
*@author : 西村宗高
*@version : 1
*@param : bomb_number(爆弾数)
*@return : tile_status型への変換結果(例 : 1→one)
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
			//構文チェックソフト用の対策
	else {
			return nothing;
		}
	}