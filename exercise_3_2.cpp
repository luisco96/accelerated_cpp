#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef vector<int>::size_type vct_sz;

double median(const vector<int> integers, vct_sz begin, vct_sz end);

int main()
{
    vector<int> integers; // Holds integers 
    int x;                // Temporal variable to hold integers

    cout << "Enter the integers: ";
    // Get integers until an EOF is received 
    while(cin >> x) {
        integers.push_back(x);
    }

    if(integers.size() == 0) {
        cout << "No integers!" << endl;
        return 1;
    }

    sort(integers.begin(), integers.end());

    vct_sz mid = integers.size() / 2;
    vct_sz lower_mid_value;     // Lower middle value, used to get Q1
    vct_sz upper_mid_value;     // Upper middle value, used to get Q3

    if(integers.size() % 2 == 0) {
        lower_mid_value = mid;
        upper_mid_value = mid;
    } else {
        lower_mid_value = mid;
        upper_mid_value = mid + 1;
    }

    cout << "Q1 = " << median(integers, 0, lower_mid_value) << endl;
    cout << "Q2 = " << median(integers, 0, integers.size()) << endl;
    cout << "Q3 = " << median(integers, upper_mid_value, integers.size()) << endl;

    return 0;
}
double median(const vector<int> integers, vct_sz begin, vct_sz end)
{
    vct_sz size = begin + end;
    vct_sz mid = size / 2;

    if(size % 2 != 0)
        return integers[mid];
    else 
        return (integers[mid] + integers[mid-1]) / 2.0; 
}