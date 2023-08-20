#include<bits/stdc++.h>
using namespace std;
/*
Set Matrix zero:
    Given a matrix if an element in the matrix is zero then change the entire row and column to zero and 
    return the matrix.


*/
vector<vector<int>> zeroMatrix(vector<vector<int>> &m,int r,int c)
{
// inorder to reduce space comp we avoid using separate arrays for marking the zeros,so we use the first row and
//first column as marking arrays.

//to avoid column row collision we keep a separate variable for column zero.
int colzero=1;

//do the marking.
for(int i=0;i<r;i++)
{
    for(int j=0;j<c;j++)
    {
        if(m[i][j]==0)
        {
            m[i][0]=0;

            if(j!=0)
            {
                m[0][j]=0;
            }
            else
            colzero=0;


        }
    }
}
//here we are filling the zeros based on the marking array and we marking everything except the first array and 
//first column because all other elements are dependent on them.The order in which we will mark the zeros is as
//follows ->m[1][1] to m[n-1][n-1]->first row from last->first column from bottom.

//m[1][1] to m[n-1][n-1]
for(int i=1;i<r;i++)
{
    for(int j=1;j<c;j++)
    {
        if(m[i][0]==0 || m[0][j]==0)
        {
            m[i][j]=0;
        }
    }
}
//first row from last
for(int i=c-1;i>=0;i--)
{
    if(m[0][0]==0)
    {
        m[0][i]=0;
    }
}
//first column from bottom.
for(int i=r-1;i>=0;i--)
{
    if(colzero==0)
    {
        m[i][0]=0;
    }
}


return m;
}

int main()
{
    vector<vector<int>> matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    cout << "The Final matrix is: n"<<endl;
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}