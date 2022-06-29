#include <iostream>
#include <vector>
using namespace std;

class Stack {
public:
    // declaration of 42.cpp
    bool find(const string &elem) const;
    int count(const string &elem) const;

    // declaration of 41.cpp
    bool push(const string&);
    bool pop(string &elem);
    bool peek(string &elem);
    bool empty() const {
        return _stack.empty();
    }
    bool full() const {
        return _stack.size() == _stack.max_size();
    }
    bool size() const {
        return _stack.size();
    }

private:
    vector<string> _stack;
};
