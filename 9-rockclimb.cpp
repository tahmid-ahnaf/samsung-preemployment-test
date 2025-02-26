#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;
int n,m;

bool isValid (int c , int cellValue)
{
    return c>=0 && c<m && cellValue>0;
}
void bfs(int r, int c , vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    queue<pair<int,int>> q;
    q.push({r,c});
    
    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        
        q.pop();
        
        if(isValid(c+1,grid[r][c+1]) && dp[r][c+1]>dp[r][c])
        {
            dp[r][c+1] = dp[r][c];
            q.push({r,c+1});
        }
        
        if(isValid(c-1,grid[r][c-1]) && dp[r][c-1]>dp[r][c])
        {
            dp[r][c-1] = dp[r][c];
            q.push({r,c-1});
        }
        
        for(int i=0; i<n; i++)
        {
            if(i!=r && grid[i][c]>0)
            {
                int dis = max(abs(i-r), dp[r][c]);
                if(dp[i][c]>dis)
                {
                    dp[i][c] = dis;
                    q.push({i,c});
                }
            }
        }
        
    }
}
int main() {
    
    
    cin>>n>>m;
    
    vector<vector<int>> grid(n, vector<int> (m));
    vector<vector<int>> dp(n, vector<int> (m, n-1));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }
    dp[n-1][0] = 0;
    bfs(n-1, 0, grid, dp);
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]==3)
            {
                cout<<dp[i][j]<<endl;
            }
        }
    }
    
}