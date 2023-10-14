#include <iostream>

using namespace std;

struct node{
    int val;
    node* right;
    node* left;
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
            cur->left = add(cur->left,x);
        }
        else if (cur->val < x){
            cur->right = add(cur->right, x);
        }
        return cur;
    }
    
    int cnt_tr(node* cur, int cnt){
        if (cur != NULL) {
            if (cur->right != NULL && cur->left != NULL)
                cnt++;
            cnt = cnt_tr(cur->left, cnt);
            cnt = cnt_tr(cur->right, cnt);
        }
        return cnt;
    }
};

int main (){
    bst* b = new bst;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++){
        int x; cin >> x;
        if (b->root == NULL){
            b->root = b->add(b->root,x);
        }
        else{
            b->add(b->root,x);
        }
    }

    int cnt = b->cnt_tr(b->root, 0);
    cout << cnt << endl;

    return 0;
}

//3051