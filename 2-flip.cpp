#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include <bits/stdc++.h>
using namespace std;


int main() {
    unordered_map<string,int> freq;
    int n,m,k;
    int ans = INT_MIN;
    
    cin>>n>>m>>k;
    
    for(int i=0; i<n; i++)
    {
        string tmp="";
        int zeroes = 0;
        
        for(int j=0; j<m; j++)
        {
            int x;
            cin>>x;
            
            if(x==0) zeroes++;
            
            tmp+='0'+x;
        }
        if(zeroes<=k && (k-zeroes)%2 == 0)
        {
            freq[tmp]++;
        }
        
    }
    
    for(auto x: freq)
    {
        if(x.second>ans)
        {
            ans = x.second;
        }
    }
    
    cout<< ans<<endl;
}
