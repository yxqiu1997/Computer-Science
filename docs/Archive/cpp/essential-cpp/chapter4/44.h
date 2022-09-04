#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

class UserProfile {
public:
    enum uLevel {Beginner, Intermediate, Advanced, Guru};

    UserProfile(string login, uLevel=Beginner);
    UserProfile();

    // default memberwise initialisation and copy is enough
    // no need for redesign copy constructor or copy assignment operator

    bool operator == (const UserProfile&);
    bool operator != (const UserProfile &rhs);

    // functions for reading data
    string login() const {
        return _login;
    }
    string user_name() const {
        return _user_name;
    }
    int login_count() const {
        return _times_logged;
    }
    int guess_count() const {
        return _guesses;
    }
    int guess_correct() const {
        return _correct_guesses;
    }
    double guess_average() const;
    string level() const;

    // functions for writing data
    void reset_login(const string &val) {
        _login = val;
    }
    void user_name(const string &val) {
        _user_name = val;
    }

    void reset_level(const string&);
    void reset_level(uLevel newLevel) {
        _user_level = newLevel;
    }

    void reset_login_count(int val) {
        _times_logged = val;
    }
    void reset_guess_count(int val) {
        _guesses = val;
    }
    void reset_guess_correct(int val) {
        _correct_guesses = val;
    }

    void bump_login_count(int cnt=1) {
        _times_logged += cnt;
    }
    void bump_guess_count(int cnt=1) {
        _guesses += cnt;
    }
    void bump_guess_correct(int cnt=1) {
        _correct_guesses += cnt;
    }

private:
    string _login;
    string _user_name;
    int _times_logged;
    int _guesses;
    int _correct_guesses;
    uLevel _user_level;

    static map<string, uLevel> _level_map;
    static void init_level_map();
    static string guess_login();
};

inline double UserProfile::guess_average() const {
    return _guesses
            ? double(_correct_guesses) / double(_guesses) * 100
            : 0.0;
}

inline UserProfile::UserProfile(string login, uLevel level)
    : _login(login), _user_level(level), _times_logged(1), _guesses(0), _correct_guesses(0) {}

inline UserProfile::UserProfile()
    : _login("guest"), _user_level("Beginner"), _times_logged(1), _guesses(0), _correct_guesses(0) {

    static int id = 0;
    char buffer[16];

    // _itoa() converts integer to ASCII string
    itoa(id++, buffer, 10);

    // create a unique session id for guest
    _login += buffer;
}

inline bool UserProfile::operator==(const UserProfile &rhs) {
    return _login == rhs._login && _user_name == rhs._user_name;
}

inline bool UserProfile::operator!=(const UserProfile &rhs) {
    return !(*this == rhs);
}

inline string UserProfile::level() const {
    static string _level_table[] = {
            "Beginner", "Intermediate", "Advanced", "Guru"
    };
    return _level_table[_user_level];
}

ostream& operator<<(ostream &os, const UserProfile &rhs) {
    os << rhs.login() << ' '
       << rhs.level() << ' '
       << rhs.login_count() << ' '
       << rhs.guess_count() << ' '
       << rhs.guess_correct() << ' '
       << rhs.guess_average() << endl;
    return os;
}

map<string, UserProfile::uLevel> UserProfile::_level_map;

void UserProfile::init_level_map() {
    _level_map["Beginner"] = Beginner;
    _level_map["Intermediate"] = Intermediate;
    _level_map["Advanced"] = Advanced;
    _level_map["Guru"] = Guru;
}

inline void UserProfile::reset_level(const string &level) {
    map<string, uLevel>::iterator iter;
    if (_level_map.empty()) {
        init_level_map();
    }

    // ensure level is representing a recognisable user level
    iter = _level_map.find(level);
    _user_level = (iter != _level_map.end()) ? iter -> second : Beginner;
}

istream& operator>>(istream &is, UserProfile &rhs) {
    string login, level;
    is >> login >> level;

    int lcount, gcount, gcorrect;
    is >> lcount >> gcount >> gcorrect;
    rhs.reset_login(login);
    rhs.reset_level(level);

    rhs.reset_login_count(lcount);
    rhs.reset_guess_count(gcount);
    rhs.reset_guess_correct(gcorrect);

    return is;
}
