#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[7] = {2,3,1,7,11,6,7};
    
    int b, i = 0, n = 7;
    for (i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false){
            break;}
    }
    for (int i = 0;i < 7;i++){
        cout << arr[i] <<' ';
    }
    cout << '\n';
    int v1 = 1, v2 = 6, v3 = 5;
    int l = 0, m = 0, r = n;
    while (r >= l){
        m = l + (r-l) / 2;
        if (arr[m] == v1){
            cout << "Bitti:"<< m;
            break;
        }
        if (arr[m] < v1){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
        cout << r << ' ' << l << ' ' << m << '\n';
    }
}