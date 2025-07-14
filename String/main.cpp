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

	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		// s->str = other.str;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		str = nullptr;
		size = 0;
		cout << "Destructor:\t\t" << this << endl;
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
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
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


void main()
{
	setlocale(LC_ALL, "");
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

	String str5 = str3 + str4;
	cout << str5 << endl;

#endif // CONSTRUCTORS_CHECK


	String str1 = "Hello";
	cout << str1 << endl;

	String str2 = str1;
	cout << str2 << endl;





	/*
   char* str = new char[8] {"Hello" };
	   cout << str << endl;
	   //dlete[]str;
   //delete[]str;
	   Clear(str);
	   Clear(str);


	   int arr[] = { 3,5,8,13,21 };
	   delete[]arr;

	   */
}