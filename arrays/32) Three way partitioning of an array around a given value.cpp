class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // code here 
        //by using dutch national flag method
        int n=arr.size();
        int low = 0 , mid = 0 , high = n-1;
        while(mid<=high)// be care full of equal to sign
        {
            if(arr[mid]<a)
            {
                swap(arr[mid],arr[low]);
                low++;mid++;
            }
            else if(arr[mid]>=a&&arr[mid]<=b)
            {
                mid++;
            }
            else {
                swap(arr[mid],arr[high]);
            high--;
                
            }
        }
    }
};
