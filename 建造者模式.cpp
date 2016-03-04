/*
*	������ģʽ	Դ�ļ�
*/


#include <iostream>
#include "������ģʽ.h"

using namespace std;

namespace jzz
{
	class IPerson		//��Ʒ��,����Ҫ������(����)����
	{
	public:
		void setType(string str) { this->type = str; };
		void setBody(int body) { this->param_body = body; };
		void setHead(int head) { this->param_head = head; };
		void setHand(int hand) { this->param_hand = hand; };
		void setFoot(int foot) { this->param_foot = foot; };
		void Use()		//��Ʒ��ʹ�ýӿ�
		{
			cout << "\ni am "<<type.c_str()<<".\n";
			cout << "body length: " << param_body << endl;
			cout << "head length: " << param_head << endl;
			cout << "hand length: " << param_hand << endl;
			cout << "foot length: " << param_foot << endl;
		};
	private:
		string type;
		int param_body;
		int param_head;
		int param_hand;
		int param_foot;
	};

	class IPersonBuilder	//�����߳�����,������������(����),���нӿ�
	{
	public:
		virtual ~IPersonBuilder() {};	//��д�ɴ�����������,����д��������.��ֱ���ÿ�ʵ�ִ���
		virtual void CreateBody(int param) = 0;
		virtual void CreateHead(int param) = 0;
		virtual void CreateHand(int param) = 0;
		virtual void CreateFoot(int param) = 0;

		virtual IPerson* GetPerson() = 0;
	};

	class FatPersonBuilder : public IPersonBuilder	//������,���������Լ���ɫ�ĸ������(����)
	{
	public:
		virtual ~FatPersonBuilder() { cout << "~FatPersonBuilder()\n"; };
		FatPersonBuilder() 
		{ 
			this->m_person = new IPerson(); 
			this->m_person->setType("fat person");
		};

		virtual void CreateBody(int param) 
		{ 
			this->m_person->setBody(param);
			cout << "create fat body-----" << param << endl;
		};

		virtual void CreateHead(int param) 
		{
			this->m_person->setHead(param);
			cout << "create fat head-----" << param << endl;
		};

		virtual void CreateHand(int param)
		{
			this->m_person->setHand(param);
			cout << "create fat hand-----" << param << endl;
		};

		virtual void CreateFoot(int param)
		{
			this->m_person->setFoot(param);
			cout << "create fat foot-----" << param << endl;
		};
		
		virtual IPerson* GetPerson()
		{
			return this->m_person;
		};

	private:
		IPerson* m_person;
	};

	class PersonDirector	//�����ָ����,ָ���Ѹ������(����) ������ ��װ����
	{
	public:
		PersonDirector(IPersonBuilder* per) : m_per(per) {};
		
		void CreatePerson(int body,int head, int hand, int foot)
		{
			cout << "start to create person\n";
			this->m_per->CreateBody(body);
			this->m_per->CreateHead(head);
			this->m_per->CreateHand(hand);
			this->m_per->CreateFoot(foot);
			cout << "create person complete\n";
		};

	private:
		IPersonBuilder* m_per;
	};

	void test_jzz()
	{
		cout << "\n----������ģʽ----\n";
		//builder�������Ʒ��ÿһ������(���)
		IPersonBuilder* builder = new FatPersonBuilder();

		PersonDirector director(builder);
		
		//�ɴ���ͬ����,��ʾ�ɰ�������(��װ)��ͬ�Ĳ�Ʒ(person)
		director.CreatePerson(1,2,3,4);

		//��ȡ��װ��ϵĲ�Ʒ,���ظ�person
		IPerson* person = builder->GetPerson();
		//ʹ�ò�Ʒ
		person->Use();

		delete person;
		delete builder;
	};
};