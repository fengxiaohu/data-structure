#include <iostream>
#include<stdio.h>
using namespace std;
int partion(int *array, int lo, int hi);
void exchange(int *a, int *b);

int partion(int *array, int lo, int hi)
{
	int i = lo-1;
	int j;
	int pivot = array[hi];
	for (j = lo; j <= (hi-1); j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			int temp1;
			temp1 = array[i];
			array[i] = array[j];
			array[j] = temp1;
			//exchange(array[i],array[j]);exchange ???
		}
	}
	int temp2;
	temp2 = array[i + 1];
	array[i + 1] = array[hi];
	array[hi] = temp2;
	//exchange(array[i + 1], array[hi]);
	return (i + 1);



}
void exchange(int *a, int *b)//swap two numbers in array
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}
void quickSort(int *array, int lo, int hi)
{
	if (lo < hi)
	{
		int j = partion(array, lo, hi);
		quickSort(array, lo, j - 1);
		quickSort(array, j + 1, hi);
	}
	

}

int main()
{	
	int test_array[] = {10,7,8,9,1,5};
	int size = sizeof(test_array) / sizeof(test_array[0]);
	for (int j = 0; j<sizeof(test_array) / sizeof(int); ++j)
	{
		cout << test_array[j] << ' ';
		cout << endl;
	}
	quickSort(test_array, 0, size - 1);
	
	for (int k = 0; k<sizeof(test_array) / sizeof(int); ++k)
	{
		cout << test_array[k] << ' ';

	}

	return 0;
}