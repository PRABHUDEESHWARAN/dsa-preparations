#include<bits/stdc++.h>
using namespace std;
/*
Insert a given val at approriate pos: given a sorted array we need to insert the given element in the approriate pos in the
array so that after inserting the array will still be sorted.


we can use lowerbound to do this becoz...
        -> if the given element is 2, arr is [1,3,4,5,6] the lower bound will return index of element 3 in arr.
        -> if the given elemt is 2 , arr is [1,2,3,4,5,6] the lower bound will return index of element 2 in arr.
        therefore after insertion our arr will be 
                    -> [1,2,3,4,5,6] for first case.
                    -> [1,2,2,3,4,5,6] for second case.

*/
\
int searchInsert(vector<int> arr,int x)
{
    int low=0;
    int high=arr.size()-1;
    int ans=arr.size();
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=x)
        {
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}