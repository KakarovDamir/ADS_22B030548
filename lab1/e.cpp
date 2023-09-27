#include <bits/stdc++.h>
using namespace std;
int main (){
    int range = 1000000;
    queue <int> boris, nursik;
    for(int i = 0;i < 10;i++){
        int a;
        if (i >= 0 && i < 5){
            cin >> a;
            boris.push(a);
        }else{
            cin >> a;
            nursik.push(a);
        }
    }
    for (int i = 1;i <= range;i++){
        if(boris.front() == 9 && nursik.front() == 0){
            int win1 = boris.front(), win2 = nursik.front();
            boris.pop();
            nursik.pop();
            nursik.push(win1);
            nursik.push(win2);
        }else if(boris.front() == 0 && nursik.front() == 9){
            int win1 = boris.front(), win2 = nursik.front();
            boris.pop();
            nursik.pop();
            boris.push(win1);
            boris.push(win2);
        }else if (boris.front()>nursik.front()){
            int win1 = boris.front(), win2 = nursik.front();
            boris.pop();
            nursik.pop();
            boris.push(win1);
            boris.push(win2);
        }else{
            int win1 = boris.front(), win2 = nursik.front();
            boris.pop();
            nursik.pop();
            nursik.push(win1);
            nursik.push(win2);
        }
        if(boris.empty()){
            cout <<"Nursik " << i;
            break;
        }else if(nursik.empty()){
            cout <<"Boris "<<i;
            break;
        }
        if (i+1 == range){
            cout <<"blin nichya";
        }
    }
}