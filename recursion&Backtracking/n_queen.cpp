#include<bits/stdc++.h>
using namespace std;
/*
N Queen problem: given a size N, we need to return the number of ways the N queen can be placed in a NxN matrix chess board,
satisfying the following conditions.
    -> each row  must contain only one queen.
    -> each col  must contain only one queen.
    ->No queen must be in a position to attack any other queen.

Here we can use the recursion and back tracking approach to solve this problem.
->


*/
class Solution
{
    public:
        void solve(int col,vector<string> &board,vector<vector<string>> &ans,int leftside[],int upperdiagonal[],int lowerdiagonal[],int n)
        {
            if(col==n)
            {
                ans.push_back(board);
                return;
            }
            for(int i=0;i<n;i++)// for all row of the curr col check if queen can be placed, if safe call recursion from there to find
            //solution through that path if exists.
            {
                int row=i;
                if(leftside[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[n-1+col-row]==0)
                {
                    board[row][col]='Q';
                    leftside[row]=1;
                    lowerdiagonal[row+col]=1;
                    upperdiagonal[n-1+col-row]=1;
                    solve(col+1,board,ans,leftside,upperdiagonal,lowerdiagonal,n);
                    board[row][col]='.';
                    leftside[row]=0;
                    lowerdiagonal[row+col]=0;
                    upperdiagonal[n-1+col-row]=0;
                }

            }




        }


        vector < vector < string >> solveNQueens(int n)
        {
            vector < vector < string >> ans;
            vector<string> board(n);
            string s(n,'.');
            for(int i=0;i<n;i++)
            {
                board[i]=s;
            }// filling up the board with initial string values '.' like ['.','.','.','.']
            //lets init hash arrays for checking is safe to place.
            int leftside[n]={0},upperdiagonal[2*n-1]={0},lowerdiagonal[2*n-1]={0};
            solve(0,board,ans,leftside,upperdiagonal,lowerdiagonal,n);
            return ans;
        } 
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}