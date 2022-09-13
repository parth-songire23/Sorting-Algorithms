//
//  main.cpp
//  Sorting_Prob
//
//  Created by Parth Sunil Songire on 17/08/22.
//

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start,end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = (end-start);
        
        float us = duration.count()*1000000.0f;
        cout<<"time taken is "<< us <<"us "<<endl;
    }
};

void swap(int* a, int* b)
{
    int temp=0;
    temp = *a;
    *a = *b;
    *b = temp;
}

void MergeSort(int A[],int l, int mid, int h)
{
    int i,j,k;
    int B[h+1];
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
    Timer timer;
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

void BubbelSort(int A[],int n)
{
    Timer timer;
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
    Timer timer;
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

int partition(int A[],int l,int h)
{
    int pivot = A[l];
    int i=l,j=h;
    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
    
        if(i<j)swap(&A[i],&A[j]);
    }while(i<j);
    
    swap(&A[l],&A[j]);
    return j;
}

void Quicksort(int A[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(A, l, h);
        Quicksort(A, l, j);
        Quicksort(A, j+1, h);
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
    
//    int A[8]={1,2,34,46,3,7,8,10};
//    int n=8;
//    InsertionSort(A, n);
//    MergeSort(A,0,3,7);
    
//    int k,n;

//
//    IMergeSort(A, n);
//    for(k=0;k<n;k++)
//    {
//        cout<<A[k]<<" \n";
//    }
    int k,n;
    cin>>n;
    int A[n];
    int B[n];
    for(k=0;k<n;k++)
    {
        A[k]=rand();
        B[k]=rand();
    }
    
    cout<<"For Merge Sort ";
    IMergeSort(A, n);
    
    // 10000    3184.71us
    // 20000    6130.46us
    // 30000    9387.5us
    // 50000    16751.1us
    // 100000   31468.4us
    // 500000   100999us
    // 1000000  163680us
    
    cout<<"For Insertion Sort ";
    InsertionSort(B, n);
    
    // 10000    67754.3us
    // 20000    168733us
    // 30000    341110us
    // 40000    569780us
    // 50000    887548us
    // 100000
    // 500000
    // 1000000

    return 0;
    
    
}

