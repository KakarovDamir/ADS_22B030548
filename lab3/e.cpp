#include <iostream>

using namespace std;

bool check(int a[][4], int n, int k, int m){
    int cnt = 0;
    for (int i = 0;i < n;i++){
        int width = a[i][0] + abs(a[i][2] - a[i][0]);
        int height = a[i][1] + abs(a[i][3] - a[i][1]);

        if (width <= m && height <= m ){
            cnt++;
        }
    }

    return cnt >= k;
}

int length(int a[][4],int n, int k,int max){
    int l = 1, r = max, m = 0;
    int result = 0;
    while(l <= r){
        m = l + (r - l) / 2;
        if (check(a,n,k,m)){
            result = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return result;
}

int main (){
    int n, k;
    cin >> n >> k;

    int a[n][4];
    int max = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0;j < 4; j++){
            cin >> a[i][j];
            if (a[i][j]>max){
                max = a[i][j];
            }
        }
    }

    int ans = length(a,n,k, max);
    cout << ans;
    return 0;
}

//2284