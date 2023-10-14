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
        if (cur == NULL){
            cur = new node(x);
        }
        else if (cur->val > x){
            cur->left = add(cur->left, x);
        }
        else if(cur->val < x){
            cur->right = add(cur->right, x);
        }
        return cur;
    }
    node* find(node* cur, int x){
        if (cur == NULL){
            return NULL;
        }
        if (cur->val == x){
            return cur;
        }
        if(cur->val < x){
            return find(cur->right, x);
        }
        return find(cur->left, x);
    }

    int height(node *cur, int& diameter) {
        if (cur == NULL)
            return 0;
        int h1 = height(cur->left, diameter);
        int h2 = height(cur->right, diameter);
        diameter = max(diameter, h1 + h2);
        return 1 + max(h1, h2);
    }

    int getPath(node *root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

    void print (node* cur){
        if (cur != NULL){
            print(cur->left);
            cout << cur->val << " ";
            print(cur->right);
        }
    }
};

int main (){
    bst* b = new bst;
    int n;
    cin >> n;

    for (int i = 0;i < n;i++){
        int x; cin >> x;
        if (b->root == NULL){
            b->root = b->add(b->root, x);
        }
        else{
            b->add(b->root, x);
        }
    }
    cout << b->getPath(b->root) + 1;
    return 0;
}

//3243