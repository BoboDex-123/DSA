/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<tuple<int,int,int>> nodes;    //col,row,value
        queue<tuple<TreeNode*,int,int>> q;
        q.push({root,0,0});
        while(!q.empty())
        {
            auto[node,row,col]=q.front();
            q.pop();
            if(!node) continue;

            nodes.push_back({col,row,node->val});

            q.push({node->left,row+1,col-1});
            q.push({node->right,row+1,col+1});
        }

        sort(nodes.begin(),nodes.end(),[](auto &a,auto &b)
        {
            auto[col1,row1,val1]=a;
            auto[col2,row2,val2]=b;
            if(col1!=col2) return col1<col2;
            if(row1!=row2) return row1<row2;
            return val1<val2;
        });

        vector<vector<int>> result;
        int prevCol=INT_MIN;

        for(auto&[col,row,val]:nodes)
        {
            if(col!=prevCol)
            {
                result.push_back({});
                prevCol=col;
            }
            result.back().push_back(val);
        }
        return result;
    }
};