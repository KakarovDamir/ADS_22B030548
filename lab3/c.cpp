#include <iostream>

using namespace std;
int patchwork(int l1, int r1, int l2, int r2, int *a,int n){
    int cnt = 0;
    for (int i = 0;i < n;i++){
        if ((l1 <= a[i] && a[i] <= r1) || (l2 <= a[i] && a[i] <= r2)){
            cnt++;
        }
    }
    return cnt;
}


int main (){
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int b[m][4];
    for (int i = 0; i < m;i++){
        int l1, r1 , l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = patchwork(l1,r1,l2,r2,a,n);
        cout << ans << '\n';
    }
    return 0;
}
//1405