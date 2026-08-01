class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<long long,long long> freq,res;
        for(int& x:planks){
            freq[x]++;
            res[x]++;
        }

        for(auto [a,cnt_a]:freq){
            for(auto [b,cnt_b]:freq){
                if(a<b){
                    res[a+b]+=min(freq[a],freq[b]);
                }
                else if(a==b){
                    res[a+b]+=freq[a]/2;
                }
            }
        }

        long long maxm=0;
        for(auto& [p,f]:res){
            maxm=max(maxm,f);
        }
        return maxm;
    }
};