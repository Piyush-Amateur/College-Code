// Check end of code for refrences
#include <iostream>
using namespace std;
class Complex
{
    int real, img; // real and img will store real and imaginary part of complex no repectively
    // real + (img)i
    public:

    Complex() // This is a default constructor
    {
        real = 0; // Default Constructor makes complex number like (0 + 0i)
        img = 0;
    }

    Complex(int real, int img) // Parameterized Constructor
    {
        // this operator points to current object 
        this->real = real; // real part of current object = parameter(real)
        this->img = img; // img. part of current object = parameter (img)
    }

    Complex operator + (Complex o2); //line 28
    Complex operator * (Complex o2); //line 42
    friend istream& operator >> (istream& is, Complex& o); //line 57
    friend ostream& operator << (ostream& os, Complex& o); //line 67

};
/*function return_type    class name      operator to be overloaded
      //  Complex           Complex    ::  operator +              (Complex& o2)
                               //scope resolution operator      // function parameters*/

Complex Complex:: operator+ (Complex o2) 
{
    Complex o3; // Created a new object to store addition

    //eg o3 = o1 + o2
    // function(operator overload) gets called on object o1 and takes o2 as its parameters

    //since function is called on object o1, 
    o3.img = this->img + o2.img;  // this->img is the (img) varaible of o1
    o3.real = this->real + o2.real; // this-> is the (real) varaible of o2

    return o3; // function returns addition of both nos 
}

Complex Complex:: operator * (Complex o2)
{
    Complex o3; // Created a new object to store multiplication

    //eg o3 = o1 * o2
    // function(operator overload) gets called on object o1 and takes o2 as its parameters

    //since function is called on object o1, 
    o3.real=(this->real*o2.real)-(this->img*o2.img);// this->img is the (img) varaible of o1
    o3.img=(this->real*o2.img)+(this->img*o2.real);   // this-> is the (real) varaible of o2

    return o3; // function returns multiplication of both nos 
}

// syntax of operator overloading for << 
ostream&  operator << (ostream& os, Complex& o) //function definition 
                        // do not forget (&)
{ 
    os << o.real << " + " << o.img << "i ";
    cout << endl;
    return os;
    // do not forget (return os)
}

// syntax of operator overloading for >> 
istream&  operator >> (istream& is, Complex& o) //function definition 
                        // do not forget (&)
{   
    is >> o.real >> o.img;
    return is;
    // do not forget (return os)
}

int main()
{
    Complex o1; // object created for using default constructor , line 8 for definition
    cout << "Default value of o1 is : ";
    cout << o1; // output 0 + 0i , line 57 for definiton of << 

    Complex o2,o3,o4,o5;
    //Input values , line 67 for definition of >> 
    cout << "Enter values of real and img for o2 : ";
    cin >> o2;

    cout << "Enter values of real and img for o3 : ";
    cin >> o3;

    // Addition , line 28 for defintion of + 
    o4 = o2 + o3;
    cout << "Addition is : " << o4;

    // Multiplication , line 42 for definition of *
    o5 = o2 * o3;
    cout << "Multiplication is : " << o5;


    return 0;
}

//References

//(https://www.geeksforgeeks.org/operator-overloading-c/ )
//(https://www.geeksforgeeks.org/operator-overloading-and-operator-in-a-linked-list-class/)
// Ctrl + click this link to view more about operator overloading

// (https://www.youtube.com/watch?v=BnMnozsSPmw&t=1373s&ab_channel=CodeBeauty)
// Detailed video on Operator Overloading
