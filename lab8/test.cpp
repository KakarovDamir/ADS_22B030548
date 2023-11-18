#include <iostream>
#include <string>
#include <map>
#include <vector>

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
    int n;
    cin >> n;

    pair <string,string> calc[n * 2];
    for (int i = 0;i < 2 * n;i++){
        string s;cin >> s;
        calc[i].first = s;
        calc[i].second = my_hash(s);
    }
    
    int cnt = 0;
    for (int i = 0;i < n * 2;i++){
        for (int j = 0;j < n * 2;j++){
            if (calc[i].second == calc[j].first){
                cout << "Hash of string \"" << calc[i].first << "\" is " << calc[i].second << '\n';
                cnt++;
            }
            if (cnt == n) break;
        }
    }
    return 0;
}