class Solution {
public:
    int jump(vector<int>& nums) {
        // GREEDY APPROACH: the best index to jump to maximises reach
        //                  only jump once all possible destinations have been evaluated

        // Extra: the max <= nums.size()-1

        int n = nums.size();

        int max_reach = 0;
        int last_reach = 0;
        int ans = 0;

        for (int i=0; i<(n-1); i++) {
            // track local maximum reach from feasible next jumps
            // maximum reach is upper bounded by n-1
            int tmp = min((i + nums[i]), (n-1));
            max_reach = max(max_reach, tmp);

            // after checking all feasible next jumps,
            // pick best jump greedily
            if (last_reach == i) {
                last_reach = max_reach;
                ans++;
            }
        }

        return ans;
    }
};
