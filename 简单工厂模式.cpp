/*
*	�򵥹���ģʽ	Դ�ļ�
*/

#include <iostream>
#include <string>
#include "�򵥹���ģʽ.h"

using namespace std;

namespace jdgc	//�򵥹���ģʽ�����ռ�
{
	class IProduct
	{
	public:
		IProduct() { cout << "IProduct()" << endl; };
		virtual ~IProduct() { cout << "~IProduct()" << endl; };
		virtual void Use() = 0;
	};

	class IFactory
	{
	public:
		IFactory() { cout << "IFactory()" << endl; };
		virtual ~IFactory() { cout << "~IFactory()" << endl; };
		virtual IProduct* CreateProduct(string) = 0;
	};

	class RedMi : public IProduct
	{
	public:
		RedMi() { cout << "RedMi()" << endl; };
		~RedMi() { cout << "~RedMi()" << endl; };
		virtual void Use()
		{
			cout << "i am RedMi-----------" << endl;
		};

	};

	class XiaoMi : public IProduct
	{
	public:
		XiaoMi() { cout << "XiaoMi()" << endl; };
		~XiaoMi() { cout << "~XiaoMi()" << endl; };
		virtual void Use()
		{
			cout << "i am XiaoMi----------" << endl;
		};
	};

	class XiaoMiFactory : public IFactory
	{
	public:
		XiaoMiFactory() { cout << "XiaoMiFactory()" << endl; };
		virtual ~XiaoMiFactory() { cout << "~XiaoMiFactory()" << endl; };
		virtual IProduct* CreateProduct(string type)
		{
			if (type == "xiaomi")
				return new XiaoMi();
			if (type == "redmi")
				return new RedMi();

			return NULL;
		};
	};

	void test_jdgc()	//�򵥹����Ĳ�������
	{
		cout << "\n----�򵥹���ģʽ----" << endl;

		IFactory* factory = new XiaoMiFactory();
		IProduct* xiaomi = factory->CreateProduct("xiaomi");
		xiaomi->Use();
		IProduct* redmi = factory->CreateProduct("redmi");
		redmi->Use();
		delete factory;
		delete xiaomi;
		delete redmi;
	};






};
