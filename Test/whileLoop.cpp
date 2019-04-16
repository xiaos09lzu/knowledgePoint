#include <stdlib.h>
#include <memory>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Animal
{
public:
	Animal(){ cout << "Animal constructor... " << endl; initialize(); }
	virtual ~Animal() = default;
	virtual string getMyName()const{
		return string(myName);
	}

	/*virtual*/ string likesToEat()const{
		return "snacks";
	}
protected:
	char myName[12];
	virtual void initialize(){
		cout << "Animal initialize... " << endl;
		strcpy(myName, "Animal");
	}
};

class Bear : public Animal
{
public:
	Bear() :Animal(){ cout << "Bear constructor... " << endl; initialize(); }
	virtual string likesToEat()const{
		return "honey";
	}
	//virtual string getMyName()const{
	//	return string(myName);
	//}

protected:
	char myName[12];
	virtual void initialize() override{
		cout << "Bear initialize... " << endl;
		strcpy(myName, "Teddy");
	}
};

void main()
{
	//shared_ptr<Animal> animal(new Bear);
	Animal* animal = (Animal*)(new Bear);
	cout << sizeof(*animal) << endl;
	cout << animal->getMyName() << " like to eat "
		<< animal->likesToEat() << endl;

	system("pause");
	////按照我们的理解，int占用4个字节，应该相差4个字节。
	////这是因为VS在Debug模式下，int变量占用12个字节。
	////可以这样认为，Debug模式下，在int变量的前后各增加了4个字节，用于存储调试信息。
	////当我们把模式设为Release，就会发现栈上连续定义的int变量，地址相差4个字节
	//int a = 0;
	//int size = 2;
	//while (a < size)
	//{
	//	int i = 0;
	//	cout << "i = " << i << ", &i = " << &i << endl;

	//	int j = 10;
	//	cout << "j = " << j << ", &j = " << &j << endl;

	//	int k = 15;
	//	cout << "k = " << k << ", &k = " << &k << endl;

	//	cout << endl;
	//	a++;
	//	system("pause");
	//}

	//char s[] = "10";
	//printf("%s\n", s);
	//printf("s[1]:%d\n", s[1]);
	//printf("s[2]:%d\n", s[2]);
	//printf("s[1]:%c\n", s[1]);
	//printf("s[2]:%c\n", s[2]);

	//char u[] = { "hello" };
	//cout << sizeof(u) / sizeof(*u) << endl;
	//char v[] = "hello";
	//cout << sizeof(v) / sizeof(*v) << endl;

	//system("pause");
}

//全局变量，局部变量，静态局部变量
//void func();
//int n = 1; //全局变量
//void main()
//{
//	static int a; // 静态局部变量
//	int b = -10; // 局部变量
//	cout << "a:" << a
//		<< " b:" << b
//		<< " n:" << n << endl;
//	b += 4;
//	func();
//	cout << "a:" << a
//		<< " b:" << b
//		<< " n:" << n << endl;
//	n += 10;
//	func();
//	system("pause");
//}
//void func()
//{
//	static int a = 2; // 静态局部变量
//	int b = 5; // 局部变量
//	a += 2;
//	n += 12;
//	b += 5;
//	cout << "a:" << a
//		<< " b:" << b
//		<< " n:" << n << endl;
//}
