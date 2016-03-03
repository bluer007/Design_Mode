/***************************************
*	project name: Design Patterns
*	description: This is the practice about design mode.
*	author: Bluer
***************************************/
#include <iostream>
#include "�򵥹���ģʽ.h"
#include "���󹤳�ģʽ.h"
#include "װ����ģʽ.h"
#include "��������ģʽ.h"

using namespace std;

using zsq::test_zsq;		//װ����ģʽ
using cxgc::test_cxgc;		//���󹤳�ģʽ
using jdgc::test_jdgc;		//�򵥹���ģʽ
using gcff::test_gcff;		//��������ģʽ

enum
{
	ZSQ = 1,	//װ����ģʽ
	CXGC,		//���󹤳�ģʽ
	JDGC,		//�򵥹���ģʽ
	GCFF		//��������ģʽ
};

int main()
{
	char choose[3] = "";
	while (true)
	{
		cout << "Choose a number to show a design pattern,\nPress 'q' to quit." << endl;
		cout << "[1] װ����ģʽ\n";
		cout << "[2] ���󹤳�ģʽ\n";
		cout << "[3] �򵥹���ģʽ\n";
		cout << "[4] ��������ģʽ\n";

		cin.getline(choose, 3);
		if (choose[0] == 'q' || choose[0] == 'Q')
			return 0;
		switch (atoi(choose))
		{
		case ZSQ:
			test_zsq();	break;		//װ����ģʽ
		case CXGC:
			test_cxgc();	break;	//���󹤳�ģʽ
		case JDGC:
			test_jdgc();	break;	//�򵥹���ģʽ
		case GCFF:
			test_gcff();	break;	//��������ģʽ
		default:
			cout << "\nPlease choose a valid number.\n";	break;
		}
		system("echo, & pause & cls");
	}


	return 0;
}

