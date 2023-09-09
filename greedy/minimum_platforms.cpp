#include<bits/stdc++.h>
using namespace std;
/*
Minimum platforms: given the arrival and the departure time of number of trains, we are required to find the minimum
number of platforms required for the trains to arrive and departure without overlapping.
NOTE: we cannot assign a platform to a train if the departure time of previous train is equal to the arrival time of
the upcoming train.

->We can solve this problem using greedy approach.
    -> greedy approach often involves sorting the given data,and mostly involved in assignment problems.
*/
int countPlatforms(int n,int arr[],int dep[])
{
    int cnt=1;
    int currplatforms=1;
    //sort both arrival and departure times.
    sort(arr,arr+n);
    sort(dep,dep+n);

    //we use two pointers i and j and start loop from arr[i=1] and dep[j=0] respectively.
    int i=1,j=0;


    while(i<n && j<n)
    {
        if(arr[i]>dep[j])
        {
            currplatforms--;
            j++; // here we moved j pointer as we have arrival time > dep time but we did not assign{increment the platform} plaform 
            //for the arr[i] value train..this will be taken care in upcoming iterations as next time arrival time may be greater than
            //dep time so that the currplatforms count will be incremented.
        }
        else{
            currplatforms++;
            cnt=max(cnt,currplatforms);
            i++; // after assigning platform we move i pointer.
        }
    }
    return cnt;
}

int main()
 {
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
 }