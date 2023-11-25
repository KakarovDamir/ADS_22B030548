#include <iostream>
#include <vector>

using namespace std;

vector <int> kmp(string s){
    int n = s.size();
    vector <int> p(n,0);

    for (int i = 1;i < n;i++){
        int j = p[i - 1];

        while(j > 0 && s[i] != s[j]){
            j = p[j - 1];
        }
        if (s[i] == s[j]){
            j++;
        }
        p[i] = j;
    }

    return p;
}

int main (){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    s2 = s2 + '#' + s1;
    vector <int> p = kmp(s2);
    vector <int> res;

    for (int i = m + 1; i < p.size(); i++){
        if (p[i] == m){
            res.push_back(i - m - m + 1);
        }
    }
    cout << res.size() << '\n';
    for (int i = 0;i < res.size(); i++){
        cout << res[i] << ' ';
    }
}