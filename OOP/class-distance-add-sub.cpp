/*
    ----------------------------------------------------------------------
    The program takes two distances and performs various operations on it, 
    input, display, addition and subtraction.
    ----------------------------------------------------------------------
*/
#include<iostream>

using namespace std;

// function to return greater of 2 numbers
    inline int max(int a, int b){ return a > b ? a : b; }

/*  class Distance has variable km to hold kilometer and member functions to input 
    distance, print distance, add distance (with another distance object) and
    subtract distance (with another object) 
*/
class Distance
{
    private:
        float km;   // variable for kilometer

    public:
    // Function to scan feet & inches
        void setDistance()
        {

            cout << endl << "Enter kilometers: "; 
            cin >> km;

        }

    //Function to print distance
        void printDistance()
        {
            cout << endl << "Distance is: " << km << "km";
        }

    //Function to add distance with the distance of the object passed as argument
        void addDistance(Distance *obj)
        {
            cout << endl << "-------------SUM------------" << endl;

            float sum = obj->km + km;

            cout << endl << "Sum of distance of this object and passed object is: ";
            cout << sum << "km";

        } // end of addDistance()

        void subDistance(Distance *obj)
        {
            cout << endl << "-------------DIFFERENCE-----------" << endl;

            float diff = obj->km - km;
            if(diff < 0)
                diff *= -1;
            
            cout << endl << "Difference of distance of this object and passed object is: ";
            cout << diff << "km";

        } // end of subDistance()

};

// generic function to print the menu 
    void showChoices()
    {
	    cout << endl << "-----------------MENU-----------------" << endl;
	    cout << "1: Enter Distance " << endl;
	    cout << "2: Print Distance " << endl;
	    cout << "3: Add " << endl;
	    cout << "4: Subtract " << endl;
        cout << "0: Exit" << endl;
	    cout << "Enter your choice :";
    }

// function takes 2 distance objects as arguments and prints the menu for operations to be 
// to be executed on the 2 passed objects
    void distanceMenu(Distance x, Distance y)
    {
        int choice;
        do{
            showChoices();
            cin >> choice;
            cout << endl << "-----------------------------------------" << endl;

            switch (choice)
            {
                case 1:
                    cout << endl << "Distance 1: ";
                    x.setDistance();

                    cout << endl << "Distance 2: ";
                    y.setDistance();

                    break;

                case 2: 
                    cout << endl << "Distance 1: ";
                    x.printDistance();

                    cout << endl << "Distance 2: ";
                    y.printDistance();

                    break;

                case 3:
                    x.addDistance(&y);
                    break;
            
                case 4: 
                    x.subDistance(&y);
                    break;

                case 0: 
                    break;
            
                default:
                    cout << endl << "Invalid choice!";
            }


        }while (choice != 0);

    } // end of distanceMenu()

int main()
{
    Distance A, B;
    
    distanceMenu(A, B);

    return 0;

} // end of main()

// end of program
