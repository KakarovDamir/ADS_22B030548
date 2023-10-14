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

node *search (node *root, int x) {
    if (root == NULL)
        return NULL;
    if (root->val == x)
        return root;
    node *found = search(root->left, x);
    if (found == NULL)
    found = search(root->right, x);
    return found;
}


int getHeight (node *cur) {
    if (cur == NULL)
        return 0;
    int lHeight = getHeight(cur->left);
    int rHeight = getHeight(cur->right);
    return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
}

int getWidth (node *cur, int level) {
    if (cur == NULL)
        return 0;
    if (level == 1)
        return 1;
    else {
        return getWidth(cur->left, level - 1) + getWidth(cur->right, level - 1);
    }
}

int getMaxWidth (node *cur) {
    int max = 0, width;
    int h = getHeight(cur);
    for (int i = 1; i <= h; i++) {
        width = getWidth(cur, i);
        if (width > max)
            max = width;
    }
    return max;
}



int main (){
    node* root = NULL;
    node* cur;
    int n;
    cin >> n;
    for (int i = 1; i < n;i++){
        int x, y, z; cin >> x >> y >> z;
        if (root == NULL){
            cur = new node(x);
            root = cur;
        }
        else{
            cur = search(root, x);
        }
        node* temp = new node(y);
        if (z == 0)
            cur->left = temp;
        else
            cur->right = temp;
    }
    cout << getMaxWidth(root);
    return 0;
}

//5691