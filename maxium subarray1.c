#include<stdio.h>
#include<limits.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int maxium=-10000;
    int sum;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            sum=0;//reset the sum when loop is over
            for(int k=i;k<=j;k++)
            {
                sum=sum+nums[k];   
            }
            if(sum>maxium)
            {
                maxium=sum;
            }
        }
    }
    return maxium; 
        
    }
};
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int maxium=-65535;
    int sum;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        sum=0;
        if(nums[i]>(2^31-1)||nums[i]<(-2^31))
            return nums[i];
        for(int j=i;j<n;j++)
        {
            sum=sum+nums[j];   
            if(sum>maxium)
            {
                maxium=sum;
            }
        }
    }
    return maxium; 
        
    }
};
class Solution{//divide and conquer
public:

    int max(int a, int b)
    {
        return (a>b) ? a : b;
    }
    int max(int a, int b, int c)
    {
        return (max(a, b)>c) ? max(a, b): c;
    }
    int maxCrossingSum(int *array, int l, int m, int h)
    {
        int sum = 0;
        int left_sum = INT_MIN;
        for (int i = m; i>=l; i--)
        {
            sum += array[i];
            if (sum>left_sum)
            {
                left_sum = sum;
            }
        }
        sum = 0;
        int right_sum = INT_MIN;
        for (int j = m + 1; j<=h; j++)
        {
            sum += array[j];
            if (sum>right_sum)
            {
                right_sum = sum;
            }
        }
        return left_sum + right_sum;

    }
    int maxSubarray(int *array, int l, int h)
    {
        if (l == h)
        {
            return array[h];
        }
            int m = (l + h) / 2;
            return maxSubarray(array, l, m),
                maxSubarray(array, m + 1, h),
                maxCrossingSum(array, l, m, h);
        
    }
    void printArray(int *array,int size)
    {
        for (int i = 0; i<size; i++)
        {
            printf("%d", array[i]);
            printf("\n");
        }
    }

class Solution{//dynamic programming
public:

    int max(int a, int b)
    {
        return (a>b) ? a : b;
    }
    
    int maxSubarray(int *A, int n)
    {
        int nstart = A[n - 1];
        int nall = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            nstart = max(A[i], nstart + A[i]);
            nall = max(nstart, nall);
            
        }
        return nall;
    }
    void printArray(int *array,int size)
    {
        for (int i = 0; i<size; i++)
        {
            printf("%d", array[i]);
            printf("\n");
        }
    }

class Solution{//dynamic programming
public:

    int max(int a, int b)
    {
        return (a>b) ? a : b;
    }
    
    int maxSubarray(int *A, int n)
    {
        int *start = new int[n];
        int *all = new int[n];
        

        start[n - 1] = A[n - 1];
        all[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            //start[i] = max(A[i] + start[i + 1], A[i]);
            start[i] = (start[i + 1] > 0) ? A[i] + start[i + 1] : A[i];
            //all[i] = max(start[i], all[i + 1]);
            all[i] = (start[i] > all[i + 1]) ? start[i] : all[i + 1];
            debug_array[i] = start[i];
        }
        
        return all[0];
        void printArray(int *array,int size)
        {
            for (int i = 0; i<size; i++)
            {
                printf("%d", array[i]);
                printf("\n");
            }
    }


int main()
{
    int array[]={1,-2,3,5,-3,2};
    int size=sizeof(array)/sizeof(array[0]);
    printArray(array,size);
    int result=maxSubarray(array,0,size-1);
    print("maxium subarray is %d",result);

}
