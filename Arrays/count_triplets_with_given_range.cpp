class Solution {
  public:
  
    int countTrip(int arr[],int val , int n){
        int count = 0;
        for(int k=0;k<n-2;k++){
            int i = k + 1;
            int j = n-1;
            while(i != j){
                int sum  = arr[i] + arr[j] + arr[k];
                if(sum > val)j--;
                else {
                    count += (j -i );
                    i++;
                }
            }
        }
        return count;
    }
  
    int countTriplets(int arr[], int n, int left, int right) {
        // code here
        sort(arr , arr + n);

        int l1 =  countTrip(arr,right ,n);
        int l2 =  countTrip(arr,left-1,n);
        return l1 - l2;
    }
};
