/*selection sort algorithm:
    running time has no correlation with input arrays
    element in array exchange least times
*/

#include <iostream>
using namespace std;
void SelectSort(int array[],int length)
{
    int j;
    int size;
    int index;
    int temp;
    
    for(j=0;j<length;j++)
    {   
        for(index=j+1;index<length;index++)
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
    int test_array[]={10,9,8,7,6};
    int length=sizeof(test_array)/sizeof(test_array[0]);
    for(int j=0;j<length;++j)
    {
        cout<<test_array[j]<<' ';
        cout<<endl;
    }
     SelectSort(test_array,length);
     for(int k=0;k<length;++k)
     {
         cout<<test_array[k]<<' ';
         
     }
     return 0;
}