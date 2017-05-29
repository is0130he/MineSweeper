#include "GameClear.h"

extern Tile *table[];

GameClear::GameClear(){}


GameClear::~GameClear(){}

//ゲームクリアを判定するメソッド
/*
*機能概要 : ゲームクリアを判定するメソッド
*機能詳細 : テーブルにおいて爆弾を持つタイルを除きすべてのタイルが開放されている(クリアしている)か確認
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : 1(ゲームクリア)、0(ゲームクリアならず)
*/

int GameClear::checkGameClear(){
	//カウンタ変数
	int i, open_count = X_MAX * Y_MAX - BOMB_NUMBER;
	//タイルの状態を取得する変数
	tile_status status;
	//タイルの開閉を取得する変数
	bool open;
	//開放されているタイルが(タイルの数) - (爆弾の数)あるか確認
	for (i = 0;i < (X_MAX * Y_MAX);i++) {
		//タイルの状態を確認
		status = table[i]->getStatus();
		//タイルの開閉を取得
		open = table[i]->getOpen();
		//タイルの中身が爆弾でない場合
		if (status != bomb) {
			//タイルが開放されている場合
			if (open == true) {
				//カウント
				open_count--;
			}
		}
	}
	//クリアならず
	if (open_count > 0) {
		return 0;
	}
	//クリア
	return 1;
}
/*
*機能概要 : ゲームクリア処理
*機能詳細 : ゲームクリア画像を出力
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : なし
*/
void GameClear::gameClearEnd(){
	
	//画像をロード
	int gameclear_graphic = LoadGraph("game_clear.png");

	//画面をクリア
	ClearDrawScreen();
	//ゲームクリア画面を出力
	DrawGraph(0, 0, gameclear_graphic, FALSE);
	ScreenFlip();
	//メッセージ処理
	ProcessMessage();
}