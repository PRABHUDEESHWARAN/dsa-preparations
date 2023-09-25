#include<bits/stdc++.h>
using namespace std;
/*
Search in 2D matrix: given a 2d matrix and a target where all the elements in the matrix are sorted we need to tell whether
the target is present in the array or not.

INTUITION:
    -> we can do this problem if we consider the 2d matrix as a 1d array by concept of flattening without actually flattening.
    -> then we will be doing a binary search which will find our answer in O(log2(n+m)) time.

    paramter to be taken:
        low= 0 and high will be the total num of elements in array that is n*m so high=n*m-1
        from mid value we should somehow find the corresponding value denoted by mid in matrix,
            -> if mid is 5 and r=4 and c=5 then the row and col denoted by mid will be
                -> row=mid/c;
                -> col=mid%c;
        -> remaining are usual binary search things. 


*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int low=0,high=(n*m)-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target)
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        return false;
    }
};


int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution obj;
    obj.searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}