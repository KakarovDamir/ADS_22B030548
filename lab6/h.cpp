#include <iostream>
using namespace std;

#include <iostream>

using namespace std;

int partition (string& s,int low, int high){
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

void qsort(string& s, int low, int high){
    if (low < high){
        int pivot = partition(s, low, high);
        qsort(s, low, pivot - 1);
        qsort(s, pivot + 1, high);
    }
}

int main (){
    int n;
    cin >> n;
    string s;
    char a;
    for (int i = 0;i < n;i++){
        char c; cin >> c;
        s.push_back(c);
    }
    cin >> a;
    qsort(s,0,n-1);
    bool tap = false;
    for (int i = 0;i < n;i++){
        if (s[i] > a){
            cout << s[i];
            tap = true;
            break;
        }
        else{
            continue;
        }
    }
    if (!tap){
        cout << s[0];
    }
}

//3724