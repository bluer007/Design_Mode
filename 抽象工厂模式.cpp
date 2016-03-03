/*
*   ���󹤳�ģʽ	Դ�ļ�
*/

#include <iostream>
#include "���󹤳�ģʽ.h"
using namespace std;

namespace cxgc
{


	class IProduct
	{
	public:
		virtual ~IProduct() = 0;	//����Ϊ���麯��
		virtual void UseProduct() = 0;
	};
	IProduct::~IProduct() { cout << "~IProduct()\n"; };		//����д��������ܱ���

	class IFactory
	{
	public:
		virtual IProduct* CreateProduct() = 0;
		virtual ~IFactory() { cout << "~IFactory()\n"; };
	};

	class Shoe : public IProduct
	{
	public:
		Shoe() { cout << "Shoe()" << endl; };
		virtual ~Shoe() { cout << "~Shoe()" << endl; };
		virtual void UseProduct()
		{
			cout << "i am shoe -- product." << endl;
		};

	};

	class ShoeFactory : public IFactory
	{
	public:
		ShoeFactory() { cout << "ShoeFactory()" << endl; };
		virtual ~ShoeFactory() { cout << "~ShoeFactory()" << endl; };
		virtual IProduct* CreateProduct()
		{
			return new Shoe();
		};
	};


	void test_cxgc()
	{
		std::cout << "\n----���󹤳�ģʽ----\n";
		IFactory* pFactory = new ShoeFactory();
		IProduct* pProduct = pFactory->CreateProduct();
		pProduct->UseProduct();
		delete pProduct;
		delete pFactory;
	}

};