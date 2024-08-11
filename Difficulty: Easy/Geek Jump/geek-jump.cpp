//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int> &dp, vector<int> &arr, int n){
        if(n == 0) return 0;
        if(dp[n]!=-1) return dp[n];
        
        int left = solve(dp,arr,n-1) + abs(arr[n]-arr[n-1]);
        int right = INT_MAX;
        if(n>1) {
            right = solve(dp,arr,n-2) + abs(arr[n]-arr[n-2]);
        }
        
        return dp[n] = min(left,right);
    }
    int minimumEnergy(vector<int>& arr, int n) {
        vector<int> dp(n+1, -1);
        return solve(dp,arr,n-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends