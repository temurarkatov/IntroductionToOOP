#pragma once
#include<iostream>
using namespace std;

#define delimiter "--------------------------\n"

/////////////////////////////////////////////////////////////////////
//////////////////   ќбъ€вление класса (Class declaration)  ///////////////




class String
{
	int size;
	char* str;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);

	String(String&& other);
	~String();

	String& operator=(const String& other);
	String& operator=(String&& other);

	char operator[](int i)const;
	char& operator[](int i);

	void print()const;
};

String operator+(const String& left, const String& right);
std::ostream& operator<<(std::ostream& os, const String& obj);

//////////////////    онец объ€влени€ класса (Class declaration)  ///////////////
/////////////////////////////////////////////////////////////////////


