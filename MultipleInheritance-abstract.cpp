#include<bits/stdc++.h>
using namespace std;

/*
Encapsulation - Encapsulation is defined as the wrapping up of data under a single unit. Like when
create a class we are binding them to a single entity and class is the capsule inside which we have
data and methods. Again we are having getters and setters which kind of encapsulates the data
from outside acces and could be only accessed through methods.

NOTE- It is also known as a combination of data-hiding and abstraction.(Not always true)
Getters and setters could be used for public variables of there is a restriction on type of
data that it accepts.

Advantages of Encapsulation:  

Data Hiding: The user will have no idea about the inner implementation of the class. It will not be visible to the user how the class is storing values in the variables. The user will only know that we are passing the values to a setter method and variables are getting initialized with that value.
Increased Flexibility: We can make the variables of the class read-only or write-only depending on our requirement. If we wish to make the variables read-only then we have to omit the setter methods like setName(), setAge(), etc. from the above program or if we wish to make the variables as write-only then we have to omit the get methods like getName(), getAge(), etc. from the above program
Reusability: Encapsulation also improves the re-usability and is easy to change with new requirements.
Testing code is easy: Encapsulated code is easy to test for unit testing.*/


/*

Abstraction - Abstraction means displaying only essential information and hiding the details. Data abstraction refers to providing only essential information about the data to the outside world, hiding the background details or implementation.
1) Abstraction using Classes: We can implement Abstraction in C++ using classes.
2) Abstraction in Header files: One more type of abstraction in C++ can be header files. For example, consider the pow() method present in math.h header file. Whenever we need to calculate power of a number, we simply call the function pow()
3) Abstraction using access specifiers: Access specifiers are the main pillar of implementing abstraction in C++.

/*

/*

Abstract class : 

Virtual member functions are inherited. A class derived from an abstract base class will also be
abstract unless you override each pure virtual function in the derived class.

ibm.com/docs/en/zos/2.1.0?topic=only-abstract-classes

*/

/*
Data Hiding:

Data hiding is a software development technique specifically used in object-oriented programming (OOP)
to hide internal object details (data members). Data hiding ensures exclusive data access to class 
members and protects object integrity by preventing unintended or intended changes.

*/

class Number;

class Real{
    int real;
public:
    friend class Number;    //friend class
    Real(){
        this->real = 0;
    }
    Real(int a){
        this->real = a;
    }

    Real add(Real a, Real b){
        this->real = a.real+b.real;
        return *this;
    }
    void show () { 
     cout << "Result = " << this->real; 
    }
};
class Complex{ 
  int img;
public : 
  friend class Number;       //friend class
  Complex() : img(0){}    
  Complex(int a) : img(a){}  //Constructor overloading
  Complex add(Complex a, Complex b) { 
    this->img = a.img + b.img;
    return *this; 
  }
    void show () { 
     cout << "Result = " << this->img; 
    }
}; 

class Number: public Real, public Complex{   //multiple inheritance
    Real r;
    Complex c;
public:
    Number(): r(0),c(0){}
    Number(Real a, Complex b): r(a),c(b){}
    Number add(Number a, Number b){
        this->r = Real::add(a.r, b.r);
        this->c = Complex::add(a.c, b.c);
        return *this;
    }
    void show () { 
        cout<<r.real<<" "<<c.img<<endl;
    }
};
int main ()  
{ 

    Real r1(4);
    Real r2(8);

    Complex c1(3);
    Complex c2(7);

    Real r3;
    r3.add(r1,r2);

    Complex c3;
    c3.add(c1,c2);

    Number n(r3,c3);

    Number n1;
    n1.add(n,n);

    n1.show();

    return 0; 
} 