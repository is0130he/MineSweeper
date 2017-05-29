#include"Tile.h"

//デバッグ用
//#define DEBUG true

//タイル関連の画像
extern int tile_graph[12];
//テーブル情報
extern Tile *table[];
//デフォルトコンストラクタ
Tile::Tile() {}

//コピーコンストラクタ
Tile::Tile(int x, int y, bool open, tile_status status, bool flag_status) {
	this->x = x;
	this->y = y;
	this->open = open;
	this->status = status;
}

//デストラクタ
Tile::~Tile() {}


/*
*機能概要 : 1つのタイルの中身を出力
*機能詳細 : 1つのタイルの中身に対応した画像を出力
*@author : 西村宗高
*@version : 1
*@param : image(画像データ)
*@return : なし(DXライブラリ上にはタイルの画像)
*/
void Tile::dispTile(int image) {
	//デバッグ時
#if DEBUG == true
	//デバッグ時
	//タイルが開放している場合は中身を出力
	DrawRotaGraph((this->x), (this->y), TILE_RATE, 0, image, FALSE);
#else
	//本番時
	//旗があるタイルは旗を出力
	if ((this->flag_status == true) && (this->open == false)) {
		DrawRotaGraph((this->x), (this->y), TILE_RATE, 0, tile_graph[11], FALSE);
	}
	//タイルが閉鎖している場合は閉じているタイルを出力
	else if (this->open == false) {
		DrawRotaGraph((this->x), (this->y), TILE_RATE, 0, tile_graph[0], FALSE);
	}
	//タイルが開放している場合は中身を出力
	else {
		DrawRotaGraph((this->x), (this->y), TILE_RATE, 0, image, FALSE);
	}
#endif
}

/*
*機能概要 : 全てのタイルを出力
*機能詳細 : 全てのタイルに対応した画像情報を出力
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : なし(DXライブラリ上にはテーブルの画像)
*/
void Tile::dispAll() {
	//カウンタ変数
	int i;
	tile_status image;
	for (i = 0;i < X_MAX * Y_MAX;i++) {
		image = table[i]->getStatus();
		table[i]->dispTile(tile_graph[image]);
	}
}

/*
*機能概要 : openのセッター
*機能詳細 : openのセッター
*@author : 西村宗高
*@version : 1
*@param : open(タイルの開閉フラグ)
*@return : なし
*/
void Tile::setOpen(bool open) {
	this->open = open;
}


/*
*機能概要 : openのゲッター
*機能詳細 : openのゲッター
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : open(タイルの開閉フラグ)
*/

bool Tile::getOpen() {
	return this->open;
}

/*
*機能概要 : statusのセッター
*機能詳細 : statusのセッター
*@author : 西村宗高
*@version : 1
*@param : status(タイルの状態)
*@return : なし
*/
void Tile::setStatus(tile_status status) {
	this->status = status;
}


/*
*機能概要 : statusのセッター
*機能詳細 : statusのセッター
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : status(タイルの状態)
*/
tile_status Tile::getStatus() {
	return (this->status);
}


/*
*機能概要 : flagのセッター
*機能詳細 : flagのセッター
*@author : 西村宗高
*@version : 1
*@param : flag_status(旗の有無フラグ)
*@return : なし
*/
void Tile::setFlag(bool flag) {
	this->flag_status = flag;
}
/*
*機能概要 : flagのゲッター
*機能詳細 : flagのゲッター
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : flag_status(旗の有無フラグ)
*/
//旗のゲッター
bool Tile::getFlag() {
	return this->flag_status;
}