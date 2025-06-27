struct Data
{
    ll sum=0;
    ll mx=-inf;
    ll lazy=0;
};
Data idendity{0,-inf,0};
Data join(Data l,Data r)
{
    return Data{l.sum+r.sum,max(l.mx,r.mx),0};
}
Data SetValue(ll& x)
{
    return Data{x,x,0};
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
    void push()
    {
        val.sum+=(e-s+1)*val.lazy;
        val.mx+=val.lazy;
        if(s!=e)
        {
            next[0]->val.lazy+=val.lazy;
            next[1]->val.lazy+=val.lazy;
        }
        val.lazy=0;
    }
    void pull()
    {        
        val=join(next[0]->val,next[1]->val);
    }
    void Build(vll& a)
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
    void Update(int l,int r,ll& v)
    {
        push();
        if(r<s or e<l)
            return;
        if(l<=s and e<=r)
        {
            val.lazy+=v;
            push();
            return;
        }
        next[0]->Update(l,r,v);
        next[1]->Update(l,r,v);
        pull();
    }
    Data get(int l,int r)
    {
        push();
        if(r<s or e<l)
            return idendity;
        if(l<=s and e<=r)
            return val;
        return join(next[0]->get(l,r),next[1]->get(l,r));
    }
};