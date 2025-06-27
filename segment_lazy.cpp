struct SegmentTree
{
    ll mi=100;
    int s,e;
    SegmentTree* next[2];
    SegmentTree(int l,int r)
    {
        mi=l;
        s=l;
        e=r;
        if(s!=e)
        {
            int mid=(s+e)/2;
            next[0]=new SegmentTree(s,mid);
            next[1]=new SegmentTree(mid+1,e);
        }
    }
    
};