#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
    vector<string> names;
    vector<double> grades;
    string name;
    double midterm, final, homework = 0, x;

    // ask for and read the student's name
    cout << "Please enter the student name, q to quit: ";
    while(cin >> name) {
        if(name == "q") break;

        names.push_back(name);
        // Ask for the mid and final grades
        cout << "Please enter your midterm and final grades: ";
        cin >> midterm >> final;

        cout << "Enter the 3 homework grades: ";
        for(int i= 0; i < 3; i++ ){
            cin >> x;
            homework += x;
        }
        homework /= 3;
        final = 0.2 * midterm + 0.4 * final + 0.4 * homework;
        grades.push_back(final);

        cout << "Please enter the student name, q to quit: ";
    }

    if(names.size() == 0) {
        cout << "No names were given!" << endl;
        return 1;
    }

    streamsize prec = cout.precision();
    for(vector<string>::size_type i = 0; i < names.size(); i++) {
        cout << names[i] << ": " <<  setprecision(3) << grades[i] << endl;
    }
    cout.precision(prec);

    return 0;
}