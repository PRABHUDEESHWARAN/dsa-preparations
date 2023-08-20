#include<bits/stdc++.h>
using namespace std;
/*
Spiral matrix: given a matrix print it in the spiral manner.


here we keep four pointers top, bottom, right,left.
-> top=0,bottom=r-1,left=0,right=c-1;

*/


//printing func.
vector<int> printSpiral(vector<vector<int>> m)
{
    int top=0,left=0,right=m[0].size()-1,bottom=m.size()-1;
    vector<int> ans;
    // we are doing the loop until top<=bottom and left<=right.
    while(top<=bottom && left<=right)
    {

        // print from left to right.
        for(int i=left;i<=right;i++)
        {
            ans.push_back(m[top][i]);
        }
        top++;

        // print from top to bottom.
        for(int i=top;i<=bottom;i++)
        {
            ans.push_back(m[i][right]);
        }
        right--;

        // there are two conditions to be checked here.
        // -> we should not print from right to left when bottom is above top.
        // -> we should not print from bottom to top when left has crossed right.
        //so include if conditions for that.
        
        // print from right to left.
        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            {
                ans.push_back(m[bottom][i]);
            }
            bottom--;
        }

        //print from bottom to top.
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                ans.push_back(m[i][left]);
            }
            left++;
        }
        
    }

    return ans;
}
int main()
{
    
  //Matrix initialization.
  vector<vector<int>> mat   {{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};
		                     
  vector<int> ans = printSpiral(mat);

  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  
  return 0;
}