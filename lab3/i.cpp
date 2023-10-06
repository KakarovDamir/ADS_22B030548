#include <iostream>
using namespace std;
int main (){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    
    int l = 0,m = 0,r = n;
    bool taptim = false;
    while(l <= r){
        m = l + (r - l) / 2;

        if (x == a[m]){
            taptim = true;
            break;
        }
        if (x > a[m]){
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    if(taptim){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}
//1134