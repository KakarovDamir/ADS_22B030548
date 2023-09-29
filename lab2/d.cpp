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
    node*head = NULL;
    node*tail = NULL;
    void append(int x){
        node* temp = new node(x);
        if (head  == NULL){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    void Mode(int n){
        node* cur = head;
        map <int,int> m;
        int pos = 0, max = INT_MIN;
        for (int i = 0;i < n;i++){
            int cnt  = 0;
            node* cur2 = head;
            for (int j = 0;j < n; j++){
                if (cur->val == cur2->val){
                    cnt++;
                }
                cur2 = cur2->next;
            }
            if (cnt >= max){
                max = cnt;
                m[cur->val] = max;
            }
            cur = cur->next;
        }
        
        for (auto itr = m.crbegin(); itr != m.crend(); ++itr){
            if (itr->second == max){
                cout << itr->first << ' ';
            }
        }
    }
};
int main (){
    ll list;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++){
        int x;
        cin >> x;
        list.append(x);
    }
    list.Mode(n);
}

//run id:2449