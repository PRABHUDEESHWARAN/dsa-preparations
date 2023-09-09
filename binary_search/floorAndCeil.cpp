#include<bits/stdc++.h>
using namespace std;

/*
Floor and ceil in binary search:
    what is floor ?: the floor of a given element is the largest element in the  sorted array that is smaller than or equal to the 
    given number.
    what is ceil ?: the ceil of a given element is the smallest element in the sorted array that is greater than or equal to the
    given number.

*/
int findFloor(int arr[],int n,int x)
{
    int floor=-1;
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]<=x)
        {
            low=mid+1;
            floor=mid;
        }
        else{
            high=mid-1;
        }
    }
    return arr[floor];
}
int findCeil(int arr[],int n,int x)
{
    int ceil=-1;
    int low=0;
    int high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>=x)
        {
            high=mid-1;
            ceil=mid;
        }
        else{
            
            low=mid+1;
        }
    }
    return arr[ceil];
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	int f = findFloor(arr, n, x);
	int c = findCeil(arr, n, x);
	return make_pair(f, c);
}

int main() {
	int arr[] = {3, 4, 4, 7, 8, 10};
	int n = 6, x = 5;
	pair<int, int> ans = getFloorAndCeil(arr, n, x);
	cout << "The floor and ceil are: " << ans.first
	     << " " << ans.second << endl;
	return 0;
}