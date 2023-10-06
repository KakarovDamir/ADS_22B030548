#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int p;
    cin >> p;
    int b[p];
    for (int i = 0;i < p;i++){
        cin >> b[i];
    }

    for (int i = 0;i < p;i++){
        int cnt = 0, sum = 0;
        for (int j = 0;j < n; j++){
            if (b[i] >= a[j]){
                cnt++;
                sum += a[j];
            }else{
                continue;
            }
        }
        cout << cnt << ' ' << sum << '\n';
    }
    return 0;
}
//	2327