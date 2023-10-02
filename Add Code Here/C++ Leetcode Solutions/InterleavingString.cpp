class Solution {
public:
bool checkstr(int idx1, int idx2, int idx3, string s1, string s2, string s3, vector<vector<int>>& dp)
{
	int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();
	if(idx3>=n3)
		return true;
	if(dp[idx1][idx2]!=-1)
		return dp[idx1][idx2];
	bool check1 = false;
	bool check2 = false;
	if(idx1<=n1 && s1[idx1]==s3[idx3])
	{
		check1 = checkstr(idx1+1, idx2, idx3+1, s1, s2, s3, dp);
	}
	if(idx2<=n2 && s2[idx2]==s3[idx3])
	{
		check2 = checkstr(idx1, idx2+1, idx3+1, s1, s2, s3, dp);
	}
	return dp[idx1][idx2] = check1 || check2;
}
    bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size();
	int n2 = s2.size();
	int n3 = s3.size();
	if(n3 != (n1+n2))
		return false;
	vector<vector<int>> dp(n1+1, vector<int>(n2+1,-1));
	bool ans = checkstr(0,0,0,s1,s2,s3,dp);
	return ans;
    }
};
