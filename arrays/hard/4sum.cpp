#include<bits/stdc++.h>
using namespace std;
/*
4 sum problem: 
    -> Here we are given an array and a target, we are supposed to find the all  possible 
    quads that sum up to the given target.
    -> we are going to follow the same principle followed in the three sum problem,
    but by keep four pointers i,j,k,l keeping i and j fixed.

*/
vector<vector<int>> fourSum(vector<int> &v,int t)
{
    int n=v.size();
    vector<vector<int>> ans;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(i!=0 && v[i]==v[i-1])
        {
            continue;
        }
        for(int j=i+1;j<n;j++)
        {  
            if(j!=i+1 && v[j]==v[j-1])
            {
                continue;
            }
            int k=j+1;
            int l=n-1;
            while(k<l)
            {
                int sum=v[i]+v[j]+v[k]+v[l];
                if(sum<t)
                {
                    k++;
                }
                else if(sum>t)
                {
                    l--;
                }
                else
                {
                    ans.push_back({v[i],v[j],v[k],v[l]});
                    k++;
                    l--;
                    //if duplicates come the check and move.
                    while(k<l && v[k]==v[k-1])
                    {
                        k++;
                    }
                    while(k<l && v[l]==v[l+1])
                    {
                        l--;
                    }
                }
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}