#include "MouseListener.h"
//#if DEBUG

extern Tile *table[];

MouseListener::MouseListener(){}


MouseListener::~MouseListener(){}

/*
*機能概要 : データの受け渡しを行うメソッド
*機能詳細 : マウス経由で取得したテーブルの位置座標を配列に合わせた形で変換
*@author : 西村宗高
*@version : 1
*@param : x(x座標)
*@param : y(y座標)
*@return : テーブルの座標(配列用)
*/
int MouseListener::convertTileCoordinates(int x, int y){
	//戻り値
	int ans = 0;

	//正しい座標であるか判定用の変数
	bool judge_coordinate = checkMousePointer(x,y);

	//明らかに正しくない座標であればfalse
	if (judge_coordinate == false) {
		return -1;
	}

	//初期値から原点に戻す
	x -= (BEGIN_X - GRAPHIC_GAP);
	y -= (BEGIN_Y - GRAPHIC_GAP);

	//初期値から横にいくらずれてるか確認
	x /= TILE_INTERVAL;

	//初期値から縦にいくらずれているか確認
	y /= TILE_INTERVAL;

	ans = X_MAX * y + x;

	//配列の値に変換
	return ans;
}
/*
*機能概要 : 旗を立てたり取ったりするメソッド
*機能詳細 : 旗があれば取り除き、旗がなければ旗をセットするためのメソッド
*@author : 西村宗高
*@version : 1
*@param : location(指定座標)
*@return : なし
*/
void MouseListener::flagTile(int location){
	bool flag;

	flag = table[location] -> getFlag();
	
	//旗がすでに立っている場合
	if (flag == true) {
		table[location]->setFlag(false);
	}
	else {
		table[location]->setFlag(true);
	}
}
/*
*機能概要 : マウスポインタがテーブル上にあるか確認するメソッド
*機能詳細 : GUI上においてマウスポインタがテーブル上にあるのか確認
*@author : 西村宗高
*@version : 1
*@param : x(x座標)
*@param : y(y座標)
*@return : true(テーブル上にある場合), false(テーブル上にない場合)
*/
bool MouseListener::checkMousePointer(int x, int y) {
	//x座標がテーブル上にない場合
	//左端よりも左
	if (x < (BEGIN_X - GRAPHIC_GAP)) {
		return false;
	}

	//右端よりも右
	//GUIを反映させるために式が長くなったが、できれば修正したい
	else if (x >(BEGIN_X + TILE_INTERVAL * (X_MAX - 1) + GRAPHIC_GAP - 1)) {
		return false;
	}

	//y座標がテーブル上にない場合
	//一番上よりも上
	else if (y < (BEGIN_Y - GRAPHIC_GAP)) {
		return false;
	}

	//一番下よりも下
	//GUIを反映させるために式が長くなったが、できれば修正したい
	else if (y > (BEGIN_Y + TILE_INTERVAL * (Y_MAX - 1) + GRAPHIC_GAP - 1)) {
		return false;
	}

	//最後までガードをパスしなければtrue
	return true;
}
/*
*機能概要 : 左クリックをお行った際の機能
*機能詳細 : 左クリックを行った際の機能
*@author : 西村宗高
*@version : 1
*@param : location(テーブル上の指定座標)
*@return : なし
*/

void MouseListener::inputLeftClick(int mouse_location){
	//メソッド生成
	SafeSpace *dummy3;
	dummy3 = new SafeSpace();
	GameOver *gameover;
	gameover = new GameOver();

	//安全地帯の場合
	if (table[mouse_location]->getStatus() == safespace) {
		//他の安全地帯を開放
		table[mouse_location]->setOpen(true);
		dummy3->searchAllSafeSpace(mouse_location);
	}
	//爆弾の場合
	else if (table[mouse_location]->getStatus() == bomb) {
		table[mouse_location]->setOpen(true);
		//テーブル出力
		dispAll();
		ScreenFlip();
		//メッセージ処理
		ProcessMessage();
		//ゲームオーバー
		gameover->gameOverEnd(mouse_location);
	}
	//危険地帯の場合
	else {
		//そのタイルを開けるだけ
		table[mouse_location]->setOpen(true);
	}
}
/*
*機能概要 : 右クリックを行った際の機能
*機能詳細 : 右クリックを行った際の機能
*@author : 西村宗高
*@version : 1
*@param : location(テーブル上の指定座標)
*@return : なし
*/
void MouseListener::inputRightClick(int mouse_location){
	MouseListener *dummy;
	dummy = new MouseListener();

	//タイルが開放されていたら何もしない
	if (table[mouse_location]->getOpen() == true);
	//タイルが閉じていたら旗の操作
	else {
		dummy->flagTile(mouse_location);
	}
}
/*
*機能概要 : マウスポインタを取得する機能
*機能詳細 : マウスの移動からクリックが行われるまでの機能
*@author : 西村宗高
*@version : 1
*@param : なし
*@return : なし
*/

void MouseListener::inputMousePointer(){
	//マウスの座標
	int mouse_x, mouse_y, mouse_location;
	//マウスの入力判定
	int mouse_input;
	//カウンタ変数
	int i = 0;
	//旗の数
	int flag_number;
	//インスタンス生成
	MouseListener *dummy;
	dummy = new MouseListener();
	TableController *table_instance;
	table_instance = new TableController();
	
	//マウスの座標を取得
	GetMousePoint(&mouse_x, &mouse_y);

	//マウスの座標を変換
	mouse_location = dummy->convertTileCoordinates(mouse_x, mouse_y);

	//マウスの座標に合うもののみ判定(テーブル外のものは判定しない)
	if (mouse_location >= 0) {
		//マウスの入力を取得
		mouse_input = GetMouseInput();
#if DEBUG
		DrawFormatString(0, 50, 100, "座標[%d,%d]", mouse_x, mouse_y);
		DrawFormatString(0, 100, 100, "mouse_location : %d", mouse_location);
		DrawFormatString(0, 150, 100, "mouse_input : %d", mouse_input);
#endif
		//旗の数をカウント
		flag_number = table_instance->checkFlagNumber();
		//爆弾数を出力
		DrawFormatString(0, 50, 100, "爆弾数 : %d", BOMB_NUMBER);
		DrawFormatString(0, 100, 100, "旗の数 : %d", flag_number);
		//タイルの状態


		//マウスの左クリックが入力された場合
		if (mouse_input == MOUSE_INPUT_LEFT) {
			i++;
			inputLeftClick(mouse_location);
		}
		//マウスの右クリックが入力された場合
		else if (mouse_input == MOUSE_INPUT_RIGHT) {
			inputRightClick(mouse_location);
		}
		//マウスがクリックされていれば、キャッチ
		do {
			mouse_input = GetMouseInput();
		} while (mouse_input != 0);
	}
}
