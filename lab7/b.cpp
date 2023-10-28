#include <iostream>

using namespace std;

int main (){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    int b[m];
    for (int i = 0;i < m;i++){
        cin >> b[i];
    }

    int i = 0, j = 0;
    while(true){
        if (i != n && j != m ){
            if (a[i] < b[j]){
            cout << a[i] << ' ';
            i++;
            }
            else if(a[i] > b[j]){
                cout << b[j] << ' ';
                j++;
            }
            else{
                cout << a[i] << ' ' << b[j] << ' ';
                i++;
                j++;
            }
        }
        else if (i == n && j != m){
            cout << b[j] << ' ';
            j++;
        }
        else if (j == m  && i != n ){
            cout << a[i] << ' ';
            i++;
        }
        else{
            break;
        }
    }
}

//2186