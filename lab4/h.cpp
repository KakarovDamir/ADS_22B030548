#include <iostream>

using namespace std;

int pre = 0;

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

    node* add(node*cur, int x){
        if(cur == NULL){
            cur = new node(x);
        }
        else if (cur->val > x){
            cur->left = add(cur->left, x);
        }
        else if (cur->val < x){
            cur->right = add(cur->right, x);
        }
        return cur;
    }

    node* bstToGst(node* cur){
        if(cur->right != NULL){
            bstToGst(cur->right);
        }
        pre = cur->val = pre + cur->val;
        if(cur->left != NULL){
            bstToGst(cur->left);
        }
        return cur;
    } 

    void print(node*cur){
        if(cur != NULL){
            print (cur->right);
            cout << cur->val << ' ';
            print (cur->left);
        }
    }
};

int main (){
    bst*b = new bst;
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

    b->bstToGst(b->root);
    b->print(b->root);
}

//4075