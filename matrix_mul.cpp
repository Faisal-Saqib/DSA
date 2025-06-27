class matrix_
{
public:
  vector<vector<ll>> ans;
  ll mod=1;
  void init(int n,int m)
  {
    ans.resize(n,vector<ll>(m));
  }
  ll multi(ll&x, ll&y)
  {
    return (x * y) % mod;
  }
  ll sum(ll&a, ll b)
  {
    return (a + b >= mod) ? a + b - mod : a + b;
  }
  vector<vector<ll>> multiply(vector<vector<ll>>&a, vector<vector<ll>>&b)
  {
    vector<vector<ll>> res(a[0].size(), vector<ll>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
      for (int j = 0; j < b[0].size(); j++)
      {
        res[i][j] = 0;
        for (int k = 0; k < a[0].size(); k++)
          res[i][j] = sum(res[i][j], multi(a[i][k], b[k][j]));
      }
    }
    return res;
  }
  vector<vector<ll>> expo(vector<vector<ll>> mat, ll m)
  {
    ans = vector<vector<ll>>(mat.size(), vector<ll>(mat[0].size()));
    for (int i = 0; i < mat.size(); i++)
      for (int j = 0; j < mat[0].size(); j++)
        ans[i][j] = (i == j);
    while (m > 0)
    {
      if (m & 1)
        ans = multiply(ans, mat);
      m = m / 2;
      mat = multiply(mat, mat);
    }
    return ans;
  }
};