//===================================================
//
//授業その3[enemyHuman.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _ENEMYHUMAN_H_
#define _ENEMYHUMAN_H_

#include "enemy.h"

//********************************
//人型の敵のクラス定義
//********************************
class CEnemyHuman : public CEnemy
{/* CEnemyの派生クラス */
public:		/* コンストラクタ・デストラクタ */
	CEnemyHuman();
	~CEnemyHuman()override;

public:		/* メンバー関数宣言 */
	void Init()override;	//初期化
	void Uninit()override;	//終了
	void Input()override;	//入力
	void Output()override;	//出力

private:	/* メンバー変数宣言 */
	int m_nSpeedWalk;	//歩くスピード
};

#endif