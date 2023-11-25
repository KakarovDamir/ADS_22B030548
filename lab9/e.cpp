#include <iostream>
#include <vector>

using namespace std;

vector <int> kmp(string s){
    int n = s.size();
    vector <int> p(n, 0);

    for (int i = 1; i < n;i++){
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
    int san;
    cin >> san;
    while(san--){
        string s;
        int n;
        cin >> s >> n;
        int m = s.size();
        vector<int> p = kmp(s);
        cout <<  (m - p[m - 1]) * (n - 1) + m << '\n';
    }
}