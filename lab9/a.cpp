#include <iostream>
#include <vector>

using namespace std;

vector <int> kmp(string s){
    int n = s.size();
    vector <int> p(n, 0);

    for (int i = 1; i < n; i++){
        int j = p[i - 1];

        while(j > 0 && s[j] != s[i]){
            j = p[j - 1];
        }
        if (s[i] == s[j]){
            j++;
        }

        p[i] = j;
    }

    return p;
}

bool kmp_search(string pattern, string text){
    int n = text.length();
    int m = pattern.length();
    int i = 0, j = 0;

    vector <int> pref = kmp(pattern);
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) return true;
        } else if (j > 0) {
            j = pref[j-1];
        } else {
            i++;
        }
    }

    return false;
}


int main(){
    string text, pattern;
    cin >> text >> pattern;

    int count = 1;
    string copied_text = text;
    while (copied_text.length() < pattern.length()) {
        copied_text += text;
        count++;
    }

    if (kmp_search(pattern, copied_text)) cout << count;
    else if (kmp_search(pattern, copied_text+text)) cout << count+1;
    else cout << -1;

    return 0;
}