#include <iostream>
#include <string>
// Below are two additional headers
#include <ios>
#include <limits>
using namespace std;
int ch = 1;
// class Database is the friend of class Marks so , All members of Marks(private/public) can be accesed by Database(class)
class Marks{
    int history, geo; 

   /* void SetMarks(int history, int geo) // Parameterized constructor
    {
        this->history = history; 
        this->geo = geo;
    }
    void PrintMarks()
    {
        cout << "\n History score is : " << history;
        cout << "\n Geography score is : " << geo;
    }
*/
    friend class Database; // syntax for friend class
    // Database if friend of Marks (but not the other way around!)
};
class Database
{
    string name,class_with_div,dob,bld_grp,address;
    int roll_no;
    long long int phone_no; // since phone number is 10 digits we require more space to store large varible , long long int can store very large numbers
    // can use string instead
    Marks m;
    static string test1; // Defined a static variable
    public:
    Database() //Defualt constructor provides random entry 
    {
        name = "Default";
        class_with_div = "SE COMP 2";
        dob = "12/12/2012";
        bld_grp = "A+";
        address = "Pune";
        roll_no = 69;
        phone_no = 1234567890;
        this->m.history = 100; // current object . m(Object of Marks class) . history
        // history varaible  {of} m object (Marks class) {of} current object(Database class)
        this->m.geo = 100; 
        //geo varaible {of} m object (Marks class) {of} current object (Database class)
    }

    void MakeEntry() // Parameterized constructor to get input from user
    {
        cout << "\nEnter name : ";
        getline(cin,name); // getline function is used to get input along with " " wide spaces
        // eg My name is SPPU , using only cin will give error

        //syntax of getline(cin,variable_name)
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Use this line to clear stream buffer
        //When we use getline function it is a good pratice to clear "stream buffer" to prevent "errors"

        cout << "\nEnter class with division : "; 
        getline(cin,class_with_div);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEnter dob in dd/mm/yyyy format : "; 
        cin >> dob;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEnter blood group : "; 
        getline(cin,bld_grp);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEnter address : "; 
        cin >> address;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEnter roll no : "; 
        cin >> roll_no;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEnter phone_no : "; 
        cin >> phone_no;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // This is the point where program threw infinte loop error 
        // TO fix that error use below block of code
        if (cin.fail())
        {
        // get rid of failure state
        cin.clear(); 
        // discard 'bad' character(s) 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        cout << "\nEnter marks in History and Geography : ";
        cin >> this->m.history >> this->m.geo;

    }
    // Dont forget (&) , & means refrence to a varaible ,so when working with (&) operator you deal with actual variables/values and not copies. Any modification done using & operator will modify actual variables.

    Database(Database& o1) // copy constructor copies entries of object 1 to object 2
    // eg Database o1 = o2;  This will copy all entries of o2 like name,dob to o1
    {
        // this operator points to the current object
        this->address = o1.address;
        this->name = o1.name;
        this->class_with_div = o1.class_with_div;
        this->dob = o1.dob;
        this->bld_grp = o1.bld_grp;
        this->roll_no = o1.roll_no;
        this->phone_no = o1.phone_no;
        this->m.history = o1.m.history;
        this->m.geo = o1.m.geo;
    }
    ~Database() // Destructor gets called at object destruction time
    {
        // This will run once only
        if(ch == 1)
        {
            cout << "Thanks for using this code!";
            ch++;
        }
    }
    void print() // to print all entries corresponding to an object
    {
        cout << "\nName is : " << name;
        cout << "\n Class is : " << class_with_div;
        cout << "\n dob is : " << dob;
        cout << "\n blood group is : " << bld_grp;
        cout << "\n address is : " << address;
        cout << "\n roll no  is : " << roll_no;
        cout << "\n phone no is : " << phone_no; 
        cout << "\n Marks in History are : " << this->m.history; 
        cout << "\n Marks in Geography are : " << this->m.geo; cout << endl;
    }
    static void Test() // Static varaibles can only be used along with static functions
    {
    cout << test1 << endl; // This prints the variable 
    } 
};
string Database::test1 = "Welcome"; // Static variable can only be defined outside of class
//syntax
// datatype   class_name :: variable_name = value;


int main()
{
    Database *obj; // Pointer of type Database
    int num;
    cout << "Enter the number of student : ";
    cin >> num;
    obj = new Database[num]; // We create an Array of Database type whose length is num
    int choice;
    do
    {
        cout << "\nEnter 1 to Make Entries in Database";
        cout << "\nEnter 2 to Display All Entries";
        cout << "\nEnter 3 to Exit";
        cout << "\nEnter choice : "; cin >> choice;
        switch(choice)
        {
            case 1:
            {
                for(int i=0;i<num;i++)
                {
                    obj[i].MakeEntry();
                }
            }
            break;
            case 2:
            {
                for(int i=0;i<num;i++)
                {
                    obj[i].print();
                }
            }
            break;
            case 3:
            {
                cout << "END" << endl;
                delete [] obj; // at the end of program we free all the memory which has been allocated to pointer obj

                // to delete a dynamically created "array" syntax is :
                //delete [] pointer_name
            }
            break;
            default:
            {
                cout << "Enter Correct Choice!";
            }
            break;
        }
    } while(choice!=3);
    
    return 0;
}