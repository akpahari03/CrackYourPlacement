class info {
    public:
        int maxi;
        int mini;
        bool isBST;
        int size;
};
class Solution{
    public:
    info solve(Node* root , int& ans) {
        if(root==NULL) return{INT_MIN,INT_MAX,true,0};
        
        info left=solve(root->left,ans);
        info right=solve(root->right,ans);
        
        info currNode;
        currNode.maxi=max(root->data,right.maxi);
        currNode.mini=min(root->data,left.mini);
        currNode.size=left.size+right.size+1;
        
        if(left.isBST && right.isBST && (root->data>left.maxi && root->data < right.mini)) {
            currNode.isBST=true;
        } 
        else {
            currNode.isBST=false;
        }
        if(currNode.isBST) {
            ans=max(ans,currNode.size);
        }
        return currNode;
    }
    int largestBst(Node *root)
    {
    	int maxSize=0;
    	info temp=solve(root,maxSize);
    	return maxSize;
    	
    }
};