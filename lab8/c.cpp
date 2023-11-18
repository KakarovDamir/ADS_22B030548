#include <iostream>
#include <vector>

using namespace std;

int p = 31;

int my_hash(string s){
    int h = 0;
    for (int i = 0;i < s.size(); i++){
        h = h * p + s[i] - 'a' + 1;
    }

    return h;
}

int main (){
    string s;
    int san;
    cin >> s >> san;
    int n = s.size();
    vector <bool> check(n,false);

    int i = 0, cnt = 0;
    while(i < san){
        string w;
        cin >> w;
        int m = w.size();
        
        int hs = my_hash(s.substr(0,m));
        int hw = my_hash(w);

        int pm = 1;
        for (int i = 0;i < m - 1;i++){
            pm *= p;
        }

        int cnt2 = 0;
        for (int i = 0;i + m <= n;i++){
            if (hs == hw){
                cnt2++;
                for (int j = i;j < i + m;j++){
                    check[j] = true;
                }
            }

            if (i + m < n){
                hs = (hs - pm * (s[i] - 'a' + 1)) * p + (s[i + m] - 'a' + 1);
            }
        }

        cnt += cnt2;
        i++;
    }

    for (int i = 0;i < n;i++){
        if (!check[i]){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}