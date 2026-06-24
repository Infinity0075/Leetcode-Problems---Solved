class Solution {
    static constexpr int p = 1e9 + 7;
public:
    int zigZagArrays(int n, int l, int r) {
        int k = r - l + 1;
        unsigned mat[k][k];
        memset(mat, 0, sizeof(mat));
        // init mat
        for(int i = 0; i < k; ++i) {
            for(int j = 0; j < i; ++j) {
                mat[k - j - 1][i] = 1;
            }
        }
        int pow = n - 1;
        unsigned res[k];
        for(int i = 0; i < k; ++i) {
            res[i] = 1;
        }
        while(pow > 0) {
            if(pow & 1) {
                // res = res * curr;
                unsigned tmp[k];
                memset(tmp, 0, sizeof(tmp));
                for(int j = 0; j < k; ++j) {
                    for(int l = 0; l < k; ++l) {
                        tmp[j] = (tmp[j] + 1ll * res[l] * mat[l][j]) % p;
                    }
                }
                memcpy(res, tmp, sizeof(tmp));
            }
            // curr = curr * curr;
            unsigned tmp[k][k];
            memset(tmp, 0, sizeof(tmp));
            for(int i = 0; i < k; ++i) {
                for(int j = 0; j < k; ++j) {
                    for(int l = 0; l < k; ++l) {
                        tmp[i][j] = (tmp[i][j] + 1ll * mat[i][l] * mat[l][j]) % p;
                    }
                }
            }
            memcpy(mat, tmp, sizeof(tmp));
            pow >>= 1;
        }
        unsigned ret = 0;
        for(int i = 0; i < k; ++i) {
            ret = (ret + res[i]) % p;
        }
        return 2 * ret % p;
    }
};