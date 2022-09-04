#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    int ival;
    int sum = 0;

    // loop ends when non-integer typed
    while (cin >> ival) {
        vec.push_back(ival);
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        sum += vec[i];
    }
    int average = sum / vec.size();

    cout << "Sum of " << vec.size()
         << " elements: " << sum
         << ". Average: " << average << endl;
}
