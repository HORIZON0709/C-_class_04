//===================================================
//
//授業その3[enemy.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//********************************
//敵のクラス定義
//********************************
class CEnemy
{/* 基本クラス */
public:		/* 列挙型の定義 */
	enum class TYPE
	{//種類
		NONE = 0,
		HUMAN,	//人型
		BIRD,	//鳥型
		MAX,
	};

public:		/* 定数の定義 */
	static const int MAX_ENEMY = 5;		//最大数
	static const int MIN_ENEMY = 1;		//最少数

public:		/* 静的メンバ関数宣言 */
	static CEnemy* Create(TYPE type);	//生成
	static void ReleaseAll();			//全ての敵の破棄
	static void OutputAll();			//全ての敵を出力
	static int GetNumAll();				//総数を取得
	static int GetNumHuman();			//人型の数を取得
	static int GetNumBird();			//鳥型の数を取得
private:
	static void OutputNum();

public:		/* コンストラクタ・デストラクタ */
	CEnemy();
	CEnemy(TYPE type);
	virtual ~CEnemy();

public:		/* メンバ関数宣言 */
	virtual void Init();	//初期化
	virtual void Input();	//入力
	virtual void Output();	//出力
	virtual void Uninit();	//終了

private:	/* 静的メンバ変数宣言 */
	static CEnemy* m_apEnemy[MAX_ENEMY];	//ポインタ配列
	static int m_nNumAll;					//総数
	static int m_nNumHuman;					//人型の数
	static int m_nNumBird;					//鳥型の数

private:	/* メンバ変数宣言 */
	int m_nLife;		//体力
	int m_nAttack;		//攻撃力

};

#endif