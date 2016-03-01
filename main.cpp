/***************************************
*	project name: Design Patterns
*	description: This is the practice about design mode.
*	author: Bluer
***************************************/
#include <iostream>
using namespace std;

extern void test_ZhuangShiQi();		//װ����ģʽ
extern void test_ChouXiangGongChang();		//���󹤳�ģʽ

enum
{
	ZhuangShiQi = '1',		//װ����ģʽ
	ChouXiangGongChang		//���󹤳�ģʽ
};

int main()
{
	char choose[2] = "";
	while (true)
	{
		cout << "choose a number to show a design pattern,\npress 'q' to quit." << endl;
		cout << "[1] װ����ģʽ" << endl;
		cout << "[2] ���󹤳�ģʽ" << endl << endl;

		cin.getline(choose, 2);
		if (choose[0] == 'q' || choose[0] == 'Q')
			return 0;
		switch (choose[0])
		{
		case ZhuangShiQi:
			test_ZhuangShiQi();	break;		//װ����ģʽ
		case ChouXiangGongChang:
			test_ChouXiangGongChang();	break;	//���󹤳�ģʽ
		
		}
		system("echo, & pause & cls");
	}

	
	return 0;
}

