class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int ones_total = count(s.begin(), s.end(), '1');
        
        vector<pair<int, int>> zero_runs;
        int i = 0;
        while (i < n) {
            if (s[i] == '0') {
                int start = i;
                while (i < n && s[i] == '0') {
                    i++;
                }
                zero_runs.push_back({start, i - 1});
            } else {
                i++;
            }
        }
        
        vector<tuple<int, int, int, int, int>> pairs;
        for (size_t k = 0; k + 1 < zero_runs.size(); ++k) {
            auto [L1, R1] = zero_runs[k];
            auto [L2, R2] = zero_runs[k+1];
            pairs.push_back({L1, R1, L2, R2, (R1 - L1 + 1) + (R2 - L2 + 1)});
        }
        
        int num_pairs = pairs.size();
        if (num_pairs == 0) {
            return vector<int>(queries.size(), ones_total);
        }
        
        int K = bit_width((unsigned int)num_pairs);
        vector<vector<int>> st(num_pairs, vector<int>(K, 0));
        for (int j = 0; j < num_pairs; ++j) {
            st[j][0] = get<4>(pairs[j]);
        }
        
        for (int j = 1; j < K; ++j) {
            for (int idx = 0; idx <= num_pairs - (1 << j); ++idx) {
                st[idx][j] = max(st[idx][j-1], st[idx + (1 << (j-1))][j-1]);
            }
        }
        
        auto query_st = [&](int L, int R) {
            if (L > R) return 0;
            int j = bit_width((unsigned int)(R - L + 1)) - 1;
            return max(st[L][j], st[R - (1 << j) + 1][j]);
        };
        
        vector<int> R1_list, L2_list;
        for (auto& p : pairs) {
            R1_list.push_back(get<1>(p));
            L2_list.push_back(get<2>(p));
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            int first_k = lower_bound(R1_list.begin(), R1_list.end(), l) - R1_list.begin();
            int last_k = upper_bound(L2_list.begin(), L2_list.end(), r) - L2_list.begin() - 1;
            
            if (first_k > last_k) {
                ans.push_back(ones_total);
                continue;
            }
            
            int best_gain = 0;
            if (first_k == last_k) {
                auto [L1, R1, L2, R2, _] = pairs[first_k];
                int gain = (R1 - max(L1, l) + 1) + (min(R2, r) - L2 + 1);
                best_gain = max(best_gain, gain);
            } else {
                auto [L1, R1, L2, R2, _] = pairs[first_k];
                int gain1 = (R1 - max(L1, l) + 1) + (min(R2, r) - L2 + 1);
                best_gain = max(best_gain, gain1);
                
                auto [L1_l, R1_l, L2_l, R2_l, _] = pairs[last_k];
                int gain2 = (R1_l - max(L1_l, l) + 1) + (min(R2_l, r) - L2_l + 1);
                best_gain = max(best_gain, gain2);
                
                if (first_k + 1 <= last_k - 1) {
                    best_gain = max(best_gain, query_st(first_k + 1, last_k - 1));
                }
            }
            ans.push_back(ones_total + best_gain);
        }
        return ans;
    }
};