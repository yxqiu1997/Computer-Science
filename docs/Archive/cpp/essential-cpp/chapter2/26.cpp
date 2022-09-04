#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename Type>
inline Type _max(Type t1, Type t2) {
    return t1 > t2 ? t1 : t2;
}

template <typename elemType>
inline elemType _max(const vector<elemType> &vec) {
    return *max_element(vec.begin(), vec.end());
}

template <typename arrayType>
inline arrayType _max(const arrayType *parray, int size) {
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

    int imax = _max(_max(ivec), _max(iarray, isize));
    float fmax = _max(_max(fvec), _max(farray, fsize));
    string smax = _max(_max(svec), _max(sarray, sarray -> size()));

    cout << "imax should be 169 -- found: " << imax << '\n'
         << "fmax should be 24.8 -- found: " << fmax << '\n'
         << "smax should be were -- found: " << smax << '\n';

    return 0;
}
