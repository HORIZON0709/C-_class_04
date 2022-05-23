//===================================================
//
//授業その4[enemy.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//インクルード
//********************************
#include "enemy.h"
#include "enemyHuman.h"
#include "enemyBird.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//静的メンバ変数
//********************************
CEnemy* CEnemy::m_apEnemy[CEnemy::MAX_ENEMY] = {};	//ポインタ

int CEnemy::m_nNumAll = 0;		//総数
int CEnemy::m_nNumHuman = 0;	//人型敵の数
int CEnemy::m_nNumBird = 0;		//鳥型敵の数

//===================================================
//生成
//===================================================
CEnemy* CEnemy::Create(TYPE type)
{
	int nIdx = m_nNumAll;	//インデックス数用

	switch (type)
	{//種類毎の処理
	case TYPE::HUMAN:	/* 人型 */

		//メモリの動的確保
		m_apEnemy[nIdx] = new CEnemyHuman;
		break;

	case TYPE::BIRD:	/* 鳥型 */

		//メモリの動的確保
		m_apEnemy[nIdx] = new CEnemyBird;
		break;

	case TYPE::NONE:	/* 選択範囲外 */
	case TYPE::MAX:
	default:
		assert(false);
		break;
	}

	if (m_apEnemy[nIdx] == nullptr)
	{//NULLチェック
		assert(false);
	}

	/* nullptrではない */

	//初期化
	m_apEnemy[nIdx]->Init();

	return m_apEnemy[nIdx];	//動的確保したものを返す
}

//===================================================
//全ての敵の破棄
//===================================================
void CEnemy::ReleaseAll()
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (m_apEnemy[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrではない場合 */

		//終了
		m_apEnemy[i]->Uninit();

		//メモリの解放
		delete m_apEnemy[i];
		m_apEnemy[i] = nullptr;
	}
}

//===================================================
//全ての敵を出力
//===================================================
void CEnemy::OutputAll()
{
	//メッセージ
	printf("\n 《 設定した敵のステータスはこちら 》");

	for (int i = 0; i < m_nNumAll; i++)
	{
		if (m_apEnemy[i] == nullptr)
		{//NULLチェック
			continue;
		}

		/* nullptrでは無い場合 */

		//何体目か表示
		printf("\n\n ***** %d体目 *****",(i + 1));

		//出力
		m_apEnemy[i]->Output();
	}

	//数を表示
	OutputNum();
}

//===================================================
//総数を取得
//===================================================
int CEnemy::GetNumAll()
{
	return m_nNumAll;
}

//===================================================
//人型の数を取得
//===================================================
int CEnemy::GetNumHuman()
{
	return m_nNumHuman;
}

//===================================================
//鳥型の数を取得
//===================================================
int CEnemy::GetNumBird()
{
	return m_nNumBird;
}

//===================================================
//敵の数を表示
//===================================================
void CEnemy::OutputNum()
{
	printf("\n\n 敵の総数 : [ %d ]", GetNumAll());
	printf("\n 人型 : [ %d ]", GetNumHuman());
	printf("\n 鳥型 : [ %d ]", GetNumBird());
}

//===================================================
//デフォルトコンストラクタ
//===================================================
CEnemy::CEnemy()
{
	
}

//===================================================
//オーバーロードされたコンストラクタ
//===================================================
CEnemy::CEnemy(TYPE type)
{
	//メンバ変数をクリア
	m_nLife = 0;
	m_nAttack = 0;

	//総数をカウントアップ
	m_nNumAll++;

	switch (type)
	{
	case TYPE::HUMAN:	/* 人型 */
		
		//数をカウントアップ
		m_nNumHuman++;
		break;

	case TYPE::BIRD:	/* 鳥型 */
		
		//数をカウントアップ
		m_nNumBird++;
		break;

	case TYPE::NONE:	/* 範囲選択外 */
	case TYPE::MAX:
	default:
		assert(false);
		break;
	}
}

//===================================================
//デストラクタ
//===================================================
CEnemy::~CEnemy()
{
	/* 処理無し */
}