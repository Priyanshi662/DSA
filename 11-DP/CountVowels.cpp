#include <vector>
using namespace std;
class Solution
{
public:
    int countVowelPermutation(int n);
};

int Solution :: countVowelPermutation(int n)
{
    // a-> {e,i,u}
    // e-> {a,i}
    // i-> {e,o}
    // o-> {i}
    // u-> {i,o}
    vector<vector<long>> dp(n+1, vector<long>(5, 0));
    int MOD = 1e9 + 7;
    for(int i = 0; i < 5; i++)
        dp[1][i] = 1;
    for(int i = 1; i < n; i++)
    {
        dp[i+1][0] = (dp[i][1] + dp[i][2] + dp[i][4]) %MOD;
        dp[i+1][1] = (dp[i][0] + dp[i][2]) % MOD;
        
        dp[i+1][2] = (dp[i][1] + dp[i][3]) % MOD;
        
        dp[i+1][3] = dp[i][2];
        
        dp[i+1][4] = (dp[i][2] + dp[i][3]) % MOD;
    }
    
    int res = 0;
    for(int i = 0; i < 5; i++)
        res = (res + dp[n][i]) % MOD;
    return res;
}