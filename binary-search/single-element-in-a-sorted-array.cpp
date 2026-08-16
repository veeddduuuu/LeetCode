class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, left = 1, right = n - 2;

        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            if ((mid % 2 == 0 && nums[mid + 1] == nums[mid]) ||
                (mid % 2 == 1 && nums[mid - 1] == nums[mid])) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};