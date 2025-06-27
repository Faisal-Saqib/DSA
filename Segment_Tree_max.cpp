struct SegmentTree
{
	ll mx=0;
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
			mx+=val;
			return;
		}
		next[0]->Update(l,val);
		next[1]->Update(l,val);
		mx=max(next[0]->mx,next[1]->mx);
	}
	void Set(int l,ll val)
	{
		if(e<l or l<s)
			return;
		if(s==e)
		{
			mx=val;
			return;
		}
		next[0]->Update(l,val);
		next[1]->Update(l,val);
		mx=max(next[0]->mx,next[1]->mx);
	}
	void Build(vll&a)
	{
		if(s==e)
		{
			mx=a[s];
			return;
		}
		next[0]->Build(a);
		next[1]->Build(a);
		mx=max(next[0]->mx,next[1]->mx);		
	}
	ll get(int l,int r)
	{
		if(e<l or r<s)
		{
			return 0; // Change to -inf if needed
		}
		if(l<=s and e<=r)
		{
			return mx;
		}
		return max(next[0]->get(l,r),next[1]->get(l,r));
	}
};