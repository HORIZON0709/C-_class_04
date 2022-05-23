//===================================================
//
//���Ƃ���4[enemy.cpp]
//Author:KishimotoEiji
//
//===================================================

//********************************
//�C���N���[�h
//********************************
#include "enemy.h"
#include "enemyHuman.h"
#include "enemyBird.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//********************************
//�ÓI�����o�ϐ�
//********************************
CEnemy* CEnemy::m_apEnemy[CEnemy::MAX_ENEMY] = {};	//�|�C���^

int CEnemy::m_nNumAll = 0;		//����
int CEnemy::m_nNumHuman = 0;	//�l�^�G�̐�
int CEnemy::m_nNumBird = 0;		//���^�G�̐�

//===================================================
//����
//===================================================
CEnemy* CEnemy::Create(TYPE type)
{
	int nIdx = m_nNumAll;	//�C���f�b�N�X���p

	switch (type)
	{//��ޖ��̏���
	case TYPE::HUMAN:	/* �l�^ */

		//�������̓��I�m��
		m_apEnemy[nIdx] = new CEnemyHuman;
		break;

	case TYPE::BIRD:	/* ���^ */

		//�������̓��I�m��
		m_apEnemy[nIdx] = new CEnemyBird;
		break;

	case TYPE::NONE:	/* �I��͈͊O */
	case TYPE::MAX:
	default:
		assert(false);
		break;
	}

	if (m_apEnemy[nIdx] == nullptr)
	{//NULL�`�F�b�N
		assert(false);
	}

	/* nullptr�ł͂Ȃ� */

	//������
	m_apEnemy[nIdx]->Init();

	return m_apEnemy[nIdx];	//���I�m�ۂ������̂�Ԃ�
}

//===================================================
//�S�Ă̓G�̔j��
//===================================================
void CEnemy::ReleaseAll()
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (m_apEnemy[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͂Ȃ��ꍇ */

		//�I��
		m_apEnemy[i]->Uninit();

		//�������̉��
		delete m_apEnemy[i];
		m_apEnemy[i] = nullptr;
	}
}

//===================================================
//�S�Ă̓G���o��
//===================================================
void CEnemy::OutputAll()
{
	//���b�Z�[�W
	printf("\n �s �ݒ肵���G�̃X�e�[�^�X�͂����� �t");

	for (int i = 0; i < m_nNumAll; i++)
	{
		if (m_apEnemy[i] == nullptr)
		{//NULL�`�F�b�N
			continue;
		}

		/* nullptr�ł͖����ꍇ */

		//���̖ڂ��\��
		printf("\n\n ***** %d�̖� *****",(i + 1));

		//�o��
		m_apEnemy[i]->Output();
	}

	//����\��
	OutputNum();
}

//===================================================
//�������擾
//===================================================
int CEnemy::GetNumAll()
{
	return m_nNumAll;
}

//===================================================
//�l�^�̐����擾
//===================================================
int CEnemy::GetNumHuman()
{
	return m_nNumHuman;
}

//===================================================
//���^�̐����擾
//===================================================
int CEnemy::GetNumBird()
{
	return m_nNumBird;
}

//===================================================
//�G�̐���\��
//===================================================
void CEnemy::OutputNum()
{
	printf("\n\n �G�̑��� : [ %d ]", GetNumAll());
	printf("\n �l�^ : [ %d ]", GetNumHuman());
	printf("\n ���^ : [ %d ]", GetNumBird());
}

//===================================================
//�f�t�H���g�R���X�g���N�^
//===================================================
CEnemy::CEnemy()
{
	
}

//===================================================
//�I�[�o�[���[�h���ꂽ�R���X�g���N�^
//===================================================
CEnemy::CEnemy(TYPE type)
{
	//�����o�ϐ����N���A
	m_nLife = 0;
	m_nAttack = 0;

	//�������J�E���g�A�b�v
	m_nNumAll++;

	switch (type)
	{
	case TYPE::HUMAN:	/* �l�^ */
		
		//�����J�E���g�A�b�v
		m_nNumHuman++;
		break;

	case TYPE::BIRD:	/* ���^ */
		
		//�����J�E���g�A�b�v
		m_nNumBird++;
		break;

	case TYPE::NONE:	/* �͈͑I���O */
	case TYPE::MAX:
	default:
		assert(false);
		break;
	}
}

//===================================================
//�f�X�g���N�^
//===================================================
CEnemy::~CEnemy()
{
	/* �������� */
}