/* Question : Leetcode 33. Search in Rotated Sorted Array */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int minp = 0;
        int valid = false;
        for( int i = 0 ; i < nums.size() ; ++i ){
            if( nums[i] < nums[minp] ) minp = i;
            if( nums[i] == target ) valid = true;
        }

        if( valid ){
            int cnt = minp, step = nums.size() - 1;
            while( step != 0 ){
                int ndx = cnt + step;

                if( ndx >= minp + nums.size() || nums[ndx % nums.size()] > target ) step /= 2;
                else cnt = ndx;
            }

            return cnt % nums.size();
        }else return -1;
        
        return 0;
    }
};