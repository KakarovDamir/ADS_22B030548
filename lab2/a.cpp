#include <bits/stdc++.h>

using namespace std;

struct node{
    int val;
    node*next;
    node(int val){
        this->val = val;
        this->next =  NULL;
    }
};
struct ll{
        node * head = NULL;
        node * tail = NULL;
        
        void append(int x){
            node * temp = new node(x);
            if (head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
        }
        void Nnum(int k, int n){
            node* cur = head;
            int b = INT_MAX, pos;
            for (int i = 0;i < n;i++){
                if (abs(k - cur->val) < b){
                    b = abs(k - cur->val);
                    pos = i;
                }
                cur = cur->next;
            }
            cout << pos;
        }
};


int main(){
    ll list;
    int n, k;
    cin >> n;
    for (int i = 0;i < n;i++){
        int x;
        cin >> x;
        list.append(x);
    }
    cin >> k;
    list.Nnum(k,n);
}

//run id:1715