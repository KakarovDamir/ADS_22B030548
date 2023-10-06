#include <iostream>

using namespace std;

int min_num(int *a, int n, int h,int max){
    int l = 0, m = 0, r = max;
    int res;
    while(l <= r){
        m = l + (r - l) / 2;

        int sum = 0;
        for (int i = 0;i < n;i++){
            if (a[i] % m != 0) {
                sum += (a[i] /  m) + 1;
            }
            else{
                sum += a[i] / m;
            }
        }
        if (sum > h){
            l = m + 1;
        }
        else{
            res = m;
            r = m - 1;
        }
    }
    return res;
}

int main(){
    int n, h;
    cin >> n >> h;

    int a[n],max = 0;
    for (int i = 0;i < n;i++){
        cin >> a[i];
        if (a[i]>max){
            max = a[i];
        }
    }
    int res = min_num(a,n,h,max);
    cout << res;
    return 0;
}
//3283