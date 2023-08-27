#include<bits/stdc++.h>
using namespace std;
/*
reverse Pairs: Given an array we need to return the count of the no of reverse pairs.
-> we can use merge sort algo to solve this problem same like the count inversion problem.
-> but here we need to do a have separate code for counting reverse pairs other than the
merging code itself.
*/
void merge(vector<int> &v, int start,int mid,int end)
{
    vector<int> temp;
    int i=start;
    int j=mid+1;
    int i1=start,i2=mid+1;
    while(i<=mid && j<=end)
    {
        if(v[j]<v[i])
        {
            temp.push_back(v[j]);
            j++;
        }
        else{
            temp.push_back(v[i]);
            i++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while(j<=end)
    {
        temp.push_back(v[j]);
        j++;
    }
    for(int k=start;k<=end;k++)
    {
        v[k]=temp[k-start];
    }
}
int count(vector<int> &v,int start,int mid,int end)
{
    int j=mid+1;
    int ans=0;
    for(int i=start;i<=mid;i++)
    {
        while(j<=end && v[i]>2*(v[j]))
        {
            j++;
        }
        ans+=(j-(mid+1));
    }
    return ans;
}
int mergesort(vector<int> &v,int start,int end)
{
    int ans=0;
    if(start>=end)
    {
        return ans;
    }
    int mid=(start+end)/2;
    ans+=mergesort(v,start,mid);
    ans+=mergesort(v,mid+1,end);
    ans+=count(v,start,mid,end);
    merge(v,start,mid,end);
    return ans;
}


int team(vector<int>&v,int n)
{
    return mergesort(v,0,n-1);
}
int main()
{
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: "
         << cnt << endl;
    return 0;
}