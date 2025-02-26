#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 10;
vector<int> adj[N], bestCycle;
int par[N], hi = 200;
int col[N];

void dfs(int u) {
    col[u] = 1;
    for(auto v : adj[u]) {
        if(col[v] == 1) {
            int sum = 0;
            vector<int> cycle = {v};
            // cout<<"cycle pushing "<<v<<endl;
            for(int now = u; now != v; now = par[now]) {
                sum += now;
                // cout<<"cycle pushing now = "<<now<<endl;
                cycle.push_back(now);
            }
            if(sum < hi) {
                hi = sum;
                bestCycle = cycle;
            }
        }
        else {
            par[v] = u;
            dfs(v);
        }
    }
    col[u] = 2;
}


int main() {
    int n, m; cin >> n >> m;
    for(int t = 0; t < m; ++t) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; ++i) {
        if(col[i] != 2) dfs(i);
    }
    sort(bestCycle.begin(), bestCycle.end());
    for(auto x: bestCycle) {
        cout << x << ' ';
    }
    cout << '\n';

}