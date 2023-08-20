#include<bits/stdc++.h>
using namespace std;
/*
longest consecutive subsequence in the array:
    -> we will be given an array with random elements and we are supposed to generate the longest possible consecutive
    subsequence which is also the greatest in length of all such generated sequences.
    ex:
    Input: [3, 8, 5, 7, 6]
    Output: 4
    Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
    ->there are two optimal approaches : 
        -> use set datastructure with O(N) space comp and 2N time comp.
        -> use sorting with O(1) space comp and N+NlogN time comp.
*/

// sorting method.
void maxLen(vector<int> v,int n)
{
    int maxL=0,startIndex=0;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(v[i+1]!=v[i]+1)
        {
            maxL=max(maxL,i-startIndex+1);// find length by substracting currIndex and starting index.
            startIndex=i+1;
        }
    }
    cout<<maxL<<endl;
}

// using set datastructure.
void UsingSet(vector<int> v,int n)
{
    int maxL=0;
    unordered_set<int> s;
    for(int i:v) // put all values in set.
    {
        s.insert(i);
    }

    // we reduce time comp by checking the sequence only for those integers who have a possibility of being the
    //first element in the sequence.So, how can we determine this?.
    // If an element does v[i] does not have a previous element v[i]-1 in the set then it can be the starting of seq.
    for(int i=0;i<n;i++)
    {
        if(s.find(v[i]-1)==s.end())
        {
            int cnt=1;
            while(s.find(v[i]+1)!=s.end()) // loop till the longest.
            {
                cnt++;
                i++;
            }
            maxL=max(maxL,cnt);
        }
    }
    cout<<maxL;
}

int main()
{
    vector<int> v={3,8,5,7,6};
    maxLen(v,v.size());
    UsingSet(v,v.size());
    return 0;
}