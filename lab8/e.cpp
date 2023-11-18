#include <iostream>
#include <string>

using namespace std;

int main (){
    int n;
    cin >> n;
    string s = "";
    long long prev = 0;
    long long p = 1;
    for (int i = 0;i < n;i++){
        long long a; cin >> a;
        char c = (a - prev) / p + 97;
        prev = a;
        s += c;
        p *= 2;
    }
    cout << s;
}