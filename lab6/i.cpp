#include <iostream>
#include <string>

using namespace std;

int partition(string& s, int low, int high){
    int i = low - 1;
    int pivot = high;
    for (int j = low;j <= high - 1;j++){
        if (s[j] < s[pivot]){
            i++;
            swap(s[i],s[j]);
        }
    }
    swap(s[i + 1], s[pivot]);
    return i + 1;
}

int qsort (string& s, int low, int high){
    if (low < high){
        int pivot = partition(s, low, high);
        qsort(s, low, pivot - 1);
        qsort(s,pivot + 1, high);
    }
}

int main (){
    string s;
    cin >> s;
    qsort(s, 0, s.size() - 1);
    for (int i = 0;i < s.size();i++){
        cout << s[i];
    }
}

//1339