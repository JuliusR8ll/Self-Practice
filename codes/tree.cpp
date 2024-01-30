#include<bits/stdc++.h>
using namespace std;
 struct Node
 {
    Node* left, *right;
    int data;
    Node(int x){
        data = x;
        right = left = NULL;
    }
 };
 Node* lca(Node* root,Node* n1,Node* n2){
   if(root == NULL)return NULL;
   if(root == n1 || root == n2)return root;
   Node* lca1 = lca(root->left,n1,n2);
   Node* lca2 = lca(root->right,n1,n2);
   if(lca1 != NULL && lca2 != NULL)return root;
   if(lca1 != NULL){
      return lca1;
   }
   else  
      return lca2;
 }
 int countCompleteTreeNodes(Node* root){ // O(logn*logn)
   if(root == NULL)return 0;
   int lh = 0,rh = 0;
   Node* curr = root;
   while(curr){
      curr = curr ->left;
      lh++;
   }
   curr = root;
   while (curr)
   {
      curr = curr ->right;
      rh++;
   }
   if(lh == rh)return pow(2,lh)-1;
   return 1+countCompleteTreeNodes(root->left) + countCompleteTreeNodes(root->right);
 }
 void serialize(Node* root,vector<int> &v){
   if(root == NULL)v.push_back(INT_MAX);
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
      Node* curr = q.front();
      q.pop();
      if(curr->left){
         q.push(curr->left);
         v.push_back(curr->data);
      }
      else v.push_back(INT_MAX);
      if(curr->right){
         q.push(curr->right);
         v.push_back(curr->data);
      }
      else v.push_back(INT_MAX);
      
   }
 }
 Node* deserialize(vector<int> &v){
   Node* root = new Node(v[0]);
   queue<Node*> q;
   q.push(root);
   for(int i = 1;i<v.size()-1;i++){
      Node* curr = q.front();
      q.pop();
      if(v[i] != INT_MAX){
         curr->left = new Node(v[i]);
         q.push(curr->left);
      }
      else curr ->left = NULL;
      if(v[i+1] != INT_MAX){
         curr->right = new Node(v[i+1]);
         q.push(curr->right);
      }
      else curr ->right = NULL;
   }
   return root;
 }
 int main(){
    Node* root = new Node(5);
    root ->left = new Node(2);
    root ->left->left = new Node(9);
    root ->left->right = new Node(8);
    root -> right = new Node(4);
    root -> right->left = new Node(6);
    cout << countCompleteTreeNodes(root);
    return 0;
 }
 