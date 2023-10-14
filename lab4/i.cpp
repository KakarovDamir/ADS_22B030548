#include <iostream>
#include <string>

using namespace std;

struct node{
    int val;
    int cnt;
    node* left;
    node* right;
    node(int val){
        this->val = val;
        this->cnt = 1;
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
        else if (cur->val == x){
            cur->cnt += 1;
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

    node* rightMost(node* cur){
        if (cur == NULL) return NULL;
        if (cur->right == NULL) return cur;
        return rightMost(cur->right);
    }

    node* del(node* cur, int x){
        if (cur == NULL){
            return NULL;
        }
        if(cur->val == x){
            if (cur->cnt == 0){
                if (cur->left == NULL && cur->right == NULL){
                    delete cur;
                    return NULL;
                }
                else if (cur->left == NULL && cur->right != NULL){
                    node* temp = cur->right;
                    delete cur;
                    return temp;
                }
                else if (cur->left != NULL && cur->right == NULL){
                    node* temp = cur->left;
                    delete cur;
                    return temp;
                }
                else if (cur->left != NULL && cur->right != NULL){
                    node* temp = rightMost(cur->left);
                    if (temp != NULL){
                        cur->val = temp->val;
                    }
                    cur->left = del(cur->left, cur->val);
                }
            }
            else{
                cur->cnt -= 1;
                return cur;
                }
        }
        else if (cur->val > x){
            cur->left = del(cur->left, x);
        }
        else if (cur->val < x){
            cur->right = del(cur->right, x);
        }
        return cur;
    }
};

int main (){
    bst* b = new bst;
    int n;
    cin >> n;
    for (int i = 0;i < n;i++){
        string s;cin >> s;
        int x; cin >> x;
        if (s == "insert"){
            if (b->root == NULL){
                b->root = b->add(b->root, x);
            }
            else{
                b->add(b->root, x);
            }
        }
        else if (s == "delete"){
            b->del(b->root, x);
        }
        else if(s == "cnt"){
            node* found = b->find(b->root, x);
            if (found == NULL){
                cout << 0 <<'\n';
            }
            else{
                cout << found->cnt << '\n';
            }
        }
    }
    return 0;
}

//6482