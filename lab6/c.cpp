#include <iostream>

using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    quickSort(a,0, n - 1);

    int x = abs(a[1] - a[0]);
    for (int i = 0;i < n;i++){
        if (abs(a[i + 1]-a[i]) < x){
            x = abs(a[i + 1]-a[i]);
        }
    }
    for (int i = 0;i < n;i++){
        if (abs(a[i + 1]-a[i]) == x){
            cout << a[i] << ' '<< a[i + 1] <<' ';
        }
    }
}

//1328