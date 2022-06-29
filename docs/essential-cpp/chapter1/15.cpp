#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    // malloc space with fixed size
    const int nm_size = 128;
    char user_name[nm_size];
    cout << "Please enter your name: ";

    // iomanip - setw() ensures the size of input is less than 127
    cin >> setw(nm_size) >> user_name;

    // if using string, the condition will be stringname.size()
    switch (strlen(user_name)) {
        case 0:
            cout << "Ah, the user with no name."
                 << "Well, ok, hi, user with no name\n";
            break;
        case 1:
            cout << "A 1-character name? Hmm, have you read Kafka?: "
                 << "hello, " << user_name << endl;
            break;
        case 127:
            cout << "That is a very big name, indeed --"
                 << "we may have needed to shorten it!\n"
                 << "In any case,\n";
        default:
            cout << "Hello, " << user_name
                 << " -- happy to make you acquaintance!\n";
            break;
    }

    return 0;
}

