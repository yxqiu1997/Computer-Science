#include "44.h"

int main() {
    UserProfile anon;
    cout << anon;

    UserProfile anon_too;
    cout << anon_too;

    UserProfile anna("AnnaL", UserProfile::Guru);
    cout << anna;

    anna.bump_guess_count(27);
    anna.bump_guess_correct(25);
    anna.bump_login_count();
    cout << anna;

    cin >> anon;
    cout << anon;

    return 0;
}
