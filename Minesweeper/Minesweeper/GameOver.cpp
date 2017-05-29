#include "GameOver.h"

#include"DxLib.h"

extern Tile *table[];

GameOver::GameOver(){}
GameOver::~GameOver(){}

/*
*機能概要 : ゲームオーバー処理
*機能詳細 : ゲームオーバー画像を出力
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : なし
*/
void GameOver::gameOverEnd(int location){

	//画像をロード
	int gameover_graphic = LoadGraph("game_over.png");
	//3秒間(爆弾を)表示
	WaitTimer(3000);
	//画面をクリア
	ClearDrawScreen();
	
	//ゲームオーバー画面を出力
	DrawGraph(0, 0, gameover_graphic, FALSE);
	ScreenFlip();
	//メッセージ処理
	ProcessMessage();
}
/*
*機能概要 : ゲームオーバーか確認
*機能詳細 : テーブル上において爆弾を持ち開放されているタイルが存在する(ゲームオーバーとなっている)か確認
*@author : 西村宗高
*@version : 1
*@param : *tile (テーブル情報)
*@return : 2(ゲームオーバー), 0(ゲームオーバーならず)
*/

int GameOver::checkGameOver(){
	//カウンタ変数
	int i;
	//タイルの状態を取得する変数
	tile_status status;
	//タイルの開閉を取得する変数
	bool open;
	for (i = 0;i < (X_MAX * Y_MAX);i++) {
		//タイルの状態を確認
		status = table[i]->getStatus();
		//タイルの開閉を取得
		open = table[i]->getOpen();
		//タイルの中身が爆弾の場合
		if (status == bomb) {
			//タイルが開放されている場合
			if (open == true) {
				//ゲームオーバー
				return 2;
			}
		}
	}
	//問題なし
	return 0;
}
