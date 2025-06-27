struct Trie
{
	Trie *next[2];
};
Trie *root=NULL,*temp=NULL;

void insert(ll x,int bit)
{
	temp=root;
	for(int j=bit;j>=0;j--)
	{
		bool p=(x&(1ll<<j));
		if(temp->next[p]==NULL)
			temp->next[p]=new Trie();
		temp=temp->next[p];
	}
}

ll min_xor(ll x,int bit)
{
	ll ans=0;
	temp=root;
	for(int j=bit;j>=0;j--)
	{
		bool p=(x&(1ll<<j));
		if(temp->next[p]==NULL)
		{
			ans+=(1ll<<j);
			temp=temp->next[!p];
		}
		else
		{
			temp=temp->next[p];
		}
	}
	return ans;
}