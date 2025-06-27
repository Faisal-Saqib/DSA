const ll base=789,mod=1e9+7,N=300000+10;
ll pw[N];
struct SegmentTree
{
	ll s,e;
	ll revhash=0,hash=0;
	int sz=0;
	SegmentTree* next[2];
	SegmentTree(int l,int r)
	{
		s=l;
		e=r;
		sz=(e-s+1);
		if(l==r)
			return;
		int mid=(s+e)/2;
		next[0]=new SegmentTree(s,mid);
		next[1]=new SegmentTree(mid+1,e);
	}
	void Update(int x)
	{
		if(s==e)
		{
			hash=1;
			revhash=1;
			return;
		}
		next[(x>((s+e)/2))]->Update(x);
		hash=(next[0]->hash*pw[next[1]->sz]+next[1]->revhash)%mod;
		revhash=(next[1]->revhash*pw[next[0]->sz]+next[0]->revhash)%mod;
	}
	pair<ll,int> query(int l,int r)
	{
		if(e<l or r<s)
			return {0,0};
		if(l<=s and e<=r)
		{
			return {hash,sz};
		}
		auto rpt=next[1]->query(l,r);
		return ((next[0]->query(l,r).first*pw[rpt.second])+rpt.first)%mod;
	}
	pair<ll,int> revquery(int l,int r)
	{
		if(e<l or r<s)
			return {0,0};
		if(l<=s and e<=r)
		{
			return {revhash,sz};
		}
		auto rpt=next[0]->revquery(l,r);
		return ((next[1]->revquery(l,r).first*pw[rpt.second])+rpt.first)%mod;
	}
};