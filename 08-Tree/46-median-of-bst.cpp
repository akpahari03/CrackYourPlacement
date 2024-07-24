//aproach 1 TC:O(n) and SC:O(n)
void inOrder(struct Node *root,vector<int>& ans) {
    if(root==NULL) return;
    inOrder(root->left,ans);
    ans.push_back(root->data);
    inOrder(root->right,ans);
}
float findMedian(struct Node *root)
{
    vector<int> in;
    inOrder(root,in);
    int n=in.size();
    float ans;
    int mid=n/2;
    if(n%2!=0) {
        ans = in[mid];
    }
    else ans=(in[mid]+in[mid-1])/2.0;
    return ans;
}

//aproach 2
