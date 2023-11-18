#include <iostream>

using namespace std;

int p = 31;

int my_hash(string s){
    int h = 0;
    for (int i = 0;i < s.size();i++){
        h = h * p + (s[i] - 'a' + 1);
    }

    return h;
}

int main (){
    int n;
    string s;
    cin >> s >> n;
    
    int sir = s.size();
    int i = 0;
    while(i < n){
        int l, r;
        cin >> l >> r;

        string w = s.substr(l - 1, r - l + 1);
        int m = w.size();
        int hs = my_hash(s.substr(0,m));
        int hw = my_hash(w);


        int pm = 1;
        for (int i = 0;i < m - 1;i++){
            pm *= p;
        }

        int cnt = 0;
        for (int i = 0;i + m <= sir;i++){
            if (hs == hw){
                cnt++;
            }
            if (i + m < sir){
                hs = (hs - pm * (s[i] - 'a' + 1)) * p + (s[i + m] - 'a' + 1);
            }
        }

        cout << cnt << '\n';
        i++;
    }
}