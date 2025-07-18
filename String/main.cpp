#include<iostream>
using namespace std;

#define delimiter "--------------------------\n"

class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	explicit String(int size = 80):size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const String& other):String(other.str)
	{
		//this->size = other.size;
		//// s->str = other.str;
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)
		//	this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}

	String(const char* str):String(strlen(str)+1)
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)this->str[i] = str[i];

		cout << "Constructor:\t\t" << this << endl;
	}
	String(String&& other):size(other.size), str(other.str)
	{
		//this->size = other.size;
		//this->str = other.str;

		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		str = nullptr;
		size = 0;
		cout << "Destructor:\t\t" << this << endl;
	}

	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)noexcept
	{
		if (this == &other)return *this;
		delete[] str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}

	char operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "str:\t" << str << endl;

	}
};
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result[i] = left[i];
		//result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result[i + left.get_size() - 1] = right[i];
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;

}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
void Clear(char* str)
{
	delete[] str;


}
//#define CONSTRUCTORS_CHECK
//#define COPY_SEMANTIC_CHEK

void main()
{
	setlocale(LC_ALL, "");

	int a = 2;
	a = 3;

#ifdef CONSTRUCTORS_CHECK
	String str1;
	str1.print();

	String str2(5);
	str2.print();

	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;

	String str4 = "World";
	cout << str4 << endl;

	cout << delimiter << endl;
	String str5;
	str5 = str3 + str4;
	cout << delimiter << endl;
	cout << str5 << endl;

#endif // CONSTRUCTORS_CHECK

#ifdef COPY_SEMANTIC_CHEK


	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	String str2 = str1;
	str2 = str1;
	cout << str2 << endl;

#endif // COPY_SEMANTIC_CHEK


  /*
	char* str = new char[8] {"Hello" };
	   cout << str << endl;
	   //delete[]str;
       //delete[]str;
	   Clear(str);
	   Clear(str);


	   //int arr[] = { 3,5,8,13,21 };
	   //delete[]arr;

  */


	String str1;
	str1.print();

	String str3 = "Hello";
	str3.print();

	String str2(5);
	str2.print();

	String str4();
	//если есть необходимость явно вызвать конструктор по у
	//str4  


	String str5{};//А эта строка уже явно вызывает 
	str5.print();


	String str6{ 6 };//Singl-ar
	str6.print();

	String str7{ "World" };
	str7.print();

	String str8 = str7;
	str8.print();

	String str9(str8);
	str9.print();
	   

	String str10{ str9 };
	str10.print();

	//!!! Фигурные скобки для вызова конструкторов следует использовать с большой осторожностью

	String str11 = str3 + str8;
	str11.print();


}