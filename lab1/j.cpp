#include <bits/stdc++.h>
using namespace std;
int main (){
    char x;
    deque <int> d, dd;
    int n;

    while(true){

        int n;
        cin >> x;

        if (x == '+'){

            cin >> n;
            d.push_front(n);

        }else if(x == '-'){

            cin >> n;
            d.push_back(n);

        }else if (x == '*'){
            if(d.empty()){
                cout << "error" << '\n';
            }else{
                cout << d.front() + d.back() << '\n';
                if(!d.empty()) d.pop_back();
                if(!d.empty()) d.pop_front();
            }
            
        }else if (x == '!'){
            break;
        }
    }
    for (int i = 0;i < dd.size();i++){
        if (dd[i] == -1){
            cout << "error"<<'\n';
        }
        else{
            cout << dd[i]<<'\n';
        }
    }
}

//run id:5297