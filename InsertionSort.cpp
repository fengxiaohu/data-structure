#include <iostream>
#include <vector>
using namespace std;
void SelectSort(int array[],int size)
{
    
    int temp;
    for(int i=0;i<size;++i)
    {
        for(int j=i+1;j>0;--j)
        {
            if(array[j-1]>array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
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
     SelectSort(test_array);
     for(int k=0;k<sizeof(test_array)/sizeof(int);++k)
     {
         cout<<test_array[k]<<' ';
         
     }
     return 0;
}
