class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            vector<int> base(2 , -1);
            return base;
        }
        if(nums.size() == 1 && nums[0] == target){
            vector<int> base(2 , 0);
            return base;
        }
        int low = 0;
        vector<int> ans;
        int high = nums.size() - 1;
        while(low <= high){
            int mid = (high + low) / 2;
            cout << low << " " << high << endl;
            if(nums[mid] == target){
                cout << "mid " << mid << endl;
                low = mid ;
                high = mid ;
                while(low > 0 && nums[low - 1] == nums[mid]){
                    low--;
                    cout<< low << endl;
                }
                while(high < nums.size() - 1 && nums[high + 1] == nums[mid]){
                    high++;
                    cout<< high << endl;
                }
                cout << low << " " << high << " in " <<endl;
                ans.push_back(low);
                ans.push_back(high);
                return ans;
            }
            else if (nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        vector<int> base(2 , -1);
        return base;
    }
};