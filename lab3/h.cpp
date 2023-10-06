#include <iostream>

using namespace std;

int check(int* p, int t, int n){
    int m = 0, l = 0, r = n;
    while(l <= r){

            m = l + (r - l) / 2;
            if (t <= p[m]){
                if (t > p[m-1]){
                    return m;
                }
                else{
                    r = m - 1; 
                }
            }
            else{
                l = m + 1;
            }
        }
    return m;
}

int main (){
    int n, m;
    cin >> n >> m;
    int a[n], sum = 0, p[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
        sum += a[i];
        p[i] = sum;
    }

    int b[m];
    for (int i = 0;i < m;i++){
        cin >> b[i];
    }

    for (int i = 0;i < m;i++){
        int ans = check(p,b[i],n) + 1;
        cout << ans << '\n';
    }
}

//2373