#include <iostream>

using namespace std;

struct node{
    int val;
    node* right;
    node* left;
    node(int val){
        this->val = val;
        this->right = this->left = NULL;
    }
};

struct bst{
    node* root ;
    bst(){
        this->root = NULL;
    }
    node* add(node* cur, int x){
        if(cur == NULL){
            cur = new node(x);
        }
        else if (cur->val > x){
            if (cur->left == NULL){
                cur->left = add(cur->left, x);
            }
            else{
                add(cur->left, x);
            }
        }
        else{
            if (cur->right == NULL){
                cur->right = add(cur->right,x);
            }
            else{
                add(cur->right,x);
            }
        }
        return cur;
    }

    node* search(node* cur, int x){
        if (cur == NULL){
            return NULL;
        }
        if (cur->val == x){
            return cur;
        }
        if (cur->val < x){
            return search(cur->right, x);
        }
        return search(cur->left,x);
    }

    int count(node* cur) {
        if (cur==NULL)return 0;
        int cnt=0;
        if(cur != NULL){
            cnt+=1;
            cnt+=count(cur->left);
            cnt+=count(cur->right);
        }
        return cnt;
    }
};

int main(){
    bst * b = new bst;
    int n;
    cin >> n;

    for (int i  = 0;i < n;i++){
        int x;
        cin >> x;
        if (b->root == NULL){
            b->root = b->add(b->root, x);
        }
        else{
            b->add(b->root,x);
        }
    }
    int m, cnt = 0;
    cin >> m;

    node* cur = b->search(b->root, m);
    cout<<bst().count(cur);

    return 0;
}

//875