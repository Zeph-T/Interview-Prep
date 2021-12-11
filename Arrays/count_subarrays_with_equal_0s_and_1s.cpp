class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        unordered_map<int,int>map;
        long long int count = 0;
        int sum = 0;
        map[0]++;
        for(int i=0;i<n;i++){
            if(arr[i] == 1)sum += 1;
            if(arr[i] == 0)sum -= 1;
            if(map[sum])count += map[sum];
            map[sum]++;
        }
        return count;
        //Your code here
    }
};
