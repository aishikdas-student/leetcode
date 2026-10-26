class Solution {
public:
    int binarysearch(vector<int>& nums, int st, int end, int tar, bool findFirst) {
        int ans = -1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(nums[mid] == tar) {
                ans = mid;

                if(findFirst) { //find first means first occurence if set to true
                    end = mid - 1; // search left
                } else {
                    st = mid + 1; // search right
                }
            }
            else if(nums[mid] < tar) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int St = 0, End = nums.size() - 1;
        vector<int> ans;

        while(St <= End) {
            int Mid = St + (End - St) / 2;

            if(nums[Mid] == target) {
                int idx = Mid;

                int stidx = binarysearch(nums, St, Mid - 1, target, true);
                int endidx = binarysearch(nums, Mid + 1, End, target, false);

                if(stidx == -1) {
                    stidx = idx;
                }
                if(endidx == -1) {
                    endidx = idx;
                }

                ans.push_back(stidx);
                ans.push_back(endidx);
                return ans;
            }
            else if(nums[Mid] < target) {
                St = Mid + 1;
            }
            else {
                End = Mid - 1;
            }
        }

        return {-1, -1};
    }
};