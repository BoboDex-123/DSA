class Solution {

    int histogram(vector<int>& height)
    {
        int n=height.size();
        stack<int> s;
        s.push(-1);
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            while(s.top()!=-1 && height[i]<height[s.top()])
            {
                int h=height[s.top()];
                s.pop();
                int w=i,pse=(s.top()==-1)?-1:s.top();
                maxi=max(maxi,h*(w-pse-1));
            }
            s.push(i);
        }

        while(s.top()!=-1)
        {
            int h=height[s.top()];
            s.pop();
            int w=n,pse=(s.top()==-1)?-1:s.top();
            maxi=max(maxi,h*(w-pse-1));
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if(matrix.empty()) return 0;
        int n=matrix.size(),m=matrix[0].size();
        int res=0;
        vector<int> height(m,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            res=max(res,histogram(height));
        }
        return res;
    }
};