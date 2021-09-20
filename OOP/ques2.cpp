/*
    --------------------------------------------------------------------------
    Define a class named as FRACTION that contains two data members that
    represent the numerator and denominator of a fraction. By defining
    necessary member functions, write a program to add, subtract and multiply
    two fractions. The add accepts the objects using call-by- value technique,
    subtract using call-by-reference and multiply using call-by-address
    technique.
    Sample input/Output
    For Fraction-1
    Enter the numerator: 3
    Enter the denominator: 5
    For Fraction-2
    Enter the numerator: 4
    Enter the denominator: 9
    Result of addition = 47/45
    Result of subtraction = 7/45
    Result of multiplication = 4/15
    --------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

// Utility function to compute GCD of 2 numbers passed as arguments
    int gcd(int a, int b)
    {
        // Everything divides 0
            if (a == 0)
                return b;
            if (b == 0)
                return a;
  
        // base case
            if (a == b)
                return a;
  
        // a is greater
            if (a > b)
                return gcd(a-b, b);

        return gcd(a, b-a);

} // end of gcd()

// Utility function to return absolute value of an integer passed as argument
    int absoluteof(int X)
    {
        if (X < 0)
            return -1 * X;
    
        else 
            return X;

    } // end of absoluteof()


// Fraction class to carry out our program
class Fraction
{
    private:
        int numerator, denominator;
     
    public:

    // Function to input fraction
        void setFraction()
        {
            cout << endl << "------enter-fraction-------" << endl;
            
            cout << endl << "enter numerator: ";
            cin >> numerator;

            cout << endl << "enter denominator: ";
            cin >> denominator;

        }

    /* Utility functions that will be used in our program */
        int returnNumerator()
        {
            return numerator;
        }

        int returnDenominator()
        {
            return denominator;
        }

        int* return_address_numerator()
        {
            return &numerator;
        }
        
        int* return_address_denominator()
        {
            return &denominator;
        }

    // function to print a fraction
        void printFraction(int a, int b)
        {
            cout << a << "/" << b;
        }

    /* Functions to perform Addition, Subtraction and Multiplication of 2 fractions */
        
        // Functio to add using call by value 
            void addFraction(int numero, int denomino)
            {
                int sumNumero = numero * (denominator) + numerator * (denomino);
                int sumDenomino = denominator * denomino;

                int GCD = gcd(sumNumero, sumDenomino);
            
                sumNumero /= GCD;
                sumDenomino /= GCD;

                cout << endl << "-------Sum-of-Fraction-------" << endl;
                printFraction(numerator, denominator);  
                cout << " + "; 
                printFraction(numero, denomino);
                cout << " = ";
                printFraction(sumNumero, sumDenomino);

            } // end of addFraction()

        // Function to subtract using call by reference
            void subFraction(int const &numero, int const &denomino)
            {
                int diffNumero = numero * (denominator) - numerator * (denomino);
                int diffDenomino = denominator * denomino;

                int GCD = gcd(absoluteof(diffDenomino), diffDenomino);

                diffNumero /= GCD;
                diffDenomino /= GCD;

                cout << endl << "-------Difference-of-Fraction-------" << endl;
                printFraction(numerator, denominator);
                cout << " - ";
                printFraction(numero, denomino);
                cout << " = ";
                printFraction(diffNumero, diffDenomino);

            } // end of subFraction()

        // Function to multiply using call by address
            void multiplyFraction(int *numero, int *denomino)
            {
                int finalNumero = numerator * (*numero);
                int finalDenomino = denominator * (*denomino);

                int GCD = gcd(finalNumero, finalDenomino);

                finalNumero /= GCD;
                finalDenomino /= GCD;

                cout << endl << "-------Product-of-Fraction-------" << endl;
                printFraction(numerator, denominator);
                cout << " X ";
                printFraction(*numero, *denomino);
                cout << " = ";
                printFraction(finalNumero, finalDenomino);

            } // end of multiplyFraction()

}; // end of class Fraction

int main()
{
    Fraction A, B;

    A.setFraction();
    B.setFraction();

    B.addFraction(A.returnNumerator(), A.returnDenominator());  // call by value!

    cout << endl;

    B.subFraction(A.returnNumerator(), A.returnDenominator());  // call by reference!

    cout << endl;

    B.multiplyFraction(A.return_address_numerator(), A.return_address_denominator());  // call  by address!  

    return 0;
} // end of main()

// end of program!