constexpr int N=1e5;
int Rt[N], Rk[N];
struct UnionFind{
    int comp;
    UnionFind(int n): comp(n){
        iota(Rt, Rt+n, 0);
        memset(Rk, 0, n*sizeof(int));
    }
    int Find(int x){
        return (x==Rt[x])? x : Rt[x]=Find(Rt[x]);
    }
    bool Union(int x, int y){
        x=Find(x), y=Find(y);
        if (x==y) return 0;
        if (Rk[x]>Rk[y]) swap(x, y);
        Rt[x]=y;
        Rk[y]+=(Rk[x]==Rk[y]);
        comp--;
        return 1;
    }

};
uint64_t A[N];
class Solution {
public:
    static inline int digitSum(int x){
        int sum=0;
        for(; x>0; x/=10){
            sum+=x%10;
        }
        return sum;
    }
    static inline uint64_t pack ( int ds , int x , int i ) {
        return ((uint64_t)ds<<47ULL)+((uint64_t)x<<17ULL)+i ;
    }
    static int minSwaps(vector<int>& nums) {
        const int n=nums.size(), mask=(1<<17)-1;
        for (int i=0; i<n; i++){
            int x=nums[i];
            A[i]=pack(digitSum(x), x, i);
        }
        sort(A, A+n);
        UnionFind G(n);
        for(int i=0; i<n; i++){
            int j=A[i] & mask;
            G.Union(i, j);
        }
        return n-G.comp;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();