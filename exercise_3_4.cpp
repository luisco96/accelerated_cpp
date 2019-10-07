#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    vector<string> words;
    vector<string>::size_type max, min;
    string *longest, *shortest, s; 

    cout << "Enter the words :" << endl;
    while(cin >> s) {
        words.push_back(s);
    }

    max = words[0].size();
    longest = &(words[0]);
    min = words[0].size();
    shortest = &(words[0]);
    
    for(vector<string>::size_type i = 1; i < words.size(); i++) {
        if(words[i].size() > max) {
            max = words[i].size();
            longest = &(words[i]);
        }
        else if(words[i].size() < min) {
            min = words[i].size();
            shortest = &(words[i]);
        }
    }

    cout << "Longest word : " << *longest << endl;
    cout << "Shortest word: " << *shortest << endl; 
}