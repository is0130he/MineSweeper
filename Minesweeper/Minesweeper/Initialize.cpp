#include "Initialize.h"
#include "DxLib.h"

Initialize::Initialize(){}
Initialize::~Initialize(){}

/*
*機能概要 : 初期化処理
*機能詳細 : DXライブラリにおける初期化処理
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : なし
*/
void Initialize::startUp(){
	/*DXライブラリに関連する処理*/

	//ウィンドウモードに変更
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1){		// ＤＸライブラリ初期化処理
		DxLib_End();				// ＤＸライブラリ使用の終了処理
		exit(0);			// エラーが起きたら直ちに終了
	}
	//裏画面処理
	SetDrawScreen(DX_SCREEN_BACK);
	//背景を白に
	SetBackgroundColor(255, 255, 255);
}

/*
*機能概要 : 画像出力後の後処理
*機能詳細 : 画像出力後に画面クリアや裏画面表示などを実行
*@author : 西村宗高
*@version : 1
*@param : *tile (テーブル情報)
*@return : なし
*/

void Initialize::backGraund(){
	//裏画面を表画面に反映
	ScreenFlip();
	//画面クリア
	ClearDrawScreen();
	//メッセージ処理
	ProcessMessage();
}
