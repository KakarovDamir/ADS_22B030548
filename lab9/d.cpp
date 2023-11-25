#include <bits/stdc++.h>

using namespace std;

vector <int> kmp(string s){
    int n = s.size();
    vector <int> p (n, 0);

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
    string s;
    int san;
    cin >> s >> san;
    vector <pair <int,string>> mp;

    int max1 = 0;
    while(san--){
        string w;
        cin >> w;
        int m = w.size();
        string t = w;

        transform(w.begin(), w.end(), w.begin(), ::tolower); 

        w = w + '#' + s;
        vector <int> p = kmp(w);

        int max2 = p[p.size() - 1];

        mp.push_back(make_pair(max2, t));
        if (max2 > max1){
            max1 = max2;
        }
    }

    if (max1 == 0){
        cout << 0 ;
        return 0;
    }

    int cnt = 0;
    for (int i = 0; i < mp.size(); i++){
        if (max1 == mp[i].first){
            cnt++;
        }
    }
    
    cout << cnt << '\n';
    for (int i = 0;i < mp.size();i++){
        if (mp[i].first == max1){
            cout << mp[i].second << '\n';
        }
    }
}