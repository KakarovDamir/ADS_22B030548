#include <iostream>
#include <string>

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
    cin >> s;
    string v;
    int i = 0;
    while (i < s.size()){
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'||
            s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                v.push_back(s[i]);
                if (i == s.size()-1){
                    s.pop_back();
                }
                else{
                swap(s[i],s[s.size()-1]);
                s.pop_back();
                i--;
                }
            }  
            i++; 
    }
    qsort(v,0,v.size() - 1);
    qsort(s,0,s.size() - 1);
    v = v + s;
    for (int i = 0;i < v.size();i++){
        cout << v[i];
    }
}

//527