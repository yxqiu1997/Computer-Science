#include "stack.h"

bool Stack::pop(string &elem) {
    if (empty()) {
        return false;
    }
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::peek(string &elem) {
    if (empty()) {
        return false;
    }
    elem = _stack.back();
    return true;
}

bool Stack::push(const string &elem) {
    if (full()) {
        return false;
    }
    _stack.push_back(elem);
    return true;
}

int main() {
    Stack st;
    string str;

    while (cin >> str && !st.full()) {
        st.push(str);
    }

    if (st.empty()) {
        cout << '\n' << "Oops! No strings were read -- Bailing out\n";
        return 0;
    }
    st.peek(str);
    if (st.size() == 1 && str.empty()) {
        cout << '\n' << "Oops! No strings were read -- Bailing out\n";
        return 0;
    }
    cout << '\n' << "Read in " << st.size() << " strings!\n"
         << "The strings, in reverse order: \n";

    while (st.size()) {
        if (st.pop(str)) {
            cout << str << ' ';
        }
    }

    cout << '\n' << "There are now " << st.size() << " elements in the stack!\n";

    return 0;
}
