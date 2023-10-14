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

    node* add(node* cur,int x){
        if (cur == NULL){
            cur = new node(x);
        }
        else if(cur->val > x){
            if (cur->left == NULL){
                cur->left = add(cur->left,x);
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

    void print(node* cur){
        if (cur != NULL){
            print(cur->left);
            cout << cur->val << ' ';
            print(cur->right);
        }
    }
};

int main (){
    bst* b = new bst;
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < n;i++){
        int x;
        cin >> x;
        if (b->root == NULL){
            b->root = b->add(b->root,x);
        }
        else{
            b->add(b->root,x);
        }
    }

    while(m--){
        string s; cin >> s;
        node* cur = b->root;

        for (int i = 0;i < s.size();i++){
            if (cur == NULL){
                break;
            }
            if (s[i] == 'L'){
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        if(cur != NULL) {
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}

//822