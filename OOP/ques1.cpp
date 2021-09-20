/*
    ----------------------------------------------------------
    WAP to perform addition of two complex numbers using
    constructor. Complex numbers are given through user input.
    ----------------------------------------------------------
*/

#include<iostream>
using namespace std;

class COMPLEX
{
    private:
        int real, imaginary;

    public:
    // constructor that will user input real and imaginary variables 
        COMPLEX()
        {
            cout << "\n\nComplex number created! enter details: -\n" ;
            cout << "real part: ";
            cin >> real;

            cout << "imaginary part: ";
            cin >> imaginary;
        }

        int returnReal() { return real; }

        int returnImaginary() { return imaginary; }

    // function to print complex number
        void printComplex();

    // function to add a complex number (object) passed to the function  
        void addComplex(COMPLEX);
};

void COMPLEX::printComplex()
{
    if (imaginary < 0)
        cout << real << " " << imaginary << "i";
    
    else
        cout << real << " + " << imaginary << "i";
}

void COMPLEX::addComplex(COMPLEX A)
{
    int realSum = A.returnReal() + real;
    int imaginarySum = A.returnImaginary() + imaginary;

    cout << "\n\n--Sum of complex Numbers--\n";
    
    printComplex();
    cout << " + ";
    A.printComplex();
    
    if (imaginarySum < 0)
        cout << " = " << realSum << " " << imaginarySum << "i";
    
    else 
        cout << " = " << realSum << " + " << imaginarySum << "i";

}

int main()
{
    COMPLEX obj1, obj2;

    obj2.addComplex(obj1);

    return 0;
} // end of main()

// end of program