#include<bits/stdc++.h>
using namespace std;

/*
Pascal's Triangle: The pascals triangle revolves around the concept of  finding NcR.
    There are three possible questions that can be asked on the pascal's triangle.
        -> given row and col we need print the value in the pascal's triangle.
        ->given a row number we need to print the entire row in the pascal's triangle.
        ->given a number N we need to print the pascals triangle.


        example of a pascals triangle for n=6
                        1
                    1       1
                1       2       1
            1       3       3       1
        1       4       6       4       1
    1       5       10      10      5       1

There are several approaches for this problem, 
    -> we can use NcR for finding any particular value in the triangle so we can loop and print but it requires
    frequent func calls.
    -> for printing a particular row we use the approach of using the row value and col val and multiplying them
    see the code you will understand if you visit it once in a while.
*/

void printVal(int row,int col)
{
    int r=row-1;
    int c=col-1;
    int val=1;
    //apply formula NcR but dont use factorial.
    //if row is 5 and col is 3 the 5 dec until 3 dec to 1. like (5x4x3)/(3x2x1).
    for(int i=0;i<c;i++)
    {
        val*=r;
        val/=(i+1); // always do the multiplication first and then divide to get proper integer values.
        r--;
    }
    cout<<"the value is:"<<val;
    return;
}

vector<int>  printRow(int row)
{
    int ans=1;
    vector<int> temp;
    // print first 1.
    temp.push_back(1);
    // cout<<ans<<" ";
    // print remaining using the concept.
    for(int i=1;i<row;i++)
    {
        // multiply by row - col 
        ans*=(row-i);
        ans/=i;
        //divide by col.
        temp.push_back(ans);
        // cout<<ans<<" ";
    }
    return temp;
}

void print(int n)
{
    vector<int> answer;
    for(int i=0;i<n;i++)
    {
        vector<int> temp=printRow(i+1);
        for(int ch:temp)
        {
            answer.push_back(ch);
        }
    }

    for(int ch:answer)
    {
        cout<<ch<<" ";
    }
}
int main()
{
    //in pascal triangle for each row value there will be only row elements eg: row=2 col also 2.
    int n,row,col;
    cin>>n>>row>>col;
    //print particular value.
    printVal(row,col);
    cout<<endl;
    //print the entire row.
    vector<int> values=printRow(6);
    cout<<endl;
    //print the entire triangle linearly.
    print(n);
    return 0;
}