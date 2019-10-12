#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string name;

    cout << "Please enter your first name: ";
    cin >> name;
    const string greeting = "Hello, " + name  + "!";

    const int pad = 10;
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    for(int i = 0; i < rows; i++)
    {
        string::size_type c = 0;
        while(c != cols)
        {
            if(i == pad + 1 && c == pad +1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                if(i == 0 || i == rows - 1 || c == 0 || c == cols -1) cout << "*";
                else                                                  cout << " ";

                c++;
            }
        }
        cout << endl;
    }
    return 0;
}