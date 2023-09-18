#include<bits/stdc++.h>
using namespace std;
/*
Subset Sum: given an array and a sum K we need to return true if there exist a subset (not subarray) whose sum is K.


Intuition:
    -> since we are asked the subset or you can say subsequence we can use the recursion approach of
            " PICK AND NOT PICK" 
    -> so since they asked whether there exist atleast one subset that has a sum k, we can optimise the
    problem by ending the program the first time we find a solution.
    -> use appropriate return statements to do that.
*/

bool ways(int i,vector<int> &a,int n,int k,int sum)
{

    //base condition
    if(sum>k)
    {
        return false;
    }
    if(i==n)
    {
        if(sum==k)
        {
            return true;
        }

        return false;
    }

    //pick
    if(ways(i+1,a,n,k,sum+a[i])==true)
    {
        return true;
    }
    //not pick
    if(ways(i+1,a,n,k,sum)==true)
    {
        return true;
    }    

    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here

    int sum=0;
    return ways(0,a,n,k,sum);

}
int main()
{

    int n=3;
    vector<int> a={1,2,3};
    int k=3;
    bool t=isSubsetPresent(n,k,a);
    cout<<t;
    return 0;
}