#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* left, *right;
    int key;
    Node(int x){
        key = x;
        left = right = NULL;
    }
};
bool find(Node* root,int n){
    if(root == NULL)return 0;
    else if(root ->key == n)return 1;
    else if(root ->key > n)return find(root->left,n);
    else return (root -> right,n);
}
bool itrSearch(Node* root,int n){
    Node* curr  = root;
    while(curr){
        if(curr->key == n)return true;
        else if(curr ->key > n)curr = curr ->left;
        else curr = curr ->right;
    }
    return 0;
}
int main(){
    Node* root = new Node(30);
    root ->left = new Node(20);
    root ->left->left = new Node(10);
    root ->left->right = new Node(25);
    root ->right = new Node(40);
    root ->right->right = new Node(50);
    cout << find(root,10);
    return 0;
}