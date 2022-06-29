#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



class LessThan {
public:
    bool operator() (const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }
};


template<typename elemType>
void display_vector(const vector<elemType> &vec, ostream &os=cout, int len=8) {
    // should add typename keyword
    typename vector<elemType>::const_iterator
            iter = vec.begin(),
            end_iter = vec.end();

    int elem_cnt = 1;
    while (iter != end_iter) {
        os << *iter++
           << (!(elem_cnt++ % len) ? '\n' : ' ');
    }
    os << endl;
}
