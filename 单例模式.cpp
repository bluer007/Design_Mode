/*
*	����ģʽ	Դ�ļ�
*/

#include <iostream>
#include "����ģʽ.h"

using namespace std;

namespace dl
{
	//��������ʵ�����������(ʵ�����ļ���Դ��)�������ֶ�������ӿ�ʵ��
	class Singleton
	{
	public:
		static Singleton* getInstance()		//����ʵ�������Ψһ;��,���ܱ��ⲿ����,��Ϊstatic
		{
			//if (m_singleton == NULL)	����ʱ�������жϿɼ���Lock()���������ܸ���
			{
				//Lock();		����ʱ������������
				//û��thisָ��,ֻ�ܷ������static��Ա
				if (m_singleton == NULL)	//����ʱ��һ���жϿɱ�֤�̰߳�ȫ
				{
					m_singleton = new Singleton();
				}
				//Unlock();
			}
			return m_singleton;
		};
		
		void destryInstance()	//�ɿ������ֶ�����,��ȻҲ���Կ������ֶ�delete
		{
			if (this->m_singleton)
			{
				delete this->m_singleton;
				this->m_singleton = NULL;
			}
		};

		void use()
		{
			cout << "use class Singleton" << endl;
		};

	private:
		static Singleton* m_singleton;		//ͨ��static����������֤Ψһʵ��(������������)
		Singleton() { cout << "Singleton()\n"; };		//˽�л�Ψһ�Ĺ��캯��,�ʲ���ʵ������,ֻ��ͨ��getInstance()�����ʵ��. �Ҳ���д�����캯���ĺ�����,��Ϊnew����������ù��캯��

		~Singleton() { cout << "~Singleton()\n"; };		//��Ϊ������m_singleton�Ƿ��䵽����,��delete����,�����󲻻��Զ�����,����������������˽�л�(�����ⲿ�����ܵ���,�����ⲿdelete,ֻ�ܵ�����ӿ�destryInstance()����ʵ��)
	};

	Singleton* Singleton::m_singleton = NULL;	//��ʼ�����static��Ա


	//��������Ȼ���ؿ������ֶ�����ʵ��,���ǲ��ܴ����Զ��������������Դ����
	class Singleton2
	{
	public:
		static Singleton2& getInstance()
		{
			static Singleton2 single;	//���ñ��ӿ�ʱ,�Ŵ�����ʵ��,�������ʱ,ϵͳ�Զ����ٸþ�̬����.Ҳ����дΪ���Ա����,���ⲿ����Singleton2����ʱ���Զ�������ʵ��
			return single;
		};

		Singleton2(Singleton2& tmp)
		{
			cout << "Singleton2�������캯��" << endl;
		};

		void use()
		{
			cout << "use class Singleton2" << endl;
		};

		//��Ϊ������static Singleton2 single;�Ƿ��䵽ջ��,��������Զ�����,����������������˽�л�,ֻ��public
		~Singleton2() {
			cout << "����ģʽ������ʵ������ ~Singleton2()\n"; 
			system("pause");
		};
	private:
		Singleton2() { cout << "Singleton2()\n"; };

	};

	//������ʵ�����Զ�����ʵ�������������Դ�Ĺ���
	class Singleton3
	{
	public:
		static Singleton3& getInstance()
		{
			if (m_instance == NULL)
			{
				m_instance = new Singleton3();
			}
			return *m_instance;
		};

		void use()
		{
			cout << "use class Singleton3" << endl;
		};

	private:
		//FILE* m_file;		//�������ļ�����
		static Singleton3* m_instance;
		Singleton3() { cout << "Singleton3()\n"; };
		~Singleton3() { cout << "~Singleton3()\n"; };
		
		//ͨ��GC���Զ�����ʵ��������������Դ
		class GC
		{
		public:
			GC() 
			{ 
				//cout << "GC()\n"; 
			};

			~GC() 
			{ 
				cout << "����ģʽ������ʵ������������ ~GC() -- Began to clean up\n"; 
				//delete m_file;	���ٳ�ʵ���������������Դ
				if (m_instance)
				{
					delete m_instance;	//ͨ��GC���������������ʵ��
					m_instance = nullptr;
				}
				system("pause");
			};
		};

		static GC m_gc;		//�����˳�ʱ,�Զ����øþ�̬��Ա���������������������Դ
	};
	
	Singleton3* Singleton3::m_instance = nullptr;
	Singleton3::GC Singleton3::m_gc;	//��������ʱ,�Զ�����Singleton3::GC��Ĺ��캯��

	void test_dl()
	{
		cout << "\n----����ģʽ----\n";
		Singleton* single = Singleton::getInstance();
		single->use();
		//delete single;	����,��Singleton�������������˽�к���,ֻ������Ľӿ�������
		single->destryInstance();		//ʹ��������ֶ�����.
		cout << endl;

		Singleton2& single2 = Singleton2::getInstance();	//������ΪSingleton2 single2;������Singleton2��Ŀ������캯��
		single2.use();		//Singleton2ʹ�����,ϵͳ���Զ�����ʵ��
		cout << endl;

		Singleton3& single3 = Singleton3::getInstance();
		single3.use();		//Singleton2ʹ�����,ϵͳ���Զ�����ʵ����������Դ
		cout << endl;
	};

};