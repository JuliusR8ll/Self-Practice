/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "#";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * curr = q.front();
            q.pop();
            s += curr -> val;
            if(curr -> left)q.push(curr->left);
            else s += "#";
            if(curr -> right)q.push(curr->right);
            else s += "#";          
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        TreeNode* root = new TreeNode(s[0] - '0');
        for(int i = 0;i<s.length()-2;i++){
            while(s[i] == '#'){
                TreeNode* curr = new TreeNode(s[i] - '0');
                i++;
            if(s[i+1] != '#')
                curr ->left = new TreeNode(s[i+1] - '0');
            if(s[i+2] != '#')
                curr ->right = new TreeNode(s[i+2] - '0');
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));