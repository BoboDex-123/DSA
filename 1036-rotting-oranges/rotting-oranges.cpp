class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        int fresh=0,minutes=0;  
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(fresh==0) return 0;
        vector<pair<int,int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            bool changed=false;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto[x,y]=q.front();q.pop();
                for(auto[dx,dy]:dirs)
                {
                    int nx=x+dx,ny=y+dy;
                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                        changed=true;
                    }
                }
            }
            if(changed) minutes++;
        }
        return fresh==0?minutes:-1;
    }
};