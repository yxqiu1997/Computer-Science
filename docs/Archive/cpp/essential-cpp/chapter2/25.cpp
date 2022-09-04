#include <vector>
#include <iostream>

using namespace std;

inline int max(int t1, int t2) {
    return t1 > t2 ? t1 : t2;
}

inline float max(float t1, float t2) {
    return t1 > t2 ? t1 : t2;
}

inline string max(const string& t1, const string& t2) {
    return t1 > t2 ? t1 : t2;
}

inline int max(const vector<int> &vec) {
    return *max_element(vec.begin(), vec.end());
}

inline float max(const vector<float> &vec) {
    return *max_element(vec.begin(), vec.end());
}

inline string max(const vector<string> &vec) {
    return *max_element(vec.begin(), vec.end());
}

inline int max(const int *parray, int size) {
    return *max_element(parray, parray + size);
}

inline float max(const float *parray, int size) {
    return *max_element(parray, parray + size);
}

inline string max(const string *parray, int size) {
    return *max_element(parray, parray + size);
}

int main() {
    string sarray[] = {"we", "were", "her", "pride", "of", "ten"};
    vector<string> svec(sarray, sarray + sarray -> size());

    int iarray[] = {12, 70, 2, 169, 1, 5, 29};
    int isize = sizeof(iarray) / sizeof(iarray[0]);
    vector<int> ivec(iarray, iarray + isize);

    float farray[] = {2.5, 24.8, 18.7, 4.1, 23.9};
    int fsize = sizeof(farray) / sizeof(farray[0]);
    vector<float> fvec(farray, farray + fsize);

    int imax = max(max(ivec), max(iarray, isize));
    float fmax = max(max(fvec), max(farray, fsize));
    string smax = max(max(svec), max(sarray, sarray -> size()));

    cout << "imax should be 169 -- found: " << imax << '\n'
         << "fmax should be 24.8 -- found: " << fmax << '\n'
         << "smax should be were -- found: " << smax << '\n';

    return 0;
}
