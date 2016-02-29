/*
*	װ����ģʽ
*/

#include <iostream>
#include <string>
using namespace std;

class Component		//�������, �ɱ���������װ��
{
public:
	virtual void use() = 0;
};

class Zhuji : public Component		//������, Ҫ��װ�����������
{
private:
	string str;
public:
	Zhuji() : str("����") {};
	 void use() 
	{
		cout << "����" << str << "--�������" << endl;		
	}
};

class Decorator : public Component		
{
public:
	Decorator(Component* com) : component(com){};
	 void use()
	{
		if (component)
			component->use();
	};

private:
	Component* component;
};

class Xianshiqi : public Decorator	//��ʾ����, װ����
{
public:
	Xianshiqi(Component* com) : Decorator(com), str("��ʾ��") {};

	 void use()
	{
		Decorator::use();
		cout << "װ��--" << str << endl;
	};

private:
	string str;
};

class Jianpan : public Decorator	//������, װ����
{
public:
	Jianpan(Component* com) : Decorator(com), str("����") {};
	 void use()
	{
		Decorator::use();
		cout << "װ��--" << str << endl;
	};

private:
	string str;
};


void test()
{
	cout << "----װ����ģʽ----" << endl;
	Component* component = new Zhuji();
	component->use();

	cout << "\n����װ��---\n";
	Decorator* decorator = new Xianshiqi(component);
	decorator->use();			//װ����ʾ��

	cout << "\n����װ��---\n";
	Decorator* decorator1 = new Jianpan(decorator);		//װ�ϼ���
	decorator1->use();
	delete decorator1;
	delete decorator;
	delete component;
}





