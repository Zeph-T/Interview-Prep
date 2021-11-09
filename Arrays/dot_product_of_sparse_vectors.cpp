class SparseVector {
public:
    unordered_map<int,int>map;
    SparseVector(vector<int> &nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                map[i] = nums[i];
            }
        }        
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans =0;
        for(auto x: map){
            if(vec.map.find(x.first) != vec.map.end()){
                ans += vec.map[x.first] * x.second;
            }
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);