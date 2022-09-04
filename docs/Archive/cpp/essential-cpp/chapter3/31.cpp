#include <set>
#include <map>
#include <iostream>
#include <fstream>
using namespace std;

void initialise_exclusion_set(set<string>&);
void display_word_count(const map<string, int>&, ofstream&);
void process_file(map<string, int>&, const set<string>&, ifstream&);
void user_query(const map<string, int>&);

int main() {
    ifstream ifile("31.txt");
    ofstream ofile("31.map");
    if (!ifile || !ofile) {
        cerr << "Unable to open file -- bailing out!\n";
        return -1;
    }

    set<string> exclude_set;
    initialise_exclusion_set(exclude_set);

    map<string, int> word_count;
    process_file(word_count, exclude_set, ifile);
    user_query(word_count);
    display_word_count(word_count, ofile);

    return 0;
}

void initialise_exclusion_set(set<string> &exs) {
    static string _excluded_words[25] = {
            "the", "end", "but", "that", "then", "are", "been",
            "can", "a", "could", "did", "for", "of",
            "had", "have", "him", "his", "her", "its", "is",
            "were", "which", "when", "with", "would"
    };
    exs.insert(_excluded_words, _excluded_words + _excluded_words -> size());
}

void process_file(map<string, int> &word_count, const set<string> &exclude_set, ifstream &ifile) {
    string word;
    while (ifile >> word) {
        if (exclude_set.count(word)) {
            continue;
        }
        word_count[word]++;
    }
}

void user_query(const map<string, int> &word_map) {
    string search_word;
    cout << "Please enter a word to search: q to quit";
    cin >> search_word;
    while (search_word.size() && search_word != "q") {
        map<string, int>::const_iterator iter = word_map.find(search_word);
        if (iter != word_map.end()) {
            cout << "Found! " << iter -> first
                 << " occurs " << iter -> second
                 << " times.\n";
        } else {
            cout << search_word
                 << "w was not found in text.\n";
        }
        cout << "\nAnother search? (q to quit).";
        cin >> search_word;
    }
}

void display_word_count(const map<string, int> &word_map, ofstream &os) {
    map<string, int>::const_iterator
                iter = word_map.begin(),
                end_iter = word_map.end();

    while (iter != end_iter) {
        os << iter -> first << " ("
           << iter -> second << ")" << endl;
        ++iter;
    }
    os << endl;
}
