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
	////�������ǵ���⣬intռ��4���ֽڣ�Ӧ�����4���ֽڡ�
	////������ΪVS��Debugģʽ�£�int����ռ��12���ֽڡ�
	////����������Ϊ��Debugģʽ�£���int������ǰ���������4���ֽڣ����ڴ洢������Ϣ��
	////�����ǰ�ģʽ��ΪRelease���ͻᷢ��ջ�����������int��������ַ���4���ֽ�
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

//ȫ�ֱ������ֲ���������̬�ֲ�����
//void func();
//int n = 1; //ȫ�ֱ���
//void main()
//{
//	static int a; // ��̬�ֲ�����
//	int b = -10; // �ֲ�����
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
//	static int a = 2; // ��̬�ֲ�����
//	int b = 5; // �ֲ�����
//	a += 2;
//	n += 12;
//	b += 5;
//	cout << "a:" << a
//		<< " b:" << b
//		<< " n:" << n << endl;
//}
