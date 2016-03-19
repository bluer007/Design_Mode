/*
*	ԭ��ģʽ	Դ�ļ�
*/

#include <iostream>
#include "������ģʽ.h"

using namespace std;

namespace spq
{
	class XiaoMi
	{
	public:
		virtual ~XiaoMi() {};	//��Ҫ��Ϊ����, �������������
		virtual void use()		//���ⲿ����������ͽӿ�
		{
			cout << "i am xiao mi" << endl;
		};
	};

	class XiaoMi2s
	{
	public:
		void useXiaoMi2s()	//ʵ������õĽӿ�
		{
			cout << "i am xiao mi 2s" << endl;
		};
	};

	class Adapter : public XiaoMi, public XiaoMi2s		//��������, �������඼�̳�
	{
	public:
		//Adapter() {};
		virtual void use()	//�������ӿ�, ���ⲿ�������ӿ���һ��
		{
			XiaoMi2s::useXiaoMi2s();	//��__super::useXiaoMi2s();
		};
	};

	class Adapter2 : public XiaoMi		//����������, ���̳�һ����,��ʹ�����Ա������ʹ����һ����
	{
	public:
		//Adapter2() {};
		virtual void use()
		{
			m_xiaomi2s.useXiaoMi2s();
		};

	private:
		XiaoMi2s m_xiaomi2s;	//��Ȼָ��Ҳ��
	};

	void test_spq()
	{
		cout << "\n----������ģʽ----" << endl;
		//�ⲿ����, �������Ľӿ���XiaoMi���use()�ӿ�
		XiaoMi* xiaomi = new Adapter();		//��������
		xiaomi->use();		//ʵ�ʵ�����С��2s�Ľӿ�
		delete xiaomi;
		xiaomi = nullptr;
		
		xiaomi = new Adapter2();	//����������
		xiaomi->use();		//ʵ�ʵ�����С��2s�Ľӿ�
		delete xiaomi;
		xiaomi = nullptr;
	};
};