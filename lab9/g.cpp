#include <iostream>
#include <vector>

using namespace std;

vector <int> kmp(string s){
    int n = s.size();
    vector <int> p (n, 0);

    for (int i = 1;i < s.size(); i++){
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
    cin >> s;

    int n = s.size();
    vector <int> p = kmp(s);

    cout << n - p[n - 1];
}