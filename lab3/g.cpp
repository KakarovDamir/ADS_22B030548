#include <iostream>

using namespace std;

int santa(int* a,int n,int m, int max){
    int mid = 0, l = 1, r = max * m;
    while(l < r){
        mid = l + (r - l) / 2;
        int cnt = 0;
        
        for (int i = 0;i < n;i++){
            cnt += a[i] / mid;
            if (a[i] % mid != 0){
                cnt++;
            }
        }
        if (cnt <= m){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}

int main (){
    int n, m;
    cin >> n >> m;

    int a[n], max = 0;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        if (max < a[i]){
            max = a[i];
        }
    }

    int ans = santa(a,n,m,max);
    cout << ans ;
}

//2393