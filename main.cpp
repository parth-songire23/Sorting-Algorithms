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
    InsertionSort(A, n);
    
    for(int k=0;k<n;k++)
    {
        cout<<A[k]<<" ";
    }
    return 0;
}
