#include <iostream>
#include <string>

using namespace std;

const int N = (int)1e5+7;
const int p = 31;

int my_hash(string s){
    int h = 0;
    for (int i = 0; i < s.length(); i++){
        h = h * p + s[i] - 'a' + 1;
    }
    return h;
}

int main (){
    int n, k, m;
    string s1, s2, w;
    cin >> s1 >> s2 >> w;


    n = s1.length();
    k = s2.length();
    m = w.length();

    int hw = my_hash(w);
    int hs1 = my_hash(s1.substr(0,m));
    int hs2 = my_hash(s2.substr(0,m));

    int pm = 1;
    for (int i = 0;i < m - 1;i++){
        pm = pm * p;
    }

    int cnt = 0;
    for (int i = 0; i + m <= n; i++){
        if (hs1 == hw && hs1 == hs2 && hs2 == hw){
            cnt++;
        }

        if (i + m < n && i + m < k){
            hs1 = (hs1 - pm * (s1[i] - 'a' + 1)) * p + (s1[i + m] - 'a' + 1);
            hs2 = (hs2 - pm * (s2[i] - 'a' + 1)) * p + (s2[i + m] - 'a' + 1);
        }
    }
    cout << cnt;

    return 0;
}
