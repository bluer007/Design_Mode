/*
*	���ģʽ	Դ�ļ�
*/

#include <iostream>
#include <string>
#include "���ģʽ.h"

using namespace std;

namespace wg
{
	class RedMi
	{
	public:
		RedMi(string name) : m_name(name) {};

		void DoSomething1()
		{
			cout << "i am RedMi , my name is " << m_name << endl;
		};

	private:
		string m_name;
	};

	class XiaoMi
	{
	public:
		XiaoMi(string name) : m_name(name) {};

		void DoSomething2()
		{
			cout << "i am XiaoMi , my name is " << m_name << endl;
		};

	private:
		string m_name;
	};

	class Facade
	{
	public:
		void DoSomething()
		{
			//���ģʽ��, �ⲿֻ�ܿ���Facade��, ��ֻ��ͨ��Facede��ӿ�����ڲ�ϵͳ���߼�
			string name_redmi = "����2";
			string name_xiaomi = "С��note3";
			RedMi redmi(name_redmi);
			XiaoMi xiaomi(name_xiaomi);
			redmi.DoSomething1();
			xiaomi.DoSomething2();
		};

	};


	void test_wg()
	{
		cout << "\n----���ģʽ----\n";
		//���ģʽ��, �ⲿֻ�ܿ���Facade��, ��ֻ��ͨ��Facede��ӿ�����ڲ�ϵͳ���߼�
		Facade facade;
		facade.DoSomething();

	}
};