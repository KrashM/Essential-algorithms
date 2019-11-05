#include <bits/stdc++.h>
using namespace std;

struct node {

    struct node *left, *right;
    int key;

};

struct node *newNode(int item) {

    struct node *temp = (struct node *)malloc(sizeof(struct node));

    temp->key = item;
    temp->left = temp->right = NULL;

    return temp;

}

void inOrder(struct node *root) {

    if(root != NULL){

        inOrder(root -> left);
        printf("%d \n", root -> key);
        inOrder(root -> right);

    }

}

struct node* insert(struct node* node, int key) {

    if(node == NULL) return newNode(key);

    if(key < node->key) node->left  = insert(node->left, key);
    else
        if(key > node->key) node->right = insert(node->right, key);

    return node;
}

int main() {

    struct node *root = NULL;

    int n, x;

    cin >> n >> x;

    root = insert(root, x);

    for(int i = 1; i < n; i++){

        cin >> x;
        insert(root, x);

    }

    inOrder(root);

    return 0;

}
