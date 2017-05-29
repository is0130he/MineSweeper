#include "PlayMode.h"

//生成するテーブル
Tile *table[X_MAX * Y_MAX];
//タイル関連の画像
int tile_graph[12];

//コンストラクタ
PlayMode::PlayMode(){}
PlayMode::~PlayMode(){}

/*
*機能概要 : タイルの画像をロード
*機能詳細 : タイルの画像をそれぞれの配列にロード
*@author : 西村宗高
*@version : 1
*@param : *tile (タイルの画像情報の配列)
*@return : なし
*/
void PlayMode::loadTileGraphics(int * tile){
	//画像をロード
	//タイル(初期状態の画像)
	tile[0] = LoadGraph("Tile0.png");
	//タイル(危険地帯の画像) ※番号は周りの爆弾の数
	tile[1] = LoadGraph("Tile1.png");
	tile[2] = LoadGraph("Tile2.png");
	tile[3] = LoadGraph("Tile3.png");
	tile[4] = LoadGraph("Tile4.png");
	tile[5] = LoadGraph("Tile5.png");
	tile[6] = LoadGraph("Tile6.png");
	tile[7] = LoadGraph("Tile7.png");
	tile[8] = LoadGraph("Tile8.png");
	//爆弾
	tile[9] = LoadGraph("Bomb.png");
	//安全地帯
	tile[10] = LoadGraph("SafeSpace.png");
	//旗
	tile[11] = LoadGraph("Flag.png");
}

//テーブルを生成するメソッド
/*
*機能概要 : テーブルを生成するメソッド
*機能詳細 : 作成したテーブルに動的メモリ確保
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : なし
*/

void PlayMode::createTable(void){
	//タイルを出力させる位置(初期値は(0,0)の位置)
	int start_x = BEGIN_X, start_y = BEGIN_Y;
	double size = 0.25;
	int i, j;
	//タイルの間隔
	int interval = 25;

	//メソッド処理用のインスタンス
	Bomb *dummy;
	dummy = new Bomb();
	DangerousSpace *dummy2;
	dummy2 = new DangerousSpace();
	SafeSpace *dummy3;
	dummy3 = new SafeSpace();
	MouseListener * dummy4;
	dummy4 = new MouseListener();

	//タイルの生成
	for (j = 0;j < Y_MAX;j++, start_y += TILE_INTERVAL) {
		for (i = 0;i < X_MAX; i++, start_x += TILE_INTERVAL) {
			table[X_MAX * j + i] = new Tile(start_x, start_y, false, nothing, false);
		}
		//x座標を元に戻す
		start_x = 200;
	}

	//臨時用
	//爆弾生成
	dummy->createBomb();
	//危険地帯設定
	dummy2->createDangerousSpace();
	//安全地帯設定
	dummy3->createSafeSpace();
}

/*
*機能概要 : メインルーチン
*機能詳細 : 主な処理を行うメソッド(ほとんどの処理がここからスタートする)
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : なし
*/

void PlayMode::mainRoutine(){
	//メソッド呼び出し用のインスタンス生成
	MouseListener * dummy5;
	dummy5 = new MouseListener();
	Initialize * dummy6;
	dummy6 = new Initialize();
	PlayMode *dummy7;
	dummy7 = new PlayMode();
	GameOver *dummy8;
	dummy8 = new GameOver();
	GameClear *dummy9;
	dummy9 = new GameClear();
	//終了フラグ(0:なし,1:game vlear, 2:game over)
	int end_flag = 0;
	//初期設定を行う
	dummy6->startUp();
	//画像データをロード
	dummy7->loadTileGraphics(tile_graph);
	//テーブルを生成
	dummy7->createTable();


	//ESCが入力されるまで実行
	while (CheckHitKey(KEY_INPUT_ESCAPE) != 1) {
		//タイルを出力
		table[0]->dispAll();
		//マウス関連の処理
		dummy5->inputMousePointer();
		
		//ゲームクリアか判定
		end_flag = dummy9->checkGameClear();
		//ゲームクリアの場合
		if (end_flag == 1) {
			//ゲームクリア処理
			dummy9->gameClearEnd();
			break;
		}
		//ゲームオーバーか判定
		end_flag = dummy8->checkGameOver();
		//ゲームオーバーの場合
		if (end_flag == 2) {
			//ゲームオーバー処理は、諸般の事情でUserInterfaceに
			break;
		}
		//一時的に後ろに移動
		dummy6->backGraund();
	}
}
