#define ll long long
class Solution {
public:
    
    bool valid(vector<ll>& nums){
        if(nums.size() < 3) return false;
        for(ll i=2;i<nums.size();i++)
            if(nums[i] != nums[i-1] + nums[i-2])
                return false;
        
        return true;
    }
    
    bool validNum(string num){
        return (num[0] != '0' || num.size() == 1) && num.size()<= 12;
    }
    
    ll toll(string num){
        ll n =0;
        ll i=0;
        while(i<num.size()){
            n*=10;
            n += (num[i++] - '0');
        }
        return n;
    }
    
    bool util(ll idx,vector<ll>& nums,string& num){
        if(idx>=num.size()){
            if(valid(nums))
                return true;
            return false;
        }
        
        string temp;
        
        for(ll i=idx;i<num.size();i++){
            temp += num[i];
            if(validNum(temp)){
                nums.push_back(toll(temp));
                if(util(i+1,nums,num))
                    return true;
                nums.pop_back();
            }
        }
        
        return false;
    }
    bool isAdditiveNumber(string num) {
        vector<ll> nums;
        return util(0,nums,num);
    }
};