#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node*next;
    node(int val){
        this->val = val;
        this->next = NULL;
    }
};
struct ll{
    node* head = NULL;
    node* tail = NULL;
    void pushback(int x){
        node* temp = new node(x);
        if (head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp; 
        }
    }
    void del(int n){
        node* cur = head;
        for (int i = 0;i < n;i++){
            if (i % 2 == 0){
                cout << cur->val << ' ';
            }
            cur = cur->next; 
        }
    }
};
int main (){
    ll list;
    int n = 0;
    cin >> n;
    for (int i = 0;i < n;i++){
        int x;
        cin >> x;
        list.pushback(x);

    }
    list.del(n);
}
//run id:1784