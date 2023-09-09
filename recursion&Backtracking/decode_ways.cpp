#include<bits/stdc++.h>
using namespace std;
/*
Decode ways: Given a integer, where a-1,b-2,....z-26. We are supposed to return the number of ways we can decode the given
integer into strings of alphabets (words.)

eg: 121 can be decoded as "aba" and "la".

Intuition: here we are using reecursion and backtracking approach to arrive at the number of ways we can decode the integer.
-> we can  take a particular index integer alone or we can take it along with its next index as they can form 2 digit number
within alphabet range.
->eg: In 121,if we are at index 1, we can take 1 and decode remaing 21 and we can take 12 and decode remaining 1.
-> but this is not always the case, there are some exceptions which is listed below.
    -> we can take current as we as current,current+1 index if the curr index is 1 or (it is 2 and curr+1 index is between 0 and 6 inclusive.)
    -> if current index is anything other than 1 and 2 we can take only that particular index as single alphabet.
    -> if curr index is 0 then we can decode 0 so that will fail.

this is also a dynamic problem, where we can store the previously decoded answers by memoization.

There are three base conditions,
    -> if curr index i :  i>=n return 1.
    -> if curr index i :  s[i]=='0' return 0;
    -> if curr index i :  i==n-1 return 1; // this is becoz if i has come to last index then it can be counted as a decodable way only
    if it is not zero, that is the reason why we put the zero condition before.
*/

int ways(int i,string s,vector<string> &ans,vector<int> &dp,string z)
{
    //base cases
    if(i>=s.length())
    {
        // dp[i]++;
        ans.push_back(z);
        return 1;
    }
    else if(s[i]=='0')
    {
        return 0;
    }
    else if(i==s.length()-1)
    {
        // dp[i]++;
        char q=96+(s[i]-'0');
        // cout<<z+q<<endl;
        ans.push_back(z+q);
        return 1;
    }
    // else if(dp[i]!=-1)
    // {
    //     return dp[i];
    // }
    else if(s[i]=='1' || (s[i]=='2' && (s[i+1]>=48 && s[i+1]<=54)))
    {
        char ch1=(96+(s[i]-'0'));
        string ch2="";
        ch2+=s[i];
        ch2+=s[i+1];
        int k=96+stoi(ch2);
        char inc=k;
        return dp[i]=ways(i+1,s,ans,dp,z+ch1)+ways(i+2,s,ans,dp,z+inc);
    }
    else{
        char ch3=(96+(s[i]-'0'));
        return dp[i]=ways(i+1,s,ans,dp,z+ch3);
    }
}
int main()
{
    string s="121";
    vector<string> ans;
    vector<int> dp(s.length(),-1);
    string z="";
    cout<<ways(0,s,ans,dp,z)<<endl; // sending starting index.
    for(string ch:ans)
    {
        cout<<ch<<endl;
    }
    return 0;
}