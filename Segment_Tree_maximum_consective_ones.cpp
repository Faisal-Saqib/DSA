struct Data
{
    ll ans=0;
    ll mxpre=0;
    ll mxsuf=0;
    ll len=0;
};
Data idendity;
Data merge(Data l,Data r)
{
    return Data{max({l.ans,r.ans,l.mxsuf+r.mxpre}),l.mxpre+r.mxpre*(l.mxpre==l.len),r.mxsuf+l.mxsuf*(r.len==r.mxsuf),l.len+r.len};
}
Data SetValue(ll& x)
{
    return Data{x,x,x,1};
}
struct SegmentTree
{
    Data val;
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
    void pull()
    {        
        val=merge(next[0]->val,next[1]->val);
    }
    void Build(vl& a)
    {
        if(s==e)
        {
            val=SetValue(a[s]);
            return;
        }
        next[0]->Build(a);
        next[1]->Build(a);
        pull();
    }
    void Update(int l,ll val)
    {
        if(e<l or l<s)
            return;
        if(s==e)
        {
            // val.sum+=val;
            // val.mi+=val;
            return;
        }
        next[0]->Update(l,val);
        next[1]->Update(l,val);
        pull();
    }
    void Set(int l,ll val1)
    {
        if(e<l or l<s)
            return;
        if(s==e)
        {
            val=SetValue(val1);
            return;
        }
        next[0]->Set(l,val1);
        next[1]->Set(l,val1);
        pull();
    }
    Data get(int l,int r)
    {
        if(e<l or r<s)
            return idendity;
        if(l<=s and e<=r)
            return val;
        return merge(next[0]->get(l,r),next[1]->get(l,r));
    }
};