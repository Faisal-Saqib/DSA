struct SegmentTree
{
	ll gd=0;
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
			gd+=val;
			return;
		}
		next[0]->Update(l,val);
		next[1]->Update(l,val);
		gd=__gcd(next[0]->gd,next[1]->gd);
	}
	void Set(int l,ll val)
	{
		if(e<l or l<s)
			return;
		if(s==e)
		{
			gd=val;
			return;
		}
		next[0]->Update(l,val);
		next[1]->Update(l,val);
		gd=__gcd(next[0]->gd,next[1]->gd);
	}
	void Build(vll&a)
	{
		if(s==e)
		{
			gd=a[s];
			return;
		}
		next[0]->Build(a);
		next[1]->Build(a);
		gd=__gcd(next[0]->gd,next[1]->gd);
	}
	ll get(int l,int r)
	{
		if(e<l or r<s)
		{
			return 0;
		}
		if(l<=s and e<=r)
		{
			return gd;
		}
		return __gcd(next[0]->get(l,r),next[1]->get(l,r));
	}
};