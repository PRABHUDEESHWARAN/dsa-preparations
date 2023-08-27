#include<bits/stdc++.h>
using namespace std;
/*
Merge two sorted arrays without extra space.
-> given two arrays we need to sort those two arrays without using extra space in place.
-> we can take advantange of the sorted nature of the two arrays and use a two pointer 
approach.
->keep two pointers i and j at the end of first array and the beginning of the second array
respectively.
->now check if arr[i]>arr2[j] if true then swap them and decrement the i pointer and increment 
the j pointer.
-> if at any case if arr1[i]<arr2[j] is true then we dont need to check furthermore, becoz of the 
sorted nature of the both arrays.
-> The goal is to put the greater elements in the right side array and the smaller elements in the
left side array, once we do this we will have all the small and large elements in left and right
array respectively but not necessarily in the sorted order.
-> therefore we sort the arr1 and arr2, and now we will have our answer.
*/




void merge(long long arr1[],long long arr2[],int n,int m)
{
    int i=n-1,j=0;
    while(i>=0 && j<m)
    {
        if(arr1[i]>arr2[j])
        {
            int temp=arr1[i];
            arr1[i]=arr2[j];
            arr2[j]=temp;
            i--;
            j++;
        }
        else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}