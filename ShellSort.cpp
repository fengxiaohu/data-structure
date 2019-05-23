#include <iostream>
#include <vector>
using namespace std;
//method 1
void ShellSort(int array[],int length)
//gap=length/2,length/4,length/8...1
{
    int i,j,gap;
    for(gap=length/2;gap>0;gap/=2)
    {
        for(i=1;i<length;i++)
        {
            int tail=array[i];
            for(j=i;j>=gap&&array[j-gap]>tail;j=j-gap)
            {
                array[j]=array[j-gap];
            }
            array[j]=tail;
        }
    }
}
//method2
void ShellSort_2(int array[],int length)
//gap=1,4,13,40...
{
    int i,j,gap,tail;
    for(gap=1;gap<length/3;gap=gap*3+1)
    {
        for(i=1;i<length;i++)
        {
            tail=array[i];
            for(j=i;j>=gap&&array[j-gap]>tail;j=j-gap)
            {
                array[j]=array[j-gap];
            }
            array[j]=tail;
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
    ShellSort(test_array,size);
     for(int k=0;k<sizeof(test_array)/sizeof(int);++k)
     {
         cout<<test_array[k]<<' ';
         
     }
     return 0;
}