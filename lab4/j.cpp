#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> balance;

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
    vector <int> nums;

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
        else if (cur->val < x){
            cur->right = add(cur->right, x);
        }
        return cur;
    }

    void inorder(node* cur){
        if (cur != NULL){
            inorder(cur->right);
            nums.push_back(cur->val);
            inorder(cur->left);
        }
    }

    void toBalance(int left, int right){
        if (left > right){
            return;
        }
        else{
            int mid = left + (right - left) / 2;
            balance.push_back(nums[mid]);
            toBalance(left, mid - 1);
            toBalance(mid + 1, right);
        }
    }
};

int main (){
    bst * b = new bst;
    int n;
    cin >> n;
    n = pow(2,n) - 1;
    for (int i = 0;i < n;i++){
        int x; cin >> x;
        if (b->root == NULL){
            b->root = b->add(b->root, x);
        }
        else{
            b->add(b->root, x);
        }
    }
    b->inorder(b->root);
    b->toBalance(0, n - 1);
    for (int i = 0;i < n;i++){
        cout << balance[i] << ' ';
    }
    return 0;
}

//7091