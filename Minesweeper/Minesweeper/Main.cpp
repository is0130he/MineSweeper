//テーブル関連の処理を行う関数が必須
#include"Tile.h"
#include"PlayMode.h"

/*
*機能概要 : メイン関数
*機能詳細 : DXライブラリの起動と終了
*@author : 西村宗高
*@version : 1
*@param : あり(詳細不明)
*@return : なし
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//インスタンス生成用
	PlayMode *play;
	play = new PlayMode();

	play->mainRoutine();
	//キー入力待ち(ユーザの認識待ち)
	WaitKey();
	//DXライブラリの終了
	DxLib_End();
	//メモリ開放
	return 0;
}
