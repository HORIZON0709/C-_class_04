//===================================================
//
//授業その3[main.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "main.h"
#include "enemy.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//定数の定義
//********************************
namespace
{

}// namespaceはここまで

//********************************
//スタティック変数
//********************************
namespace
{

}// namespaceはここまで

//********************************
//プロトタイプ宣言
//********************************
namespace
{
void Init();
void Input();
void Output();
void Uninit();

int SetNumEnemy();
CEnemy::TYPE SelectType();
}// namespaceはここまで

//===================================================
//メイン関数
//===================================================
void main(void)
{
	//初期化
	Init();
	
	//入力
	Input();

	//出力
	Output();

	//終了
	Uninit();

	//終了メッセージ & Enter入力待ち
	printf("\n\n プログラムを終了します。お疲れ様でした。");
	PressEnter();
}

//===================================================
//Enter入力待ち
//===================================================
void PressEnter()
{
	//Enter入力待ち
	printf("\n\n Press Enter");
	rewind(stdin);
	getchar();
}

namespace
{
//---------------------------------------------------
//初期化
//---------------------------------------------------
void Init()
{
	//全ての敵の破棄
	CEnemy::ReleaseAll();
}

//---------------------------------------------------
//入力
//---------------------------------------------------
void Input()
{
	//敵の数を設定
	int nNumEnemy = SetNumEnemy();

	for (int i = 0; i < nNumEnemy; i++)
	{
		//何体目か表示
		printf("\n 《 %d体目 》", (i + 1));

		//敵の種類を選択
		CEnemy::TYPE type = SelectType();

		//敵の生成
		CEnemy* pEnemy = CEnemy::Create(type);

		if (pEnemy == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrでは無い場合 */

		//入力
		pEnemy->Input();

		//画面をクリア
		system("cls");
	}
}

//---------------------------------------------------
//出力
//---------------------------------------------------
void Output()
{
	//全ての敵を出力
	CEnemy::OutputAll();
}

//---------------------------------------------------
//終了
//---------------------------------------------------
void Uninit()
{
	//全ての敵の破棄
	CEnemy::ReleaseAll();
}

//---------------------------------------------------
//敵の数を設定
//---------------------------------------------------
int SetNumEnemy()
{
	int nNumEnemy = 0;	//敵の数設定用

	while (1)
	{
		//メッセージ
		printf("\n 敵の数を設定( %d～%d体まで ) > ", CEnemy::MIN_ENEMY, CEnemy::MAX_ENEMY);
		scanf("%d", &nNumEnemy);

		if ((nNumEnemy >= CEnemy::MIN_ENEMY) && (nNumEnemy <= CEnemy::MAX_ENEMY))
		{//範囲内
			break;
		}

		/* 範囲外 */

		//メッセージ & Enter入力待ち
		printf("\n ※※※ 範囲外です ※※※");
		PressEnter();

		//画面をクリア
		system("cls");
	}

	//画面をクリア
	system("cls");

	return nNumEnemy;	//設定した敵の数を返す
}

//---------------------------------------------------
//敵の種類を選択
//---------------------------------------------------
CEnemy::TYPE SelectType()
{
	CEnemy::TYPE selectType;	//敵の種類選択用

	while (1)
	{
		//メッセージ
		printf("\n 《 敵の種類を選択 》");
		printf("\n [%d] 人型", CEnemy::TYPE::HUMAN);
		printf("\n [%d] 鳥型", CEnemy::TYPE::BIRD);
		printf("\n 番号を入力 > ");
		scanf("%d", &selectType);

		if ((selectType > CEnemy::TYPE::NONE) && (selectType < CEnemy::TYPE::MAX))
		{//範囲内
			break;
		}

		/* 範囲外 */

		//メッセージ & Enter入力待ち
		printf("\n ※※※ 範囲外です ※※※");
		PressEnter();

		//画面をクリア
		system("cls");
	}

	return selectType;	//選択した敵の種類を返す
}
}