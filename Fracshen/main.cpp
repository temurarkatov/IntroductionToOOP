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
	int get_denomiratir()const
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
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:" << this << endl;
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
		cout << "Destructor:\t\t" << this << endl;
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
		left.get_numerator() * right.get_denomiratir() + right.get_numerator() * left.get_denomiratir(),
		left.get_denomiratir() * right.get_denomiratir()
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
		left.get_denomiratir() * right.get_denomiratir()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

//#define CONSTRUCTORS_CHEK
#define AITHMETICAL_OPERATORS_CHECK
//#define INCREMENTO_DECREMENTO_CECK


void main()
{
	setlocale(LC_ALL, " ");

#ifdef CONSTRUCTORS_CHEK
	  
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
	

#endif CONSTRUCTORS_CHEK

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
#endif  AITHMETICAL_OPERATORS_CHECK

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
#endif INCREMENTO_DECREMENTO_CECK


}
