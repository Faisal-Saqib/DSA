struct SegmentTree
{
	ll mi=1e9;
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
	void Add(int l,ll val)
	{
		if(e<l or l<s)
			return;
		if(s==e)
		{
			mi+=val;
			return;
		}
		next[0]->Update(l,val);
		next[1]->Update(l,val);
		mi=min(next[0]->mi,next[1]->mi);
	}
	void Set(int l,ll val)
	{
		if(e<l or l<s)
			return;
		if(s==e)
		{
			mi=val;
			return;
		}
		next[0]->Update(l,val);
		next[1]->Update(l,val);
		mi=min(next[0]->mi,next[1]->mi);
	}
	void Build(vll&a)
	{
		if(s==e)
		{
			mi=a[s];
			return;
		}
		next[0]->Build(a);
		next[1]->Build(a);
		mi=min(next[0]->mi,next[1]->mi);		
	}
	ll get(int l,int r)
	{
		if(e<l or r<s)
		{
			return 1e9; // Change to inf if needed
		}
		if(l<=s and e<=r)
		{
			return mi;
		}
		return min(next[0]->get(l,r),next[1]->get(l,r));
	}
};