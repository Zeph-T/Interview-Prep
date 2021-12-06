class Solution {
public:
    vector<string>l20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen","Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string>currency{"","Thousand","Million","Billion"};
    vector<string>tens{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty","Sixty", "Seventy", "Eighty", "Ninety"};
    
    
    
    string convert_to_words(int num){
        if(num < 20)return l20[num]; // if the number we have to decode is less than 20, we can directly use the values frm the l20 vector
        if(num < 100){ // if the number is less than 100,means we require the tens place as well as the ones place, the tens place can be acquired from tens vector and we just have to add the ones string to the end
            int tplace = num/10;
            return tens[tplace] + " "  +l20[num%10];
        }
        int tplace = (num%100)/10;
        if(num%100 >= 20){  // else, means it has reached hundred, then we have to add hundred betwwen the hundreds place and tens place
            return l20[num/100] + " Hundred " + tens[tplace] + " " + l20[num%10]; // if the number is something like 123 , here we have to add the ones place as well
        }else{
            return l20[num/100] + " Hundred " + l20[num%100]; // if the number is something like 120, here we dont have to consider the ones place
        }
        
    }
    
    
    string numberToWords(int num) {
        if(num == 0)return "Zero";
        int i =0;
        string ans = "";
        while(num > 0){
            if(num % 1000){ // club the group of three digits
                string toWords = convert_to_words(num%1000);
                ans = toWords + " " + currency[i] + " " + ans;
            }
            i++;
            num = num/1000;
        }
        ans = std::regex_replace(ans, regex("^ +| +$|( ) +"), "$1"); // stripe off the trail and leading whitespaces

        return ans;
        
    }
    
    
    
};