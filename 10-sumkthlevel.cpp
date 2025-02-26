#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int k;
    string s;
    cin>>k>>s;
    int level = -1;
    int sum = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            level++;
        }
        else if(s[i]==')')
        {
            level--;
        }
        else if(level==k)
        {
            int n=0;
            while(s[i]>='0' && s[i]<='9')
            {
                n = n*10 + s[i++] - '0';
            }
            
            sum = sum+n;
            i--;     
        }
            
    }
    
    cout<<sum<<endl;
}
