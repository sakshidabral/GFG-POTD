//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edge, int n,int M, int src){
        // code here
        vector<int> adj[n];
        for(auto it:edge){
            if(it[0]!=it[1]){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        }
        int dist=0;
        vector<int> ans(n,-1);
        queue<int> q;
        q.push(src);
        vector<int> vis(n,0);
        vis[src]=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int cur=q.front();
                q.pop();
                ans[cur]=dist;
                for(auto it:adj[cur]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends