#include <iostream>
#include <vector>
using namespace std;
int num = 1;
int f(int cnt){
    int sum = 0;
    for (int i = 2;i < cnt;i++){
        if (sum != 0){
            return num;
        }
        if (cnt % i == 0){
            sum++;
        }
    }
    if (sum == 0){
    return num++;
    }
}
int main(){
    vector <int> v,super;
    v.push_back(3);
    int n,cnt = 2;
    cin >> n;
    int x = 5;
    if (n == 1){
        cout << 3;
        return 0;
    }
    while(num != n){
        int p = 0,p2 = 0;
        for (int i = 2;i < x;i++){
            if (x % i == 0){
                p++;
            }
        }
        if (p == 0){
            cnt++;
            f(cnt);
        }
        if (num == n){
            cout << x;
        }
        x++;
    }
}