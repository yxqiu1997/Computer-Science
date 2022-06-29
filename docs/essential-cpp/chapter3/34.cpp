#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class even_elem {
public:
    bool operator() (int elem) {
        return elem % 2 == 0;
    }
};

int main() {
    ofstream even_file("34.even"), odd_file("34.odd");
    if (!even_file || !odd_file) {
        cerr << "Arghh!! Unable to open the output files. Bailding out!";
        return -1;
    }

    vector<int> input;
    vector<int>::iterator division = partition(input.begin(), input.end(), even_elem());

    // lack of back_inserter will cause overflow error
    // eof -- ctrl + d or ctrl + z (windows)
    istream_iterator<int> in(cin), eof;
    std::copy(in, eof, back_inserter(input));

    ostream_iterator<int> even_iter(even_file, " "),
                          odd_iter(odd_file, " ");

    copy(input.begin(), division, even_iter);
    copy(division, input.end(), odd_iter);

    return 0;
}
