#include<iostream>
using namespace std;

//* Only built-in operators can be overloaded.
//* that is: [=,-,*,/,%,==,>,<,>=,<=,/=,+=,-=,*=]
//* At least one of the operands in overloaded operators must be user-defined
//* c1 - c2 is like: c1.f(c2) 

class Complex {
private:
	int real, imag;
public:
	Complex(int r = 0, int i = 0) {real = r; imag = i;}
	
	// This is automatically called when '+' is used with
	// between two Complex objects
	Complex operator + (Complex const &obj) {
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	Complex operator - (Complex const &obj) {
		Complex res;
		res.real = real - obj.real;
		res.imag = imag - obj.imag;
		return res;
	}

	//! this is a special way in which operator with only 1 argument are overloaded !!
	Complex operator++ (int){ //post operator overloaded, 
		this->imag++; this->real++;
		return Complex(real,imag);
	}
	
	Complex operator++ ( ){ //pre operator overloaded, 
		this->imag++; this->real++;
		return Complex(real-1,imag-1); //to not return the incremented object, but increment the original obj.
	}
	//now we overload pre and post operator
    
	void print() { cout << real << " + " << imag << "i\n"; }
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 - c2;
	//* c1 - c2 is like: c1.f(c2) 
	//* that is, operator overloading takes left object as one on whom the function will act, 
	//* taking right one as a parameter to that function
	c3.print();

	(Complex(1,10)++).print();
	Complex preDemo = Complex(1,10);
	(++preDemo).print(); //1 + 10i
	preDemo.print(); //2 + 11i
} 
