#include <iostream>
using namespace std;
int main(){
    int n,num = 0;
    cin >> n;
    int x = 2;
    while(num != n){
        int p = 0;
        for (int i = 2;i < x;i++){
            if (x % i == 0){
                p++;
            }
        }
        if (p == 0){
            num++;
        }
        if (num == n){
            cout << x;
            break;
        }
        x++;
    }
}