#include<iostream>
using namespace std;

class Fraction;
class Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);


class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = numerator;
	}
	void set_numerator(int numerator)
	{
		this->numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:" << this << endl;
	}
	Fraction(double decimal)
	{
		integer = decimal;
		decimal -= integer;
		denominator = 1e-10;
		numerator = decimal * denominator;
		reduce();
		cout << "SingleArgumentConstructor: " << this << endl;


	}


	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}



	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction& operator++()
	{
		integer++;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}Fraction& operator--()
	{
		integer--;
		return *this;
	}

	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}

	explicit operator int()const
	{
		//to_improper();
		return integer + numerator / denominator;
	}

	operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;
		numerator /= GCD;
		denominator /= GCD;
		return *this;

	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}


};
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	);
}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denomiratir() * right.get_denomiratir());
	return result;*/
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denomiratir() * right.get_denomiratir()
	);
	result.to_proper();
	return result;
}*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

bool operator ==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}

bool operator!=(const Fraction& left, const Fraction& right)
{
	return!(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator()*right.get_denominator() <
		right.get_numerator()*left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return left > right || left == right;
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return!(left > right);
	//return left < right || left == right;
}

std::ostream& operator << (std::ostream& os, const Fraction& obj)
{

	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);
	int n = 0;
	const char delimiters[] = "(/, )";
	int numbers[3] = {};
	for (
		char* pch = strtok(buffer, delimiters);
		pch && n<3;
		pch=strtok(NULL, delimiters))
		numbers[n++] = atoi(pch);
	//for (int i = 0; i < n; i++)cout << numbers[i] << "\t";cout << endl;
	switch (n)
	{
	case 0: obj = Fraction(); break;
	case 1: obj = Fraction(numbers[0]); break;
	case 2: obj = Fraction(numbers[0], numbers[1]); break;
	case 3: obj = Fraction(numbers[0], numbers[1], numbers[2]); break;

	}
	return is;
}

//#define CONSTRUCTORS_CHEK
//#define AITHMETICAL_OPERATORS_CHECK
//#define INCREMENTO_DECREMENTO_CECK
//#define COMPERISON_OPERATORS
//#define STREAMS_CHECK
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define HAVE_A_NICI_DAY

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHEK
	  
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
	

#endif //CONSTRUCTORS_CHEK

#ifdef  AITHMETICAL_OPERATORS_CHECK
	double a = 2.7;
	double b = 3.14;
	double c = a * b;

	Fraction A(2, 3, 4);
	A.print();
	Fraction B( 3, 4, 5);
	B.print();

	Fraction C = A * B;
	C.print();

	/*C = A / B;
	C.print();

	A *= b;
	A.print();

	A /= B;
	A.print();*/

	C = A + B;
	C.print();
#endif // AITHMETICAL_OPERATORS_CHECK

#ifdef INCREMENTO_DECREMENTO_CECK

	double a = 2;
	double b = 0;
	b += a++;
	cout << a << endl;
	cout << b << endl;

	Fraction A(2, 3, 4);
	Fraction B ;
	B *= A++;
	A.print();
	B.print();
#endif //INCREMENTO_DECREMENTO_CECK

#ifdef COMPERISON_OPERATORS



	cout << (2 == 3) << endl;
	cout << (Fraction(1, 2) <= Fraction(5, 11)) << endl;

#endif // COMPERISON_OPERATORS

#ifdef STREAMS_CHECK

	Fraction A(2, 3, 4);
	cout << "������� ������� �����: ";
	cin >> A;
	cout << A << endl;

#endif // STREAMS_CHECK

#ifdef CONVERSION_FROM_OTHER_TO_CLASS



	Fraction A = (Fraction)5;
	cout << A << endl;

	Fraction B;
	B = Fraction(8);

#endif // CONVERSION_FROM_OTHER_TO_CLASS


#ifdef CONVERSION_FROM_CLASS_TO_OTHER

	Fraction A(2, 3, 4);
	A.to_improper().print();
	int a = (int)A;
	cout << a << endl;

	double b = A;
	cout << b << endl;


#endif // CONVERSION_FROM_CLASS_TO_OTHER

#ifdef HAVE_A_NICI_DAY

	Fraction A = 2.75;
	cout << A << endl;

#endif // HAVE_A_NICI_DAY


}
