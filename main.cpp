/***************************************
*	project name: Design Patterns
*	description: This is the practice about design mode.
*	author: Bluer
***************************************/
#include <iostream>
#include "�򵥹���ģʽ.h"
#include "���󹤳�ģʽ.h"
#include "װ����ģʽ.h"

using namespace std;

using zsq::test_zsq;		//װ����ģʽ
using cxgc::test_cxgc;		//���󹤳�ģʽ
using jdgc::test_jdgc;		//�򵥹���ģʽ

enum
{
	ZSQ = '1',	//װ����ģʽ
	CXGC,		//���󹤳�ģʽ
	JDGC		//�򵥹���ģʽ
};

int main()
{
	char choose[2] = "";
	while (true)
	{
		cout << "choose a number to show a design pattern,\npress 'q' to quit." << endl;
		cout << "[1] װ����ģʽ\n";
		cout << "[2] ���󹤳�ģʽ\n";
		cout << "[3] �򵥹���ģʽ\n";

		cin.getline(choose, 2);
		if (choose[0] == 'q' || choose[0] == 'Q')
			return 0;
		switch (choose[0])
		{
		case ZSQ:
			test_zsq();	break;		//װ����ģʽ
		case CXGC:
			test_cxgc();	break;	//���󹤳�ģʽ
		case JDGC:
			test_jdgc();	break;	//�򵥹���ģʽ
		}
		system("echo, & pause & cls");
	}


	return 0;
}

