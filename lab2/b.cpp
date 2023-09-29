#include <bits/stdc++.h>
using namespace std;

struct node{
    string val;
    node* next;
    node(string val){
        this->val = val;
        this->next = NULL;
    }
};
struct ll{
    node* head = NULL;
    node* tail = NULL;

    void append(string x){
        node* temp = new node(x);
        if (head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
    }
    void poem(int n,int m){
        node*cur = head;
        string h,l;
        int i = 0;
        while (i < n + m){
            if (i < m){
                append(cur->val);
            }
            else if (i >= m){
                cout << cur->val << ' ';
            }
            cur = cur->next;
            i++;
        }
    }

};
int main (){
    ll list;
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < n;i++){
        string s;
        cin >> s;
        list.append(s);
    }
    list.poem(n,m);

}

//run id:1749