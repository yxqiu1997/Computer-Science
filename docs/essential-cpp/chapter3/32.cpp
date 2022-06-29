#include "32.h"

int main() {
    ifstream ifile("31.txt");
    ofstream ofile("32.sort");
    if (!ifile || !ofile) {
        cerr << "Unable to open file -- bailing out\n";
        return -1;
    }

    vector<string> text;
    string word;

    while (ifile >> word) {
        text.push_back(word);
    }

    sort(text.begin(), text.end(), LessThan());
    display_vector(text, ofile);

    return 0;
}
