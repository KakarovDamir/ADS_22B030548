#include <bits/stdc++.h>
using namespace std;
void f(int n){
    int sum = 0;
    for (int i = 2;i < n;i++){
        if (sum != 0){
            cout << "NO";
            break;
        }
        if (n % i == 0){
            sum++;
        }
    }
    if (sum == 0){
    cout << "YES";
    }
}
int main (){
    int n;
    cin >> n;
    if (n == 1){
        cout << "NO";
    }else{
    f(n);
    }
}

//run id:2983