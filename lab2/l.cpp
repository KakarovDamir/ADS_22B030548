#include <bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node* next ;
    node(int val){
        this->val = val;
        this->next = NULL;
    }
};

struct ll{
    node* head = NULL;
    node* tail = NULL;
    void push(int x){
        node* temp = new node(x);
        if (head == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    void max(int n){
        node* cur = head;
        int max1 = INT_MIN, max2 = 0;
        for (int i = 0;i < n;i++){
            max2 += cur->val;
            if (max1 < max2){
                max1 = max2;
            }
            if (max2 < 0){
                max2 = 0;
            }
            cur = cur->next;
        }
        cout << max1;
    }
};

int main(){
    ll list;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;cin >> x;
        list.push(x);
    }
    list.max(n);
}
//run id:3486