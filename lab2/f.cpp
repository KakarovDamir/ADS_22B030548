#include <iostream>

using namespace std;

struct node{
    int val;
    node*next;
    node*prev;
    node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
struct ll{
    node* head = NULL;
    node* tail = NULL;
    void push_back(int x){
        node* temp = new node(x);
        if (head == NULL){
            head = temp;
            tail = temp;
        } else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    void print(int a, int index){
        node* cur = head;
        int i = 0;
        while(cur != NULL){
            if (i != index){
                cout << cur->val << ' ';
                cur = cur->next;
            }
            else{
                cout << a << ' ';
            }
            
            i++;
        }
    }
};

int main(){
    ll list;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++){
        int x;
        cin >> x;
        list.push_back(x);
    }
    int a, index;
    cin >> a >> index;
    list.print(a,index);

}

//run id:3289