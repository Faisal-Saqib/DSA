struct Data
{
    ll sum=0;
};
Data idendity;
Data join(Data l,Data r)
{
    return Data{l.sum+r.sum};
}
Data SetValue(ll& x)
{
    return Data{x};
}
struct SegmentTree
{
  Data val;
  int st,en;
  SegmentTree *next[2];
  void Build(int s,int e,vll& a)
  {
    if(s==e)
    {
        val=SetValue(a[s]);
        return;
    }
    int mid=(s+e)/2;
    next[0]=new SegmentTree;
    next[1]=new SegmentTree;
    next[0]->st=s;
    next[0]->en=mid;
    next[1]->st=mid+1;
    next[1]->en=e;
    next[0]->Build(s,mid,a);
    next[1]->Build(mid+1,e,a);
    val=join(next[0]->val,next[1]->val);
  }
  void Build(int s,int e,ll& a)
  {
    if(s==e)
    {
        val=SetValue(a);
        return;
    }
    int mid=(s+e)/2;
    next[0]=new SegmentTree;
    next[1]=new SegmentTree;
    next[0]->st=s;
    next[0]->en=mid;
    next[1]->st=mid+1;
    next[1]->en=e;
    next[0]->Build(s,mid,a);
    next[1]->Build(mid+1,e,a);
    val=join(next[0]->val,next[1]->val);
  }
  int get(int l,int r)
  {
    if(r<st or en<l)
      return 0;
    if(l<=st and en<=r)
      return sum;
    return next[0]->get(l,r) + next[1]->get(l,r);
  }
};

SegmentTree* Update(int l, ll& value, SegmentTree* prev,int s,int e) {
  SegmentTree* NEW = new SegmentTree;
  NEW->val = prev->val;
  NEW->st = s;
  NEW->en = e;
  if(s == e) {
   NEW->val=SetValue(val);
   return NEW;
  }
  int mid = (s + e) / 2;
  if (l <= mid) 
  {
    NEW->next[1] = prev->next[1];
    NEW->next[0] = Update(l,value,prev->next[0], s, mid);
  } 
  else
  {
    NEW->next[0] = prev->next[0];
    NEW->next[1] = Update(l,value,prev->next[1],mid+1,e);
  }
  NEW->val = join(NEW->next[0]->val, NEW->next[1]->val);
  return NEW;
}