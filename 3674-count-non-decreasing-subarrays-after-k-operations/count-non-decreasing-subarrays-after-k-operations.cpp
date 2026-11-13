class Solution {
    using u32 = uint32_t;
    using u64 = uint64_t;

    static constexpr u32 N = 100005;
    inline static u32 q[N];

public:
    [[gnu::target("arch=skylake")]]
    static u64 countNonDecreasingSubarrays(vector<int>& nums, u32 k) noexcept {
        const auto a = reinterpret_cast<const u32*>(nums.data());
        u32 head = N, tail = N;
        u64 ans = 0, water = 0;
        u32 n = nums.size(), r = n;
        for (u32 l = n; l-- > 0;) {
            u32 x = a[l];
            while (head < tail && a[q[head]] <= x) {
                u32 s = q[head++];
                u32 end = head == tail ? r : q[head];
                water += u64(x - a[s]) * (end - s);
            }
            q[--head] = l;
            while (water > k) {
                water -= a[q[tail - 1]] - a[r - 1];
                tail -= (q[tail - 1] == r - 1);
                --r;
            }
            ans += r - l;
        }
        return ans;
    }
};

auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();