class Solution {
public:
    static bool comp(int& a,int& b){
        string num1 = to_string(a);
        string num2 = to_string(b);
        return num1+num2 > num2 + num1;
    }
    
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        string res="";
        for(int num : nums)res+=to_string(num);
        if(res[0] == '0')return "0";
        return res;
    }
};