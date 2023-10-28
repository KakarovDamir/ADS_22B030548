#include <iostream>

using namespace std;
 

int partition(int a[], int low, int high){
    int i = low - 1;
    int pivot = high;
    for(int j = low; j <= high - 1; ++j){
        if(a[j]< a[pivot]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1;
}


void qsort(int a[], int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main (){
    int n, m;
    cin >> n >> m;
    int a[m][n];
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            cin >> a[j][i];
        }
    }
    
    for (int i = 0;i < m;i++){
        qsort(a[i], 0, n - 1);
    }
    for (int i = n-1 ;i >= 0;i--){
        for (int j = 0;j < m;j++){
            cout << a[j][i] << ' ';
        }
        cout << '\n';
    }
}

//3789