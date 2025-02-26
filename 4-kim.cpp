#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> graph(15, vector<int> (15, 0));

int findCost(int mask, int visited_all_mask, int src, vector<vector<int>> &dp){

    if(src==n-1){
        if(mask == visited_all_mask){
            return 0;
        }
        return 1e9;
    }
    

    int cost=1e9;
    
    for(int node=0; node<n; node++){
        if((mask&(1<<node))==0){
            cost = min(cost, findCost((mask|(1<<node)), visited_all_mask, node, dp) + graph[src][node]);
        }
    }
    
    return cost;
}


int solve(){
    cin>>n;
    n+=2;
    vector<pair<int, int>> coord(n);
    int x, y; cin>>x>>y;
    coord[0] = {x, y};
    cin>>x>>y;
    coord[n-1] = {x, y};

    for(int i=1; i<n-1; i++){
        x, y; cin>>x>>y;
        coord[i] = {x, y};
    }    
   
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int wt = abs(coord[i].first - coord[j].first) + abs(coord[i].second- coord[j].second);

            graph[i][j] = wt;
            graph[j][i] = wt;
        }
    }

    vector<vector<int>> dp(1<<n, vector<int> (n, -1));
    int initial_mask = 1;
    int visited_all_mask = (1<<n)-1;
    
    int ans = findCost(initial_mask, visited_all_mask, 0,  dp);
    
    return ans;
}


int main() {
    
    for(int test=1; test<=10; test++){
        cout<<"# "<<test<<" ";
        int ans = solve();
        cout<<ans<<"\n";
    }
    return 0;
}