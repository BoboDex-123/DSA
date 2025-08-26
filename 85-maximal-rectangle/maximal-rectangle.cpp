class Solution {

    int histogram(vector<int>& height)
    {
        stack<int> s;
        s.push(-1);
        int n=height.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            while(s.top()!=-1 && height[i]<height[s.top()])
            {
                int h=height[s.top()];
                s.pop();
                int width=i,pse=(s.top()==-1)?-1:s.top();
                maxi=max(maxi,h*(width-pse-1));
            }
            s.push(i);
        }

        while(s.top()!=-1)
        {
            int h=height[s.top()];
            s.pop();
            int pse=(s.top()==-1)?-1:s.top();
            int w=n;
            maxi=max(maxi,h*(w-pse-1));
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n=matrix.size(),m=matrix[0].size(),res=0;
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