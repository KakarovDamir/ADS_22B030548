#include <iostream>
#include <unordered_set>

using namespace std;

long long p = 31;

long long my_hash(string s){
    long long h = 0;
    for (long long i = 0;i < s.size();i++){
        h = h * p + s[i] - 'a' + 1;
    }

    return h;
}

int main (){
    string s;
    unordered_set<long long> res;
    cin >> s;

    long long n = s.size();
    long long hs = my_hash(s);

    long long pm = 1;
    for (long long i = 0;i < n - 1;i++){
        pm *= p;
    }

    long long pg = 1;
    for (long long i = 0; i < n; i++){
        long long pt = pg;
        long long ht = hs;
        res.insert(ht);
        for (long long j = n - 1; j > i; --j){
            ht = ht - ((s[j] - 'a' + 1)*pt);
            pt *= p;
            res.insert(ht);
        }
        hs = (hs - pm * (s[i] - 'a' + 1)) * p;
        pg *= p;
    }

    cout << res.size();
}