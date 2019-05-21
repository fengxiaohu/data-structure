'''selection sort algorithm:
    running time has no correlation with input arrays
    element in array exchange least times
'''

#include <iostream>
using namespace std;
void SelectSort(int array[])
{
    int j;
    int size;
    int index;
    int temp;
    size=sizeof(array)/sizeof(int);
    for(j=0;j<size;j++)
    {   
        for(index=j+1;index<size;index++)
        {
            if(array[j]>array[index])
            {
                temp=array[index];
                array[index]=array[j];
                array[j]=temp;
            }
        }
    }

}
int main()
{
    int test_array[]={9,3,7,11};
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