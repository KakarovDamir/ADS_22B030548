#include <iostream>
#include <climits>

using namespace std;

long long p = 31;

long long my_hash(string s) {
    long long h = 0;
    for (long long i = 0; i < s.size(); i++) {
        h = (h * p + (s[i] - 'a' + 1));
    }
    return h;
}

bool check(string s, string t) {
    int n = s.size(), m = t.size();
    int hs = my_hash(s.substr(0, m));
    int ht = my_hash(t);

    long long pm = 1;
    for (int i = 0; i < m - 1; i++) {
        pm *= p;
    }

    for (int i = 0; i + m <= n; i++) {
        if (hs == ht){
            return true;
        }

        if (i + m < n){
            hs = (hs - pm * (s[i] - 'a' + 1)) * p + (s[i + m] - 'a' + 1);
        }
    }
    return false;
}

int main() {
    int n; cin >> n;
    string a[n];

    long long min_size = INT_MAX;
    string min_string;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        if (min_size > s.size()) {
            min_size = s.size();
            min_string = s;
        }
        a[i] = s;
    }

    long long max_size = 0;
    string res = "";

    for (int i = 0; i < min_size; i++){
        for (int j = i; j < min_size; j++){
            string sub = min_string.substr(i, min_size - j);
            bool ok = true;

            for (int k = 0; k < n; k++) {
                if (!check(a[k], sub)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                if (max_size < sub.size()) {
                    max_size = sub.size();
                    res = sub;
                }
            }
        }
    }
    cout << res;
}