#include<bits/stdc++.h>
using namespace std;
/*
Merge Overlapping subarrays:
->Here we are given an array of array which denotes a series of intervals, we are supposed to merge these intervals.
->We can come up with a solution of linear traversal O(N).

-> Here the intuition is to traverse the array,
        -> if the upcoming interval is the first interval which means the first interval in the 
        array and our answer array is empty {OR} when the upcoming interval does not lie within the previous 
        interval then we must add them to our answer array as new intervals.

        -> If the upcoming interval found to be a part of the previous interval in the array...here we need
        to note that the array might contain many previous answers but we take only the previous interval to
        compare therefore we use v.back()[1] to access appropriate value.

        -> at the end of the iteration we would get the desired intervals in our answer array.

*/
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> v)
{
    vector<vector<int>> ans;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        int start=v[i][0];
        int end=v[i][1];
        if(ans.empty() || ans.back()[1]<start)
        {
            ans.push_back(v[i]);
        }
        else
        {
            ans.back()[1]=max(ans.back()[1],end);
        }
    }


    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}