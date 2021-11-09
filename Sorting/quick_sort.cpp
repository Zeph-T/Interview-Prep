class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int left, int right)
    {
        if(left < right){
            int pivot = partition(arr,left,right);
            quickSort(arr,left,pivot - 1);
            quickSort(arr,pivot+1,right);
        }
        // code here
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = low ;
        for(int j=low;j<high;j++){
            if(arr[j] < pivot){
                swap(arr[i],arr[j]);
                i++;
            }
        }
        swap(arr[i],arr[high]);
        return i;
       // Your code here
    }
};