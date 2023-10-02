#include<bits/stdc++.h>
using namespace std;
/*
Longest Palindromic substring: given a string we need to tell the maximum length of the palindromic substring
from the given string.
for eg: abaaba - for this the longest palindromic substring length is 6.
Intuition:
    -> here we are using a matrix to represent the string becoz by doing so we can apply dynamic programming.
    -> Let us imagine we have two pointers i and j at 0th index respectively, now if we keep moving these pointers
    such that i is always less than j becoz to form a valid string i<j only makes sense.
    -> by moving these two pointers we will get the substrings of the given string
            -> 0,0 1,1 2,2 3,3 4,4 ...  => diff =0
            -> 0,1 1,2 2,3 3,4 .....    => diff =1
            -> 0,2 1,3 2,4 3,4....      => diff =2 and continues so on.
    -> we are going diagonal wise... from the left diagonal, we dont start from the lower traingle diagonal becoz they have i>j that
    does not form a valid substring.

    -> Now, we have 3 conditional statement to take care of,
            -> if length of substr is 1 then it is obviously palindrome. so there dp[i][j]=1.
            -> if length of substr is 2 then if both character are equal they are palin , so dp[i][j]=2
            -> else if len of substr >2 then we check if first & last character are equal and 
                    -> if substr from i+1 to j-1 is a palindrome. (dp[i+1][j-1]==1 ? )
    after forming every substr and checking them for palindrome we update the maxlen that's it.


*/



#include <bits/stdc++.h>
 
using namespace std;

int main(int argc, char** argv)
{
string s;
cin>>s;
int n=s.length();
//dp vector
vector<vector<int>> dp(n,vector<int>(n,0));
int maxLen=0;
string ans="";
//we will traverse the diagonal from the middle one
for(int diff=0;diff<n;diff++)
{
    for(int i=0,j=i+diff;i<n,j<n;i++,j++)
    {
        if(i==j)
        {
            dp[i][j]=1;
        }
        else if(i==j-1 && s[i]==s[j])
        {
            dp[i][j]=2;
        }
        else
        {
            if(dp[i+1][j-1] && s[i]==s[j])
            {
                dp[i][j]=dp[i+1][j-1]+2;
            }
        }
        
        if(dp[i][j]>maxLen)
        {
            maxLen=dp[i][j];
            ans=s.substr(i,j-i+1);
        }
    }
}
cout<<maxLen;

}