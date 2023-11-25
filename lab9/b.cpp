#include <iostream>
#include <vector>

using namespace std;

vector<int> kmp(string s ,int n, int m){
    int t = s.size();
    vector <int> p(t, 0);
    for (int i = 1; i < t; ++i){
        int j = p[i - 1];

        while(j > 0 && s[j] != s[i] ){
            j = p[j - 1];
        }
        if (s[j] == s[i]){
            j++;
        }
        p[i] = j;
    }
    return p;
}

int main (){
    string a, b;
    int san;
    cin >> a >> san >> b;

    int n = a.size();
    int m = b.size();
    a = a + '#' + b;

    vector <int> p = kmp(a, n, m);

    int cnt = 0;
    for (int i = n+1;i < p.size();i++){
        if (n == p[i]){
            cnt++;
        }
    }
    if (cnt > san){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}