struct FenwickTree
{
	vll fen;
	FenwickTree(ll n)
	{
		fen.resize(n+2);
	}
	void Update(ll i,ll val)
	{
		i++;
		while(i<fen.size()){
			fen[i]+=val;
			i+=(i&-i);
		}
	}
	ll get(ll l)
	{
		l++;
		ll sum=0;
		while(l)
		{
			sum+=fen[l];
			l-=(l&-l);
		}
		return sum;
	}
	ll get(ll l,ll r)
	{
		return get(r)-get(l-1);
	}
};