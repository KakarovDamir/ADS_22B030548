#include <iostream>

using namespace std;

int main (){
    int t;
    cin >> t;
    int a[t];

    for (int i = 0;i < t;i++){
        cin >> a[i];
    }

    int n, m;
    cin >> n >> m;
    int b[n][m];

    for (int i = 0;i < n;i++){
        for (int j = 0;j < m; j++){
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < t;i++){
        bool f  = false;
        for (int j = 0;j < n;j++){

            int r = m - 1, l = 0, mid = 0;
            if (j % 2 == 0){
                while(l <= r){
                    mid = l + (r - l) / 2;

                    if (a[i] == b[j][mid]){
                        f = true;
                        cout << j << ' ' << mid << '\n';
                        break;
                    }
                    if (a[i] > b[j][mid]){
                        r = mid - 1;
                    }
                    else{
                        l = mid + 1; 
                    }
                }
            }
            else{
                while (l <= r){
                    mid = l + (r - l) / 2;
                    if (a[i] == b[j][mid]){
                        f = true;
                        cout << j << ' ' << mid << '\n';
                        break;
                    }
                    if (a[i] > b[j][mid]){
                        l = mid + 1; 
                    }
                    else{
                        r = mid - 1; 
                    }
                }
            }
        }
        if (!f){
            cout << -1 << '\n';
        }
    }
}

//1345