#include<bits/stdc++.h>
using namespace std;
/*
Rotate matrix 90 degrees anticlockwise direction.

we have two step to rotate the matrix by 90 degree without using extra space.
    -> transpose the matrix.
    ->reverse each row ...done.
*/
void rotate(vector<vector<int>> &m,int r,int c)
{
//transpose the matrix.
for(int i=0;i<r;i++)
{
    for(int j=0;j<i;j++)
    {
        swap(m[i][j],m[j][i]);
    }
}

//reverse rows.
for(int i=0;i<r;i++)
{
    reverse(m[i].begin(),m[i].end());
}


}


int main()
{
    vector<vector<int>> matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    int n = matrix.size();
    int m = matrix[0].size();
    rotate(matrix, n, m);

    cout << "The Final matrix is: n"<<endl;
    for (auto it : matrix) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}