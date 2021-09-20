/*
    WAP using copy constructor to copy data of an 
    object to another object
*/

#include<iostream>
using namespace std;

class Age
{
    private: 
        int age;
    
    public:
        Age()   // default constructor
        {
            age = 18;
        }

        Age(int x)  // parameterized constructor
        {
            age = x;
        }

        Age(Age &A) // copy constructor
        {
            age = A.age;
        }

        void displayAge()
        {
            cout << endl << "age is: " << age << endl;
        }
};

int main()
{
    Age kartik(19), // calls parameterized constructor
    samyak,         // calls default constructor
    aryan(kartik);  // calls copy constructor and copies age of object kartik

    kartik.displayAge();
    samyak.displayAge();
    aryan.displayAge();

    return 0;
}
