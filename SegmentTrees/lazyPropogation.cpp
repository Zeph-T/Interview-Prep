#include <bits/stdc++.h>

using namespace std;



class segmentTree{

public:
	vector<int>st,lazy;
	int n;
	void init(int n){
		this->n = n;
		st.resize(4 * n , 0);
		lazy.resize(4 * n , 0);
	}

	void build(int start,int end , int node,vector<int>&v){
		// for leaf nodes
		if(start == end){
			this->st[node] = v[start];
			return ;
		}

		int mid = (start + end)/2;
		// left subtree is from start to mid
		build(start,mid,2 * node+1,v);
		// right subtree is from mid+1 to end
		build(mid+1,end,2*node+2,v);

		this->st[node] = this->st[2*node+1] + this->st[2*node+2];
	}

	int query(int start,int end,int l,int r,int node){
		// no overlap
		if(start > r or end < l)return 0;
		//complete overlap



		// lazy propogation / clear the lazy update
		if(lazy[node] != 0){
			// pending updates which needs to be done
			// update the segment tree node with the proper value
			st[node] += lazy[node] * (start - end + 1);
			if(start != end){
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0; 
		}


		else if(start >= l and end <= r)return this->st[node];
		//partial overapp
		int mid = (start + end)/2;
		int q1 = query(start,mid,l,r,2*node+1);
		int q2 = query(mid+1,end,l,r,2*node+2);
		return q1+q2;

	}

	void update(int start,int end,int node,int index,int value){
		// no overlap
		if(start > r or end < l)return 0;

		//complete overlap



		// lazy propogation / clear the lazy update
		if(lazy[node] != 0){
			// pending updates which needs to be done
			// update the segment tree node with the proper value
			st[node] += lazy[node] * (start - end + 1);
			if(start != end){
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0; 
		}
		
		if(start >= l and end <= r){
			st[node] += value * (end - start + 1);
			if(start != end){
				lazy[2 * node + 1] += value;
				lazy[2 * node + 2] += value;
			}
		}
	}	

	void update(int left,int right,int value){
		update(0,n-1,0,left,right,value);
	}

	int query(int l,int r){
		return query(0,n-1,l,r,0);
	}



	void build(vector<int>&v){
		build(0,v.size()-1,0,v);
	}
};





int main(){
	freopen("../input.txt","r",stdin);
	freopen("../output.txt","w",stdout);
	vector<int>v = {1 ,2 ,3,4,5,6,7,8};	
	segmentTree tree;
	tree.init(v.size());
	tree.build(v);
	// cout<<tree.query(2,4)<<endl;
	tree.update(4,10);
	// cout<<tree.query(2,4)<<endl;
	cout<<(4 ^ 5 ^ 2);
	return 0;	
}
