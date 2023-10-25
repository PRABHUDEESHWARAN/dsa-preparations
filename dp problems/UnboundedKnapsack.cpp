//{ Driver Code Starts
// Initial Template for C++
/*
Unbounded Knapsack problem: here we are given an set of values and their weight and also the weight of the bag, we need to return the
maximum sum that can be formed by filling the bag with values.
NOTE: taking the same value again is allowed as the problem states its unbounded we have infinite supply.

solution:
    -> Here we can either pick the current value or not pick the current value
    -> if we dont pick we go to the next index without adding value (0+ next_recur_call)
    -> If we pick it then we can take it until the bag holds again and again there for we will call the recursion for the same index
    again and again till the bag fits. (val[i]+next_rec_call_for_same_index).
    -> we go from n-1 index to 0 index and at zero index we have base case.
    -> if we are at the last index that is 0 index, we will definitely take as much as possible therefore
    we put a separate condition by diving the value of 0 index with the remaining capacity.

    -> at last we can improve the time complexity by doing memoization and tabulation.



*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int W,int val[],int wt[],vector<vector<int>> &dp)
    {
        //base
        if(i==0)
        {
            return (W/wt[0])*val[0];
        }
        if(dp[i][W]!=-1)
        {
            return dp[i][W];
        }
        
        //not pick
        int notPick=0+solve(i-1,W,val,wt,dp);
        int pick=0;
        //pick
        if(wt[i]<=W)
        {
            pick=val[i]+solve(i,W-wt[i],val,wt,dp);
        }
        
        return dp[i][W]=max(pick,notPick);
    }


    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return solve(n-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends