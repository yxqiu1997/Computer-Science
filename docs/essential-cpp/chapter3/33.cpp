#include <map>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

typedef vector<string> vstring;

void populate_map(ifstream&, map<string, vstring>&);
void display_map(const map<string, vstring>&, ostream&);
void query_map(const string&, const map<string, vstring>&);

int main() {
    map<string, vstring> families;
    ifstream nameFile("33.txt");

    if (!nameFile) {
        cerr << "Unable to find 33.txt file. Bailing out!\n";
        return -1;
    }
    populate_map(nameFile, families);

    string family_name;
    while(true) {
        cout << "Please enter a family name or q to quit ";
        cin >> family_name;

        if (family_name == "q") {
            break;
        }
        query_map(family_name, families);
    }
    display_map(families, cout);

    return 0;
}

void populate_map(ifstream &nameFile, map<string, vstring> &families) {
    string textline;
    while (getline(nameFile, textline)) {
        string fam_name;
        vector<string> child;
        string::size_type
                pos = 0,
                prev_pos = 0,
                text_size = textline.size();

        while ((pos = textline.find_first_of(" ", pos)) != string::npos) {
            string::size_type end_pos = pos - prev_pos;
            if (!prev_pos) {
                fam_name = textline.substr(prev_pos, end_pos);
            } else {
                child.push_back(textline.substr(prev_pos, end_pos));
            }
            prev_pos = ++pos;
        }

        if (prev_pos < text_size) {
            child.push_back(textline.substr(prev_pos, pos - prev_pos));
        }

        if (!families.count(fam_name)) {
            families[fam_name] = child;
        } else {
            cerr << "Oops! We already have a " << fam_name << " family in our map!\n";
        }
    }
}

void display_map(const map<string, vstring> &families, ostream &os) {
    map<string, vstring>::const_iterator
            iter = families.begin(),
            end_iter = families.end();

    while (iter != end_iter) {
        os << "The " << iter -> first << "family ";
        if (iter -> second.empty()) {
            os << "has no children\n";
        } else {
            os << "has " << iter -> second.size() << " children: ";
            vector<string>::const_iterator
                    it = iter -> second.begin(),
                    end_it = iter -> second.end();

            while (it != end_it) {
                os << *it << " ";
                ++it;
            }
            os << endl;
        }
        ++iter;
    }
}

void query_map(const string &family, const map<string, vstring> &families) {
    map<string, vstring>::const_iterator
            iter = families.find(family);

    if (iter == families.end()) {
        cout << "Sorry. The " << family << " is not currently entered.\n";
        return;
    }

    cout << "The " << family;
    if (!iter -> second.size()) {
        cout << " has no children";
    } else {
        cout << " has " << iter -> second.size() << " children: ";
        vector<string>::const_iterator
                it = iter -> second.begin(),
                end_it = iter -> second.end();
        while (it != end_it) {
            cout << *it << " ";
            ++it;
        }
        cout << endl;
    }
}
