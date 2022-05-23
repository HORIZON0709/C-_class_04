//===================================================
//
//���Ƃ���4[enemy.h]
//Author:KishimotoEiji
//
//===================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//********************************
//�G�̃N���X��`
//********************************
class CEnemy
{/* ��{�N���X */
public:		/* �񋓌^�̒�` */
	enum class TYPE
	{//���
		NONE = 0,
		HUMAN,	//�l�^
		BIRD,	//���^
		MAX,
	};

public:		/* �萔�̒�` */
	static const int MAX_ENEMY = 5;		//�ő吔
	static const int MIN_ENEMY = 1;		//�ŏ���

public:		/* �ÓI�����o�֐��錾 */
	static CEnemy* Create(TYPE type);	//����
	static void ReleaseAll();			//�S�Ă̓G�̔j��
	static void OutputAll();			//�S�Ă̓G���o��
	static int GetNumAll();				//�������擾
	static int GetNumHuman();			//�l�^�̐����擾
	static int GetNumBird();			//���^�̐����擾
private:
	static void OutputNum();

public:		/* �R���X�g���N�^�E�f�X�g���N�^ */
	CEnemy();
	CEnemy(TYPE type);
	virtual ~CEnemy();

public:		/* ���z�֐��錾 */
	virtual void Init() = 0;	//������ (�������z�֐��u�` = 0;�v�c�֐��̎��Ԃ͕s�v)
	virtual void Input() = 0;	//����
	virtual void Output() = 0;	//�o��
	virtual void Uninit() = 0;	//�I��

private:	/* �ÓI�����o�ϐ��錾 */
	static CEnemy* m_apEnemy[MAX_ENEMY];	//�|�C���^�z��
	static int m_nNumAll;					//����
	static int m_nNumHuman;					//�l�^�̐�
	static int m_nNumBird;					//���^�̐�

protected:	/* �����o�ϐ��錾 */
	int m_nLife;
	int m_nAttack;
};

#endif