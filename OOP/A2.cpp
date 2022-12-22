#include <iostream>
using namespace std;

int main()
{
    int x,y;
    cout << "Enter two numbers : ";
    cin >> x >> y;cout << endl;
    int choice;
    do{
        cout << endl;
        cout << "Enter 1 for addition \n";
        cout << "Enter 2 for subtraction \n";
        cout << "Enter 3 for multiplication \n";
        cout << "Enter 4 for division \n";
        cout << "Enter 5 to  exit \n";
        cout << "Enter choice : ";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
            case 1:
            {
                cout << "Addition is : " << x + y << endl;
            }
            break;
            case 2:
            {
                cout << "Subtraction is : " << x - y << endl;
            }
            break;
            case 3:
            {
                cout << "Multiplication is : " << x * y << endl;
            }
            break;
            case 4:
            {
                cout << "Division is : " << x / y << endl;
            }
            break;
        }
    }while(choice!=5);
    if(choice == 5)
    {
        cout << "Thanks for using our program \n";
    }
    return 0;
}