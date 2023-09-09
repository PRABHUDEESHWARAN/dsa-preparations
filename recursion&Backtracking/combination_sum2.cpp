#include<bits/stdc++.h>
using namespace std;
/*
Combination Sum 2: Here we are given an array and a target and we are supposed to return all the possible subset/subsequences
satisfying the given conditions.
    -> An element at a particular index can be taken only once.
    -> The order of the subset must be in the ascending order like [1 1 2],[1 2 1],[2 1 3].
    -> There must be no duplicate subsets.
Intuition:
    -> Mostly for all kinds of subsets/subsequences problems we use the take/not take approach in recursion.
    -> but here we need to meet several edge cases.
    -> but describing the edge cases let us first see the flow of the code.

    Flow of the code:
        -> consider the size is n and we start from 0 th index.
        -> At 0 th index we have the ability to take (0 index means we checking which value can be our first element)
                            -> 0th index "value" as the 1st element .
                            -> 1 st index value as the 1st element.
                            -> 2nd index value as the 1st element and so on till nth index value.
        -> once we have chosen a index value for the current position then we recursion for the next index (i+1);
        -> so if we are in need for a particular position we check which index element can take up that position by checking for
        all index values and calling recursion from there by incrementing index and decrementing target value by arr[i].
        ->so if an index value is decided to be taken then we add that value to our current answer data structure (ds) and call recursion.
        ->Now we have picked and call recursion, now we need to remove the taken element from our data structure so that next index element
        in the for loop can be taken and sent for recusion.
    Base conditions:
        -> we can get a subset that meets the target sum at any point in the recursion therefore we do not include
            if(i==n) case here instead we only use 
                    -> if(target==0) ans.push_back(ds);
                    return;
    Edge cases:
        -> since we do not need duplicates we do not pick an index value thats already picked by previous index within the for loop 
        during loop iteration, therefore we take a index value of if its not equal to the previous index value.
            -> just checking equality with previous index is enough because, array has been sorted.
        -> if the current index is a new begining then we must take it even if its i-1 index value is same as them, sp.
                -> if(i>idx && arr[i]==arr[i-1])continue;
*/
void find(int idx,int n,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds,int target)
{
		if(target==0)
		{
		ans.push_back(ds);
		return;	
		}
	for(int i=idx;i<n;i++)
	{
		if(arr[i]>target)
		{
			break;
		}
		if(i>idx && arr[i]==arr[i-1])continue;

		ds.push_back(arr[i]);
		find(i+1,n,arr,ans,ds,target-arr[i]);
		ds.pop_back();
	}
	

}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	vector<int> ds;
	find(0,n,arr,ans,ds,target);
	return ans;
}
int main() {
  vector<int> v{10,1,2,7,6,1,5};
  vector < vector < int >> comb = combinationSum2(v, 7,8);
  cout << "[ ";
  for (int i = 0; i < comb.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < comb[i].size(); j++) {
      cout << comb[i][j] << " ";
    }
    cout << "]";
  }
  cout << " ]";
}
