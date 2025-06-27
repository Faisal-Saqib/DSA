struct SegmentTree
{
	ll sum=0;
	int s,e;
	SegmentTree* next[2];
	SegmentTree(int l,int r)
	{
		s=l;
		e=r;
		if(s!=e)
		{
			int mid=(s+e)/2;
			next[0]=new SegmentTree(s,mid);
			next[1]=new SegmentTree(mid+1,e);
		}
	}
	void Update(int l,ll val)
	{
		if(e<l or l<s)
			return;
		sum+=val;
		if(s==e)
			return;
		next[0]->Update(l,val);
		next[1]->Update(l,val);
	}
	ll get(int l,int r)
	{
		if(e<l or r<s)
		{
			return 0;
		}
		if(l<=s and e<=r)
		{
			return sum;
		}
		return next[0]->get(l,r)+next[1]->get(l,r);
	}
};