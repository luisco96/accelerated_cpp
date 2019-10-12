#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

/* Change the framing program so that it print all spaces in one instruction */
int main()
{
    string name;

    cout << "Please enter your first name: ";
    cin >> name;
    const string greeting = "Hello, " + name  + "!";

    int pad;
    cout << "Enter the size of the padding: ";
    cin >> pad;
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;
    const string spaces(greeting.size() + (pad * 2), ' ');


    for(int i = 0; i < rows; i++)
    {
        string::size_type c = 0;
        while(c != cols)
        {
            if(i == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if(i == 0 || i == rows - 1 || c == 0 || c == cols -1) 
                {
                    cout << "*";
                    c++;
                }
                else if(i == pad + 1)                              
                {
                    cout << " ";
                    c++;    
                }
                else
                {
                    cout << spaces;
                    c += spaces.size();
                }
            }
        }
        cout << endl;
    }
    return 0;
}