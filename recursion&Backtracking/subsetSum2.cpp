#include<bits/stdc++.h>
using namespace std;
/*
SubsetSum 2: Print all the unique subSets.
    -> given an array of Integers which may contain duplicates we need to return all the possible 
       unique subsets and they can be in any order.

    intuition:
        -> since we dont want duplicate subsets we are following a different solution here for the optimal approach
        that doesnt use extra space than necessary.
        -> The idea is first we find all possible subsets for size 1 and then size 2 and the size three and so on.
        -> in previous problem we did not do like this rather we went on to take/not take all the index values in 
        one stretch.
        -> In this approach as we dont want duplicates if one element is taken for a particular size say for subset length 1,
        we do not take them again if they appear again in upcoming index from the current index.

        -> and also lets say we are in a situation where we are supposed to choose value for size 1.
                -> we have 1 2 1 4 5
                -> if we choose [1],[2],[4],[5] for subset length 1.
                -> so after I have checked for all possible combo by having [1], I check for [2] for this
                I have to remove 1 from [1] where []-> is my data structure so that 2 can occupy that place.
*/
class Solution
{
    public:

        void ways(int i,vector<int> &arr,vector<vector<int>> &ans,vector<int> &temp)
        {
            //base condition.
            int n=arr.size();
            ans.push_back(temp);
            
            //for i length subset size taking unique subsets
            for(int index=i;index<n;index++)
            {
                if(index!=i && arr[index]==arr[index-1])continue;
                temp.push_back(arr[index]);
                ways(index+1,arr,ans,temp);
                temp.pop_back();
            }
        }
        vector<vector<int>> subsetsWithDup(vector<int> &arr)
        {
            vector<vector<int>> ans;
            sort(arr.begin(),arr.end());
            int n=arr.size();
            vector<int> temp;
            // loop for every size of subset.
            ways(0,arr,ans,temp);

            return ans;
        }
        
};
void printAns(vector < vector < int >> & ans) {
   cout<<"The unique subsets are "<<endl;
   cout << "[ ";
   for (int i = 0; i < ans.size(); i++) {
      cout << "[ ";
      for (int j = 0; j < ans[i].size(); j++)
         cout << ans[i][j] << " ";
      cout << "]";
   }
   cout << " ]";
}
int main() {
   Solution obj;
   vector < int > nums = {1,2,2 };
   vector < vector < int >> ans = obj.subsetsWithDup(nums);
   printAns(ans);
   return 0;
}