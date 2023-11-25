#include <iostream>
#include <vector>

using namespace std;

vector <int> kmp(string s){
    int n = s.size();
    vector <int> p(n, 0);

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
    string s;
    string w;
    cin >> s >> w;
    
    int n = s.size();
    s = w + '#' + s + s;
    vector <int> p = kmp(s);

    for (int i = n + 1; i < p.size(); i++){
        if (p[i] == n){
            cout << n - (i - n * 2);
            return 0;
        }
    }

    cout << -1;
}