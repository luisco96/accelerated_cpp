#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Write a program to count how many times each distinct word appears in its input
int main()
{
    vector<string> words;
    vector<int>    count;

    cout << "Enter the words :" << endl;

    string s;
    while(cin >> s) {
        vector<string>::size_type i;
        for(i = 0; i < words.size(); i++) {
            if(s == words[i]) {
                count[i]++;
                break;
            }
        }
        if(i == words.size())
        {
                words.push_back(s);
                count.push_back(1);
        }
    }

    if(words.size() == 0) {
        cout << "No Words!" << endl;
        return 1;
    }

    cout << endl << "Results:" << endl;
    for(vector<string>::size_type i = 0; i < words.size(); i++) {
        cout << words[i] << " = " << count[i] << endl;
    }

    return 0;
    

}