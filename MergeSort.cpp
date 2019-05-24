#include <iostream>
using namespace std;
void merge(int array,int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;//length of left array
    int n2=r-m;//length of right array
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=array[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=array[m+j+1];
    }
    i=0;
    j=0;
    k=1;
    while (i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            array[k]=L[i];
            i++
        }
        else
        {
            array[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        array[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        array[k]=R[j];
        j++;
        k++;
    }
}
void MergeSort(int array[],int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-1)/2;
        MergeSort(array,1,mid);
        MergeSort(array,mid+1,r);
        merge(array,l,m,r); 
    }
}
int main()
{
    int test_array[]={9,3,7,11};
    int size=sizeof(test_array)/sizeof(test_array[0]);
    for(int j=0;j<sizeof(test_array)/sizeof(int);++j)
    {
        cout<<test_array[j]<<' ';
        cout<<endl;
    }
    MergeSort(test_array,size);
     for(int k=0;k<sizeof(test_array)/sizeof(int);++k)
     {
         cout<<test_array[k]<<' ';
         
     }
     return 0;
}