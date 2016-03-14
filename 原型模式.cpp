/*
*	ԭ��ģʽ	Դ�ļ�
*/

#include <iostream>
#include "ԭ��ģʽ.h"

using namespace std;

namespace yx
{
	class CProduct
	{
	public:
		virtual ~CProduct() {};
		virtual CProduct* clone() = 0;
		virtual void use() = 0;		//ʹ�ò�Ʒ
		virtual	void set(int num) = 0;	//���ò�Ʒ
	};

	class CProductA : public CProduct
	{
	public:
		CProductA(int num) : m_num(num) {};

		virtual ~CProductA() {};

		CProductA(CProductA& product)	//�������캯��,ע����ǳ��������
		{
			this->m_num = product.m_num;
		};

		virtual	void set(int num)
		{
			cout << "change number to " << num << endl;
			this->m_num = num;
		};

		virtual CProduct* clone()
		{
			return new CProductA(*this);
		};

		virtual void use()
		{
			cout << "i am product A, my number is " << this->m_num << endl;
		};

	private:
		int m_num;
	};

	void test_yx()
	{
		/*
		ԭ��ģʽ���ʹ�ÿ����������ŵ�:
		1, ����һ�����ϵͳ�д���һ������ָ��,����Ҫ�Դ�����п���,
		ԭ��ģʽ����cloneһ�¼��ɿ�������ȷ��������,������������Ҫ֪���÷��ϵͳ��
		�û���ָ������ָ���������,�ſ��Ե��ø�������Ŀ�������
		2, ԭ��ģʽ�����������ʹ�ù�����,��̬�ĸı�һЩ������,��ȷ�Ŀ�¡����������(�����Ų����ı䶯),ԭ���Ķ������ɾ���Ȳ���.���ж�̬ɾ�����ӵĺô�.
		3, ԭ��ģʽ��,ֻ��̳к���clone()�ĳ������,�����ʱclone,ʹ�ù�����,��ͳһ��ʹ�û���ָ��,�������һЩ������Ĳ���
		*/

		cout << "\n----ԭ��ģʽ----\n";
		CProduct* product1 = new CProductA(1);
		product1->use();	//ʹ�ò�Ʒ
		product1->set(2);	//���Ĳ�Ʒ����
		CProduct* product2 = product1->clone();		//��¡��Ʒ,���ָ��ĵĲ�����Ϣ
		delete product1;	//�Ѿ���¡,������ʱdelete��û������
		
		product2->use();
		
		delete product2;
	};
};