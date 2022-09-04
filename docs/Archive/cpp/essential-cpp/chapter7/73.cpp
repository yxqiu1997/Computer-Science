#include <iostream>

using namespace std;

void pop(elemType &elem) {
    if (empty()) {
        throw PopOnEmpty();
    }
    elem = _stack[--_top];
    _stack.pop_back();
}

void push(const elemType &elem) {
    if (!full()) {
        _stack.push_back(elem);
        ++_top;
        return;
    }
    throw PushOnFull();
}

class StackException : public logic_error {
public:
    StackException(const char *what) : _what(what) {}
    const char *what() const {
        return _what.c_str();
    }

protected:
    string _what;
};

class PopOnEmpty : public StackException {
public:
    PopOnEmpty() : StackException("Pop on Empty Stack") {}
};

class PushOnFull : public StackException {
public:
    PushOnFull() : StackException("Push on Full Stack") {}
};

catch (const PushOnFull &pof) {
    log(pof.what());
    return;
}

catch (const StackException &stke) {
    log(stke.what());
    return;
}

catch (const logic_error &lge) {
    log(lge.what());
    return;
}

catch (const exception &ex) {
    log(ex.what());
    return;
}
