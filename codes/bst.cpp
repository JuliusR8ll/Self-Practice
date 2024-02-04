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
void inorder(Node* root){
    if(root == NULL)return;
    inorder(root->left);
    cout << root ->key <<" ";
    inorder(root->right);
}
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
// Node* insert(Node* root,int x){
//     if(root == NULL){
//         Node* curr = new Node(x);
//         return curr;
//     } 
//     if(root->key == x)return root;
//     else if(root->key > x){
//         if(root ->left == NULL){
//             root->left = new Node(x);
//             return root;
//         }
//         else insert(root->left,x);
//         }
//     else{
//         if(root ->right == NULL){
//             root->right = new Node(x);
//             return root;
//         }
//         else insert(root->right,x);
//         }
// }
Node* insert(Node* root,int x){
    if(root == NULL){
        return new Node(x);
    }
    else if(root->key > x){
        root ->left = insert(root->left,x);
    }
    else if(root ->key < x)root -> right = insert(root->right,x);
    return root;
}
Node* itrInsert(Node* root,int x){
    if(root == NULL){
        return new Node(x);
    }
    Node* curr = root;
    while(curr){
        if(curr->key > x){
            if(!curr->left){
                curr -> left = new Node(x);
                break;
            }
            curr = curr->left;
        }
        else if(curr ->key <x){
            if(!curr->right){
                curr -> right = new Node(x);
                break;
            }
            curr = curr ->right;
        }
        else break;
    }
    return root;
}
int getSuccessor(Node* root){ // helper function for deleteion
    while(root && root->left){
        root = root->left;
    }
    return root->key;
}
Node* deletion(Node* root,int x){
    if(root == NULL)return root;
    else if(root ->key > x)root ->left = deletion(root->left,x);
    else if(root ->key < x)root ->right = deletion(root->right,x);
    else{
        if(root->left == NULL){
            Node* curr = root->right;
            delete root;
            return curr;
        }
        else if(root->right == NULL){
            Node* curr = root->left;
            delete root;
            return curr;
        }
        else{
            root->key = getSuccessor(root);
            root ->right = deletion(root->right,root->key);            
        }
    }
    return root;
}
Node* floor(Node* root,int x){
    Node* res = NULL;
    while(root){
        if(root->key == x)return root;
        else if(root->key > x){
            root = root->left;
        }
        else{
            res = root;
            root = root->right;
        }
    }
    return res;
}
int main(){
    Node* root = new Node(30);
    root ->left = new Node(20);
    root ->left->left = new Node(10);
    root ->left->right = new Node(25);
    root ->right = new Node(40);
    root ->right->right = new Node(50);
    //cout << find(root,10);
    //inorder(root);
    //insert(root,21);
    //deletion(root,30);
    //inorder(root);
    Node* curr = floor(root,15);
    cout << curr->key;
    return 0;
}