#include <iostream>

using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int val){
        this->val = val;
        this->left = this->right = NULL;
    }
};

struct bst{
    node* root;

    bst(){
        this->root = NULL;
    }
    node* add(node* cur, int x){
        if(cur == NULL){
            cur = new node(x);
        }
        else if (cur->val > x){
            if (cur->left == NULL){
                cur->left = add(cur->left,x);
            }
            else{
                add(cur->left,x);
            }
        }
        else{
            if(cur->right == NULL){
                cur->right = add(cur->right,x);
            }
            else{
                add(cur->right,x);
            }
        }
        return cur;
    }

    node* find(node* cur,int x){
        if (cur == NULL){
            return NULL;
        }
        if (cur->val == x){
            return cur;
        }
        if (cur->val < x){
            return find(cur->right,x);
        }
        return find(cur->left,x);
    }

    void print(node* cur){
        if (cur != NULL){
            cout << cur->val << ' ';
            print (cur->left);
            print (cur->right);
        }
    }
};

int main(){
    bst * b = new bst;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++){
        int x;
        cin >> x;
        if (b->root == NULL){
            b->root =b->add(b->root,x);
        }
        else{
            b->add(b->root, x);
        }
    }
    int m;
    cin >> m;
    node* cur = b->find(b->root, m);
    b->print(cur);
}

//891