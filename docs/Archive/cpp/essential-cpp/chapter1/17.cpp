#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream in_file("17.txt");
    if (!in_file) {
        cerr << "oops! unable to open input file\n";
        return -1;
    }

    ofstream out_file("17.sort");
    if (!out_file) {
        cerr << "oops! unable to open output file\n";
        return -2;
    }

    string word;
    vector<string> text;
    while (in_file >> word) {
        text.push_back(word);
    }

    cout << "unsorted text: \n";

    for (size_t ix = 0; ix < text.size(); ++ix) {
        cout << text[ix] << ' ';
    }
    cout << endl;

    sort(text.begin(), text.end());

    out_file << "sorted text: \n";
    for (size_t ix = 0; ix < text.size(); ++ix) {
        out_file << text[ix] << ' ';
    }
    out_file << endl;

    return 0;
}
