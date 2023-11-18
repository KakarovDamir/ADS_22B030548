#include <iostream>
#include <string>
#include <set>

using namespace std;

const int mod = (int)1e9+7;
int p = 11;

string my_hash(string s){
    long long h = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        h = (h * p % mod + (s[i] - 47)) % mod;
    }
    return to_string(h);
}

int main (){
    int n; cin >> n;
    set <string> hashes;
    pair <string, string> a[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        string s; cin >> s;
        a[i].first = my_hash(s);
        a[i].second = s;
        hashes.insert(s);
    }
    int j = 0;
    for (int i = 0; i < 2 * n; i++) {
        set <string> :: iterator it = hashes.find(a[i].first);
        if (it != hashes.end()) {
            cout << "Hash of string \"" << a[i].second << "\" is " << a[i].first << "\n";
            j++;
            if (j == n)
                break;
        }
    }

    return 0;
}