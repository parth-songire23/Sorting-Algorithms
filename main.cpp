//
//  main.cpp
//  Sorting_Prob
//
//  Created by Parth Sunil Songire on 17/08/22.
//

#include <iostream>
#include <string>
using namespace std;


void swap(int* a, int* b)
{
    int temp=0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbelSort(int A[],int n)
{
    int i,j;
    int flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

void InsertionSort(int A[], int n)
{
    int i,j,x=0;
    
    for(i=1;i<n;i++)
    {
        j=i-1;
        x=A[i];
        
        while(j>-1 && A[j]>x)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

void MergeSort(int A[],int l, int mid, int h)
{
    int i,j,k;
    int B[h++];
    i=l;j=mid+1;k=l;
    
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
    }
    
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];
    
    for(i=l;i<=h;i++)
        A[i]=B[i];
}

void IMergeSort(int A[],int n)
{
    int p,i,mid,l,h=0;
    
    for(p=2;p<=n;p=p*2)
    {
        for(i=0;i+p-1<n;i=i+p)
        {
            l=i;
            h=i+p-1;
            mid=(l+h)/2;
            MergeSort(A,l,mid,h);
        }
    }
    if(p/2<n)
        MergeSort(A,0,p/2,n-1);
}

int main()
{
//    your code goes here

//    Sorting Codechef Q: Uncle Johnny
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        int n=0;
//        cin>>n;
//        int A[n];
//        for(int i=0;i<n;i++)
//            cin>>A[i];
//        int c,index=0;
//        cin>>c;
//        int j=A[c-1];
//        BubbelSort(A, n);
//
//        for(int i=0;i<n;i++)
//        {
//            if(A[i]==j)
//                index=i+1;
//        }
//
//        cout<<index<<endl;
//    }
    
    int A[10]={1,2,46,34,6,4,8,9,5,7};
    int n=10;
//  BubbelSort(A, n);
//  InsertionSort(A, n);
    IMergeSort(A, n);
    for(int k=0;k<n;k++)
    {
        cout<<A[k]<<" ";
    }
    return 0;
}
