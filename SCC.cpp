#include<bits/stdc++.h>
using namespace std;
int N;

vector<vector<int>> g,gr;
vector<bool> used;
vector<int> order,component;

void dfs1(int v)
{
    used[v] = true;
    for(auto x:g[v])
    {
        if(!used[x])
        {
            dfs1(x);
        }
    }

    order.push_back(v);
}

void dfs2(int v)
{
    used[v] = true;
    component.push_back(v);
    for(auto x:gr[v])
    {
        if(!used[x])
        dfs2(x);
    }
}

int main()
{
    int n;
    cin >> n;
    for(;;)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(a);
        gr[b].push_back(b);
    }

    used.assign(n,false);
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            dfs1(i);
        }
    }
    used.assign(n,false);
    for(int i=0;i<n;++i)
    {
        int v = order[n-1-i];
        if(!used[v])
        {
            dfs2(v);
            // access component
            component.clear();
        }
    }
}