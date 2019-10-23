#include "Student_info.h"

using std::istream; using std::vector;

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw)
{
    if(in) {
        //get rid of previous contents
        hw.clear();

        // read homework grades
        double x;
        while(in >> x)
            hw.push_back(x);
        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

istream& read(istream& is, Student_info& s)
{
    // read and sptre the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);
    return is;
}



bool compare(const Student_info& x, Student_info& y)
{
    return x.name < y.name;
}