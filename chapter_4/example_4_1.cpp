#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;    
};

// compute a student's overall grade from midterm and final exam 
// grades and homework 
 double grade(double midterm, double final, double homework) 
 { 
     return 0.2 * midterm + 0.4 * final + 0.4 * homework;
 }
 
 // compute the median of a vector<double>
 // note that calling this function copies the entire argument vector
double median(vector<double> vec)
{
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if(size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid]; 
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const vector<double>& hw)
{
    if(hw.size() == 0) 
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

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

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

bool compare(const Student_info& x, Student_info& y)
{
    return x.name < y.name;
}