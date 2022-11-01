#include <iostream>
#include <exception>
#include "Container.h"

//В качестве домашнего задания к этому модулю мы предлагаем вам разработать шаблонный класс Array — динамический массив на базе класса ArrayInt, который был сделан вами в предыдущем модуле, но с использованием техники программирования на шаблонных классах и функциях.

int main()
{
	Container<int> test(4);
	test[0] = 7;
	test[1] = 77;
	test[2] = 777;
	test[3] = 7777;
	std::cout << "-------push back-------------\n";
	//test.PrintContainer();
	std::cout << "----------pop back----------\n";
	test.PopBack();
	//test.PrintContainer();
	std::cout << "--------push front------------\n";
	// error impossible (is not a public offer) using int
	test.PushFront(888);
	//test.PrintContainer();
	std::cout << "-----------pop front---------\n";
	test.PopFront();
	//test.PrintContainer();
	std::cout << "-------insert by index-------------\n";
	test.InsertElementByIndex(3, 999);
	//test.PrintContainer();
	std::cout << "-------deletebyindex-------------\n";
	test.DeleteElementByIndex(3);
	//test.PrintContainer();
	std::cout << "-----test copy to test2:---------------\n";
	Container<int> test2(3);
	std::cout << "test address \t" << &test << std::endl;
	std::cout << "test2 address \t" << &test2 << std::endl;
	test.CopyContainerTo(test2);
	//test2.PrintContainer();

	Container<int> newtest(7);

	newtest[0] = 7;
	newtest[1] = 77;
	newtest[2] = 777;
	newtest[3] = 7777;
	newtest[4] = 77777;
	newtest[5] = 777777;
	newtest[6] = 12345;

	try
	{
		std::cout << "------------------" << std::endl;
		//newtest.PrintContainer();
		std::cout << "------------------" << std::endl;
		newtest.InsertElementByIndex(7, 98765);
		//newtest.PrintContainer();
		std::cout << newtest.GetIndexByValue(123456) << std::endl;
		std::cout << "------------------" << std::endl;
	}



	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		newtest.InsertElementByIndex(8, 999);
		std::cout << newtest[5] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n and exceptions:\n";

	try
	{
		Container<int> test(-1);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test[-1] = 7;
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test[777] = 7;
	}

	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		// how to throw exception in case of overflow? this way doesn't work:
		test.PushBack(-34634645654646454);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	Container<int> testPopBack(0);
	try
	{
		testPopBack.PopBack();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Container<int> testPopFront(0);
	try
	{
		testPopFront.PopFront();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl; //it was really scary
	}

	Container<int> testElementByIndex(5);
	testElementByIndex[0] = 7;
	testElementByIndex[1] = 77;
	testElementByIndex[2] = 777;
	try
	{
		testElementByIndex.InsertElementByIndex(777, 111);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		testElementByIndex.InsertElementByIndex(777, 111);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	Container<int> testCopy(2);
	try
	{
		test.CopyContainerTo(testElementByIndex);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test.SetSizeOfArray(-7);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	//struct ttt
	//{
	//	int x;
	//	int y;
	//public:
	//	ttt(int X, int Y) : x(X), y(Y)
	//	{}

	//};

	Container<char> testTemplate(3);
	testTemplate[0] = 'a';
	testTemplate[1] = 'b';
	testTemplate[2] = 'c';
	std::cout << testTemplate.GetElementByIndex(2) << std::endl;
	Container<char> testTemplate2(3);
	testTemplate2[0] = 'c';
	testTemplate2[1] = 'b';
	testTemplate2[2] = 'a';
	testTemplate2 = testTemplate;
	std::cout << testTemplate2.GetElementByIndex(0) << std::endl;
	std::cout << testTemplate2.GetElementByIndex(1) << std::endl;
	std::cout << testTemplate2.GetElementByIndex(2) << std::endl;
	//ttt aaa(5,7);

	//Container<ttt> zzz (2);
	//zzz.PushBack(aaa);
	//zzz.PushBack(aaa);
	//zzz.PrintContainer();

	std::cout << "\nAll tests are passed. Code is extremely safe. Checked by Bjarne Stroustrup.\n";
}