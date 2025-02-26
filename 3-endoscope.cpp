#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include<iostream>
using namespace std;


struct Node {
    int x,y,l;
};





bool isLeftOpen (int x, int y, vector<vector<int>> &map)
{
    return (map[x][y]==1 || map[x][y]==3 || map[x][y]==6 || map[x][y]==7 );
}

bool isRightOpen (int x, int y,vector<vector<int>> &map)
{
    return (map[x][y]==1 || map[x][y]==3 || map[x][y]==4 || map[x][y]==5 );
}

bool isUpOpen (int x, int y,vector<vector<int>> &map)
{
    return (map[x][y]==1 || map[x][y]==2 || map[x][y]==4 || map[x][y]==7);
}

bool isDownOpen (int x, int y,vector<vector<int>> &map)
{
    return (map[x][y]==1 || map[x][y]==2 || map[x][y]==6 || map[x][y]==5 );
}

bool isValid (int n, int m, int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}
int solve(int n, int m, int x, int y, int l,vector<vector<int>> &map)
{
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int ans = 0;
    visited[x][y] = 1;
    
    queue<Node> q;
    
    q.push({x,y,l});
    
    while(!q.empty())
    {
        Node node = q.front();
        q.pop();
        
        int x = node.x;
        int y = node.y;
        int l = node.l;
        
        if(l==0) continue;
        
        ans++;
        
        
        if(isLeftOpen(x,y,map) && isValid(n,m, x, y-1) && isRightOpen(x,y-1,map) && visited[x][y-1]==0)
        {
            visited[x][y-1] = 1;
            q.push({x,y-1,l-1});
        }
        
        if(isRightOpen(x,y,map) && isValid(n,m, x, y+1) && isLeftOpen(x,y+1,map) && visited[x][y+1]==0)
        {
            visited[x][y+1] = 1;
            q.push({x,y+1,l-1});
        }
        
        if(isUpOpen(x,y,map) && isValid(n,m, x-1, y) && isDownOpen(x-1,y,map) && visited[x-1][y]==0)
        {
            visited[x-1][y] = 1;
            q.push({x-1,y,l-1});
        }
        
        if(isDownOpen(x,y,map) && isValid(n,m, x+1,y) && isUpOpen(x+1,y,map) && visited[x+1][y]==0)
        {
            visited[x+1][y] = 1;
            q.push({x+1,y,l-1});
        }
        
        
    }
    
    return ans;
}





int main() {

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,x,y,l;
        cin>>n>>m>>x>>y>>l;
        
        vector<vector<int>> map(n, vector<int>(m));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {   
                cin>>map[i][j];
            }
        }
        cout<<solve(n,m,x,y,l,map)<<endl;
    }
    
}