#include <iostream>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int a[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < q; i++){
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--; z--;

        if(a[x][y] && a[y][z] && a[x][z]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}