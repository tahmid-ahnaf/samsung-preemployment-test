#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int tsp (int n, int pos, int initial_mask, int all_visited_mask, vector<vector<int>>&dist)
{
    
    if(initial_mask==all_visited_mask)
    {
        return dist[pos][0];
    }
    
    int ans=INT_MAX;
    
    for(int city=0; city<n; city++)
    {
        if((initial_mask & (1<<city)) == 0)
        {
            int y = initial_mask|(1<<city);
            int tempAns = dist[pos][city] + tsp(n,city,y,all_visited_mask, dist);
            ans = min(tempAns, ans);
        }
    }
    return ans;
    
}


int main() {

    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        vector<vector<int>>dist;
        
        for(int i=0; i<n; i++)
        {
            vector<int> tmp;
            for(int j=0; j<n; j++)
            {
                int x;
                cin>>x;
                
                tmp.push_back(x);
            }
            
            dist.push_back(tmp); 
        }
        
        int initial_mask = 1;
        int all_visited_mask = (1<<n) -1;
        
        cout<< tsp(n,0,initial_mask,all_visited_mask, dist)<<endl;
    }
}