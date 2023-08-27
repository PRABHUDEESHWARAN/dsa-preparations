#include<bits/stdc++.h>
using namespace std;
/*
3 sum problem: Given an array and a target, we need to find the triplet that sum up to the
given target.

-> the brute force approach would be to use three loops to all the triplets and put them
in a set.
-> the better would be to use two loops and the third loop is replaced my hashmap.
-> The most optimal solution would be to use three pointer approach.

Three pointer approach.
    -> we have three pointers i,j,k.
    -> i is fixed and j and k are moving pointers.
    -> fix i at 0, j at i+1 and k at last index.
    -> we move move j right and k left until j<k that is j does not cross k, to maintain the
    sorted order.
    ->And also to avoid duplicates while moving j or k or i from one index to another, we
    make sure that they do not point to the same value they pointed before, this can be implemented
    by a simple if condition.
    -> when the sum of triplet equals target we put them in ans array.
    -> The fixed i pointer moves ahead once j crossed k each time and at the end we will have
    the 3 sum triplets.
*/

vector<vector<int>> triplet(int n,vector<int> &v,int t)
{
    vector<vector<int>> ans;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(i!=0 && v[i]==v[i-1])
        {
            continue;
        }
        int j=i+1,k=n-1;
        while(j<k)
        {
            int sum=v[i]+v[j]+v[k];
            if(sum==t)
            {
                ans.push_back({v[i],v[j],v[k]});
                k--;
                j++;// here if pair found we move, and even then there are dupli then for 
                //that the following while loops.

                while(j<k && v[j]==v[j-1])
                {
                    j++;
                }
                while(k>j && v[k]==v[k+1])
                {
                    k--;
                }
            }
            else if(sum<t)
            {
                j++;
            }
            else{
                k--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    int target=0;
    vector<vector<int>> ans = triplet(n, arr,target);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}