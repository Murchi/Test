#include <iostream>

using namespace std;

void merg(int *arr,int start,int mid,int e)
{
    cout<<"inside merge"<<endl;
    int temp[e-start+1];
    int i=start,j=mid+1,k=0;

    while(i<=mid && j<=e)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i=i+1;
            k=k+1;
        }

        else
        {
            temp[k]=arr[j];
            j=j+1;
            k=k+1;

        }
    }


    while(i<=mid)
    {
        temp[k]=arr[i];
        k=k+1;
        i=i+1;
    }

    while(j<=e)
    {
        temp[k]=arr[j];
        k=k+1;
        j=j+1;
    }

    for(int i=start;i<=e;i++)
    {
        arr[i]=temp[i-start];
    }
}

void printArray(int *arr,int s)
{

    for(int i=0;i<s;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void mergeSort(int *arr,int l,int r)
{
    cout<<"Inside MergeSort"<<endl;
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merg(arr,l,mid,r);
    }
}

int main()
{
    int arr[]={5,6,9,1,2};
    int s=sizeof(arr)/sizeof(arr[0]);
    int start=0,e=s-1;
    mergeSort(arr,0,e);
    printArray(arr,s);
    return 0;
}
