#include<bits/stdc++.h>
using namespace std;
/*
Subset 1 problem: given an array we need ot print the sum of the all the subsets produced by it in the increasing order.

Intuition:
        -> Here we can generate all the subsets by a doing two things at each index of the array.
                -> pick the element and add it to the sum and move to next index.
                -> dont pick the element and move on to next index.
        Base condition:
            -> when we reach the last index we will add the answer to the result array.
        since we need the result in the ascending order we can sort the result and return the answer.
*/

class Solution
{
    public:
    void ways(int i,vector<int> &arr,int n,vector<int> &result,int sum)
    {
        //base condition:
        if(i==n)
        {
            result.push_back(sum);
            return;
        }
        
        //we pick the current index.
        ways(i+1,arr,n,result,sum+arr[i]);
        //we dont pick the current element.
        ways(i+1,arr,n,result,sum);

    }
    vector<int> subsetSums(vector<int> &arr,int n)
    {

        vector<int> result;
        int sum=0;
        ways(0,arr,n,result,sum);
        sort(result.begin(),result.end());

        return result;
    }
};


int main() {
  vector < int > arr{3,1,2};
  Solution ob;
  vector < int > ans = ob.subsetSums(arr, arr.size());
  sort(ans.begin(), ans.end());
  cout<<"The sum of each subset is "<<endl;
  for (auto sum: ans) {
    cout << sum << " ";
  }
  cout << endl;

  return 0;
}