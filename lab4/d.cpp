#include <iostream>
#include <vector>

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
        else if(cur->val > x){
            if(cur->left == NULL){
                cur->left = add(cur->left,x);
            }
            else{
                add(cur->left,x);
            }
        }
        else{
            if(cur->right == NULL){
                cur->right = add(cur->right, x);
            }
            else{
                add(cur->right,x);
            }
        }
        return cur;
    }

    int getHeight(node* root){
    if (root->left == NULL && root->right == NULL)
        return 0;
 
    int left = 0;
    if (root->left != NULL)
        left = getHeight(root->left);
 
    int right = 0;
    if (root->right != NULL)
        right = getHeight(root->right);
 
    return (max(left, right) + 1);
    }

    void calculateLevelSum(node* cur, int level, int* sum){
    if (cur == NULL)
        return;
 
    sum[level] += cur->val;
 
    calculateLevelSum(cur->left, level + 1, sum);
    calculateLevelSum(cur->right, level + 1, sum);
    }

    void print(int arr[], int n){
        cout << n << '\n';
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        }
};


int main(){
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
    
    int cnt = b->getHeight(b->root) + 1;

    int sum[cnt] = { 0 };
    b->calculateLevelSum(b->root, 0, sum);
    b->print(sum, cnt);

    return 0;
}

//2363