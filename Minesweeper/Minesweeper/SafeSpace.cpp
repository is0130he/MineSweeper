#include "SafeSpace.h"

extern Tile *table[];

SafeSpace::SafeSpace(){
}


SafeSpace::~SafeSpace(){
}
/*
*機能概要 : 安全地帯を生成
*機能詳細 : 爆弾のある所と危険地帯のあるところ以外に安全地帯をセット
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : なし
*/
void SafeSpace::createSafeSpace(){
	//カウンタ変数
	int i, j;
	//危険地帯・爆弾の確認
	bool check;
	
	//状態をセット
	for (j = 0;j < Y_MAX;j++) {
		for (i = 0;i < X_MAX; i++) {
			//危険地帯・爆弾の確認
			check = checkSafeSpace(X_MAX * j + i);
			//安全地帯の作成
			if (check == true) {
				table[X_MAX * j + i] -> setStatus(safespace);
			}
		}
	}
}
/*
*機能概要 : 安全地帯であるかチェック
*機能詳細 : statusがnothingであるかを確認
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : true(nothing), false(nothingじゃない)
*/
bool SafeSpace::checkSafeSpace(int location){
	tile_status check;
	check = table[location]->getStatus();
	if (check != 0) {
		return false;
	}
	return true;
}

/*
*機能概要 : 安全地帯がクリックされた際、隣接する安全地帯を表示するメソッド
*機能詳細 : 安全地帯がクリックされた際、隣接する安全地帯を一気に表示
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : なし
*/
void SafeSpace::searchAllSafeSpace(int location){
	//テーブルクラス呼び出し用
	TableController *dummy;
	dummy = new TableController();
	//左から時計回りに探索
	
	//左
	if (dummy->checkLeftTile(location) == true) {
		searchLeftSafeSpace(location);
	}
	//左上
	if (dummy->checkLeftOnTile(location) == true) {
		searchLeftOnSafeSpace(location);
	}
	//上
	if (dummy->checkOnTile(location) == true) {
		searchOnSafeSpace(location);
	}
	//右上
	if (dummy->checkRightOnTile(location) == true) {
		searchRightOnSafeSpace(location);
	}
	//右
	if (dummy->checkRightTile(location) == true) {
		searchRightSafeSpace(location);
	}
	//右下
	if (dummy->checkRightUnderTile(location) == true) {
		searchRightUnderSafeSpace(location);
	}
	//下
	if (dummy->checkUnderTile(location) == true) {
		searchUnderSafeSpace(location);
	}
	//左下
	if (dummy->checkLeftUnderTile(location) == true) {
		searchLeftUnderSafeSpace(location);
	}
}

/*
*機能概要 : 左に安全地帯があるのか深さ優先探索
*機能詳細 : 左に安全地帯があるのか深さ優先探索し、あれば再起
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : なし
*/
void SafeSpace::searchLeftSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//場所を左に設定
	location--;

	//安全地帯の確認
	if (table[location]->getStatus() == safespace) {

		//開放されているタイルの確認
		if (table[location]->getOpen() == true);

		//タイルが開放されておらず,左にタイルが存在する場合
		else {
			//タイルを開放
			table[location]->setOpen(true);
			//再起
			searchAllSafeSpace(location);
		}
	}
	//爆弾の場合
	//何もしない
	else if (table[location]->getStatus() == bomb);
	//危険地帯の場合
	else{
		//タイルを開放
		table[location]->setOpen(true);
	}
}

/*
*機能概要 : 右に安全地帯があるのか深さ優先探索
*機能詳細 : 右に安全地帯があるのか深さ優先探索し、あれば再起
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : なし
*/
void SafeSpace::searchRightSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//場所を右に設定
	location++;

	//安全地帯の確認
	if (table[location]->getStatus() == safespace) {
		//開放されているタイルの確認
		if (table[location]->getOpen() == true);
		//探索を継続する場合
		else {
			//タイルを開放
			table[location]->setOpen(true);
			//再起
			searchAllSafeSpace(location);
		}
	}
	//爆弾の場合,何もしない
	else if (table[location]->getStatus() == bomb);

	//危険地帯の場合
	else {
		//タイルを開放
		table[location]->setOpen(true);
	}
}
/*
*機能概要 : 上に安全地帯があるのか深さ優先探索
*機能詳細 : 上に安全地帯があるのか深さ優先探索し、あれば再起
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : なし
*/
void SafeSpace::searchOnSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//場所を上に設定
	location -= X_MAX;

	//安全地帯の確認
	if (table[location]->getStatus() == safespace) {
		//開放されているタイルの確認
		if (table[location]->getOpen() == true);
		//探索を継続する場合
		else {
			//タイルを開放
			table[location]->setOpen(true);
			//再起
			searchAllSafeSpace(location);
		}
	}
	//爆弾の場合
	else if (table[location]->getStatus() == bomb);
	//危険地帯の場合
	else {
		//タイルを開放
		table[location]->setOpen(true);
	}
}
/*
*機能概要 : 下に安全地帯があるのか深さ優先探索
*機能詳細 : 下に安全地帯があるのか深さ優先探索し、あれば再起
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : なし
*/
void SafeSpace::searchUnderSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//場所を下に設定
	location += X_MAX;

	//安全地帯の確認
	if (table[location]->getStatus() == safespace) {

		//開放されているタイルの確認
		if (table[location]->getOpen() == true);
		//探索を継続する場合
		else {
			//タイルを開放
			table[location]->setOpen(true);
			//再起
			searchAllSafeSpace(location);
		}
	}
	//爆弾の場合
	else if (table[location]->getStatus() == bomb);
	//危険地帯の場合
	else {
		//タイルを開放
		table[location]->setOpen(true);
	}
}
/*
*機能概要 : 右上に安全地帯があるのか深さ優先探索
*機能詳細 : 右上に安全地帯があるのか深さ優先探索し、あれば再起
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : なし
*/
void SafeSpace::searchRightOnSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//場所を右上に設定
	location = location - X_MAX + 1;

	//安全地帯の確認
	if (table[location]->getStatus() == safespace) {

		//開放されているタイルの確認
		if (table[location]->getOpen() == true);
		//探索を継続する場合
		else {
			//タイルを開放
			table[location]->setOpen(true);
			//再起
			searchAllSafeSpace(location);
		}
	}
	//爆弾の場合
	else if (table[location]->getStatus() == bomb);
	//危険地帯の場合
	else {
		//タイルを開放
		table[location]->setOpen(true);
	}
}
/*
*機能概要 : 右下に安全地帯があるのか深さ優先探索
*機能詳細 : 右下に安全地帯があるのか深さ優先探索し、あれば再起
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : なし
*/
void SafeSpace::searchRightUnderSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//場所を右下に設定
	location = location + X_MAX + 1;

	//安全地帯の確認
	if (table[location]->getStatus() == safespace) {

		//開放されているタイルの確認
		if (table[location]->getOpen() == true);
		//探索を継続する場合
		else {
			//タイルを開放
			table[location]->setOpen(true);
			//再起
			searchAllSafeSpace(location);
		}
	}
	//爆弾の場合
	else if (table[location]->getStatus() == bomb);
	//危険地帯の場合
	else {
		//タイルを開放
		table[location]->setOpen(true);
	}
}
/*
*機能概要 : 左上に安全地帯があるのか深さ優先探索
*機能詳細 : 左上に安全地帯があるのか深さ優先探索し、あれば再起
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : なし
*/
void SafeSpace::searchLeftOnSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	//場所を左上に設定
	location = location - X_MAX - 1;

	//安全地帯の確認
	if (table[location]->getStatus() == safespace) {
		//開放されているタイルの確認
		if (table[location]->getOpen() == true);
		//探索を継続する場合
		else {
			//タイルを開放
			table[location]->setOpen(true);
			//再起
			searchAllSafeSpace(location);
		}
	}
	//爆弾の場合,何もしない
	else if (table[location]->getStatus() == bomb);
	//危険地帯の場合
	else {
		//タイルを開放
		table[location]->setOpen(true);
	}
}
/*
*機能概要 : 左下に安全地帯があるのか深さ優先探索
*機能詳細 : 左下に安全地帯があるのか深さ優先探索し、あれば再起
*@author : 西村宗高
*@version : 1
*@param : location(基準となるタイルの位置)
*@return : なし
*/
void SafeSpace::searchLeftUnderSafeSpace(int location){
	TableController *dummy;
	dummy = new TableController();
	
	//場所を左下に設定
	location = location + X_MAX - 1;

	//安全地帯の確認
	if (table[location]->getStatus() == safespace) {

		//開放されているタイルの確認
		if (table[location]->getOpen() == true);

		//探索を継続する場合
		else {
			//タイルを開放
			table[location]->setOpen(true);
			searchAllSafeSpace(location);
		}
	}
	//爆弾の場合、何もしない
	else if (table[location]->getStatus() == bomb);
	//危険地帯の場合
	else {
		//タイルを開放
		table[location]->setOpen(true);
	}
}

