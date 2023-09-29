#include <iostream>
using namespace std;
int main (){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    bool exist;
    for (int i = n - 1; i >= 0; i--){
        exist = false;
        for (int j = i - 1; j >= 0;j--){
            if (a[i] >= a[j]){
                a[i] = a[j];
                exist = true;
                break;
            }
        }
        if (!exist){
            a[i]= -1;
        }
    }
    for (int i = 0;i < n;i++){
        cout << a[i] << ' ';
    }
}

//run id:4847