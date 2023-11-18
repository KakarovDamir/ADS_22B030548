#include <iostream>
#include <vector>

using namespace std;

int p = 31;

int my_hash(string s){
    int h = 0;
    for (int i = 0; i < s.size(); i++){
        h = h * p + (s[i] - 'a' + 1);
    }

    return h;
}

int main (){
    while(true){
        int san;
        vector <pair<string, int>> v;
        cin >> san;

        if (san == 0){
            return 0;
        }

        int i = 0;
        while(i < san){
            string w;
            cin >> w;
            v.push_back(make_pair(w,0));
            i++;
        }
        string s;
        int j = 0;
        cin >> s;
        int n = s.size();
        int max = 0;

        while(j < san){
            string w = v[j].first;
            int m = w.size();
            int hs = my_hash(s.substr(0,m));
            int hw = my_hash(w);

            int pm = 1;
            for (int i = 0;i < m - 1; ++i){
                pm *= p;
            }

            int cnt = 0;
            for (int i = 0;i + m <= n; i++){
                if (hs == hw){
                    cnt++;
                }

                if (i + m < n){
                    hs = (hs - pm * (s[i] - 'a' + 1)) * p + (s[i + m] - 'a' + 1);
                }
            }

            if (max < cnt){
                max = cnt;
            }
            v[j].second = cnt;
            j++;
        }

        cout << max << '\n';
        for (int i = 0; i < v.size();i++){
            if (v[i].second == max){
                cout << v[i].first << '\n';
            }
        }
    }
}