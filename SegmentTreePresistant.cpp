struct SegmentTreeP
{// For range sum and Range update
  int sum = 0,lazy=0;
  int st,en;
  SegmentTreeP *next[2];
  int get(int l,int r)
  {
    if(r<st or en<l)
      return 0;
    int tp=min(r,e)-max(l,s)+1;
    if(l<=st and en<=r)
      return sum+(tp*lazy);
    return next[0]->get(l,r) + next[1]->get(l,r) + tp*(lazy);
  }
};
SegmentTreeP* Update(int l,int r,int value, SegmentTreeP* prev,int s=1,int e=n)
{
  SegmentTreeP* NEW=new SegmentTreeP;
  NEW->sum = prev->sum;
  NEW->lazy = prev->lazy;
  NEW->st=s;
  NEW->en=e;
  int tp=min(r,e)-max(l,s)+1;
  if(tp>0)
    NEW->sum+=value*(tp);// add intersection
  if(l<=s and e<=r)
  {
    NEW->lazy+=(value);
   return NEW;
  }
  int mid = (s + e) / 2;
  bool p = (l <= mid);
  NEW->next[p] = prev->next[p];
  if(p)
    NEW->next[!p] = Update(s,mid,l,value,prev->next[!p]);
  else
    NEW->next[!p] = Update(mid+1,e,l,value,prev->next[!p]);
}