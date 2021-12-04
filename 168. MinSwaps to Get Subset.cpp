/*

Given an array arr of n positive integers and a number k. 
One can apply a swap operation on the array any number of times, 
i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . 
Find the minimum number of swaps required to bring all the numbers less than or equal to k together, 
i.e. make them a contiguous subarray.

*/

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
       
        int window=0;
        //count the number less than or equal to k
        for(int i=0;i<n;i++){
            if(arr[i]<=k)
            window++;
        }

        if(window==0||window==n)
        return 0;
        int countInWindow=0,swapRequired=INT_MAX;

        //intialWindow
        for(int i=0;i<window-1;i++){
            if(arr[i]<=k)
            countInWindow++;
        }

        //Move this window and count the maximum number of less than k present at any moment in this window
        for(int i=window-1;i<n;i++){
         
           if(arr[i]<=k)
           countInWindow++;

           swapRequired=min(swapRequired,window-countInWindow);

           if(arr[i-(window-1)]<=k)
           countInWindow--;

        }

        return swapRequired;
    }
};