class Solution {
public:
    void flipArray(vector<int>&arr,int k){
        int start = 0;
        int end = k;
        while(start < end){
            swap(arr[start++],arr[end--]);
        }
    }
    
    
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>res;
        int last_index = arr.size() - 1;
        int curr_max = INT_MIN;
        while(last_index >= 0){
            curr_max = INT_MIN;
            int index = -1;
            for(int i=0;i<=last_index;i++){
                if(arr[i] > curr_max){
                    curr_max = arr[i];
                    index = i;
                }
            }
            
            flipArray(arr,index);
            res.push_back(index+1);
            flipArray(arr,last_index);
            res.push_back(last_index+1);
            last_index--;
        }
        return res;
    }
};