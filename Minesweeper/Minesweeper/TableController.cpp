#include "TableController.h"

extern Tile *table[];

TableController::TableController(){}


TableController::~TableController(){}
/*
*機能概要 : 上にタイルが存在するかチェック
*機能詳細 : 指定したタイルの上にタイルが存在するのかチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : true(存在する場合), false(存在しない場合)
*/
bool TableController::checkOnTile(int location){
	int check = location / X_MAX;

	//if文はタイルが存在しない場合を記述
	if (check == 0) {
		return false;
	}
	return true;
}

/*
*機能概要 : 下にタイルが存在するかチェック
*機能詳細 : 指定したタイルの下にタイルが存在するのかチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : true(存在する場合), false(存在しない場合)
*/

bool TableController::checkUnderTile(int location){
	int check = location / X_MAX;

	//if文はタイルが存在しない場合を記述
	if (check == X_MAX - 1 ) {
		return false;
	}
	return true;
}

/*
*機能概要 : 右にタイルが存在するかチェック
*機能詳細 : 指定したタイルの右にタイルが存在するのかチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : true(存在する場合), false(存在しない場合)
*/
bool TableController::checkRightTile(int location){
	int check = location % X_MAX;

	//if文はタイルが存在しない場合を記述
	if (check == X_MAX - 1) {
		return false;
	}
	return true;
}


/*
*機能概要 : 左にタイルが存在するかチェック
*機能詳細 : 指定したタイルの左にタイルが存在するのかチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : true(存在する場合), false(存在しない場合)
*/

bool TableController::checkLeftTile(int location) {
	int check = location % X_MAX;

	//if文はタイルが存在しない場合を記述
	if (check == 0) {
		return false;
	}
	return true;
}

/*
*機能概要 : 右上にタイルが存在するかチェック
*機能詳細 : 指定したタイルの右上にタイルが存在するのかチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : true(存在する場合), false(存在しない場合)
*/

bool TableController::checkRightOnTile(int location){
	bool check;

	//上の辺をチェック
	check = checkOnTile(location);


	if (check == false) {
		return false;
	}

	//右の辺をチェック
	check = checkRightTile(location);

	if (check == false) {
		return false;
	}
	
	return true;
}

/*
*機能概要 : 左上にタイルが存在するかチェック
*機能詳細 : 指定したタイルの左上にタイルが存在するのかチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : true(存在する場合), false(存在しない場合)
*/

bool TableController::checkLeftOnTile(int location){
	bool check;

	//上の辺をチェック
	check = checkOnTile(location);


	if (check == false) {
		return false;
	}

	//左の辺をチェック
	check = checkLeftTile(location);

	if (check == false) {
		return false;
	}

	return true;
}
/*
*機能概要 : 右下にタイルが存在するかチェック
*機能詳細 : 指定したタイルの右下にタイルが存在するのかチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : true(存在する場合), false(存在しない場合)
*/

bool TableController::checkRightUnderTile(int location){
	bool check;

	//下の辺をチェック
	check = checkUnderTile(location);


	if (check == false) {
		return false;
	}

	//右の辺をチェック
	check = checkRightTile(location);

	if (check == false) {
		return false;
	}

	return true;
}
/*
*機能概要 : 左下にタイルが存在するかチェック
*機能詳細 : 指定したタイルの左下にタイルが存在するのかチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : true(存在する場合), false(存在しない場合)
*/

bool TableController::checkLeftUnderTile(int location){
	bool check;

	//下の辺をチェック
	check = checkUnderTile(location);


	if (check == false) {
		return false;
	}

	//左の辺をチェック
	check = checkLeftTile(location);

	if (check == false) {
		return false;
	}

	return true;
}


/*
*機能概要 : 周囲にタイルが存在するかチェック
*機能詳細 : 指定したタイルの周囲にタイルが存在するのかチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : true(存在する場合), false(存在しない場合)
*/

bool TableController::checkAroundTile(int location, bool *check){

	//上のタイルをチェック
	*(check++) = checkOnTile(location);
	//下のタイルをチェック
	*(check++) = checkUnderTile(location);
	//右のタイルをチェック
	*(check++) = checkRightTile(location);
	//左のタイルをチェック
	*(check++) = checkLeftTile(location);
	
	//右上のタイルをチェック
	*(check++) = checkRightOnTile(location);
	//左上のタイルをチェック
	*(check++) = checkLeftOnTile(location);
	//右下のタイルをチェック
	*(check++) = checkRightUnderTile(location);
	//左下のタイルをチェック
	*(check++) = checkLeftUnderTile(location);

	return true;
}

/*
*機能概要 : 上のタイルの状態をチェック
*機能詳細 : 指定したタイルの上の状態をチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : ret(指定したタイルの上の状態)
*/
tile_status TableController::checkOnStatus(int location){
	tile_status ret = table[location - X_MAX] -> getStatus();

	return ret;
}

/*
*機能概要 : 下のタイルの状態をチェック
*機能詳細 : 指定したタイルの下の状態をチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : ret(指定したタイルの下の状態)
*/
tile_status TableController::checkUnderStatus(int location){

	tile_status ret = table[location + X_MAX]->getStatus();

	return ret;
}

/*
*機能概要 : 右のタイルの状態をチェック
*機能詳細 : 指定したタイルの右の状態をチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : ret(指定したタイルの右の状態)
*/
tile_status TableController::checkRightStatus(int location){

	tile_status ret = table[location + 1]->getStatus();

	return ret;
}

/*
*機能概要 : 左のタイルの状態をチェック
*機能詳細 : 指定したタイルの左の状態をチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : ret(指定したタイルの左の状態)
*/

tile_status TableController::checkLeftStatus(int location){

	tile_status ret = table[location - 1]->getStatus();

	return ret;
}

/*
*機能概要 : 右上のタイルの状態をチェック
*機能詳細 : 指定したタイルの右上の状態をチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : ret(指定したタイルの右上の状態)
*/

tile_status TableController::checkRightOnStatus(int location){

	tile_status ret = table[location -X_MAX + 1]->getStatus();

	return ret;
}

/*
*機能概要 : 左上のタイルの状態をチェック
*機能詳細 : 指定したタイルの左上の状態をチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : ret(指定したタイルの左上の状態)
*/

tile_status TableController::checkLeftOnStatus(int location){

	tile_status ret = table[location - X_MAX - 1]->getStatus();

	return ret;
}

/*
*機能概要 : 右下のタイルの状態をチェック
*機能詳細 : 指定したタイルの右下の状態をチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : ret(指定したタイルの右下の状態)
*/

tile_status TableController::checkRightUnderStatus(int location){

	tile_status ret = table[location + X_MAX + 1]->getStatus();

	return ret;
}

/*
*機能概要 : 左下のタイルの状態をチェック
*機能詳細 : 指定したタイルの左下の状態をチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : ret(指定したタイルの左下の状態)
*/

tile_status TableController::checkLeftUnderStatus(int location){

	tile_status ret = table[location + X_MAX - 1]->getStatus();

	return ret;
}
/*
*機能概要 : 全方向のタイルの状態をチェック
*機能詳細 : 指定したタイルの全方向の状態をチェック
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@param : check(返すべき値を入力するデータ)
*@return : なし(check)
*/

void TableController::checkAroundStatus(int location, tile_status check[8]){
	
	//上のタイルの状態を取得
	*(check++) = checkOnStatus(location);
	//下のタイルの状態を取得
	*(check++) = checkUnderStatus(location);
	//右のタイルの状態を取得
	*(check++) = checkRightStatus(location);
	//左のタイルの状態を取得
	*(check++) = checkLeftStatus(location);
	
	//右上のタイルの状態を取得
	*(check++) = checkRightOnStatus(location);
	//左上のタイルの状態を取得
	*(check++) = checkLeftOnStatus(location);
	//右下のタイルの状態を取得
	*(check++) = checkRightUnderStatus(location);
	//左下のタイルの状態を取得
	*(check++) = checkLeftUnderStatus(location);
}

int TableController::checkFlagNumber(){
	//カウンタ変数
	int i;
	//旗の状態チェック
	bool flag_check;
	//旗の数をカウント
	int count = 0;
	for (i = 0;i < X_MAX *Y_MAX;i++) {
		flag_check = table[i]->getFlag();
		if (flag_check == true) {
			count++;
		}
	}
	return count;
}

