int t[4*mxn];
int n;

void build(int v,int tl,int tr){
	if(tl == tr){
		t[v] = a[tl];
	}else{
		int tm = (tl + tr)/2;
		build(2*v,tl,tm);
		build(2*v + 1,tm + 1,tr);
		t[v] = combine(t[2*v],t[2*v + 1]);
	}
}

int query(int v,int tl,int tr,int l,int r){
	if((tl >= l) && (tr <= r)) return t[v];
	if(l > tr || r < tl) return 0;
	int tm = (tl + tr)/2;
	return combine(query(2*v,tl,tm,l,r),query(2*v + 1,tm + 1,tr,l,r));
}

void update(int v,int tl,int tr,int val,int pos){
	if(tl == tr){
		t[v] = val;
	}else{
		int tm = (tl + tr);
		if(pos <= tm){
			update(2*v,tl,tm,val,pos);
		}else{
			update(2*v + 1,tm + 1,tr,val,pos);
		}
	}
}

