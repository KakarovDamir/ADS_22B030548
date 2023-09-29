#include <bits/stdc++.h>
using namespace std;
void deck(int x){
    deque <int> card;
    for (int i = x; i > 0;i--){
        card.push_back(i);
        for (int j = 0;j <= i;j++){
            int a = card.back();
            card.pop_back();
            card.push_front(a);
        }
    }
    for(int i = 0;i < card.size();i++){
        cout << card[i] <<' ';
    }
    cout <<'\n';
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (int i = 0;i < n;i++){
        deck(a[i]);
    }
}

//run id:5209