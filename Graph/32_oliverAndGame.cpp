//Problem Link : https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/

#include<bits/stdc++.h>
using namespace std ; 

int main()  {
	int n ,  i ,j ,k , a , b , q; 
	// cin>>n ; 
	scanf("%d",&n) ;
	vector<vector<int> > adj(n) ;

    for(i = 0 ; i < n -1 ; i++)  {
		// cin>>a>>b ; 
		scanf("%d%d",&a , &b) ;
		a-- ; b-- ;
		adj[a].push_back(b) ; 
		adj[b].push_back(a) ;
	}

    vector<int> parent(n , -1) ;  
	vector<int> level(n , -1) ;
	queue<int> que ; 

	que.push(0) ; 
	parent[0] = 0 ; level[0] = 0 ; 
    int top ;
	while(que.empty()==false)  {
		top = que.front() ; 
		while(auto ele : adj[top])  {
			if(parent[ele] == -1 )  {
				parent[ele] = top ;
				level[ele] = level[top] + 1 ; 
				que.push(ele) ; 
			}
		}
	}

	scanf("%d",&q) ;
	for(int i = 0 ; i < q ; i++)  {
		cin>>type>>a>>b ; 
		a-- ; b-- ;
		if(a == b) {
			cout<<"YES\n" ;
			continue ;
		}
		else if(a==0) {
			cout<<"NO\n" ; 
			continue ; 
		}

		if(type==0) {
			while(parent[a] != a ) {
			     a = parent[a] ; 
				 if(a==b) {
					 cout<<"YES\n" ;
					 break ; 
				 }
			}
			if(parent[a] == a ) {
				cout<<"NO\n" ;
			}
		}else {
			queue<int> q2 ; 
			int flag = 0 ; 
			q2.push_back(a) ; 
			while(q2.empty()==false && flag == 0) {
				top = q2.front() ; 
				q2.pop() ; 
				for(auto ele : adj[top])  {
					if(level[ele] > level[top])  {
						if(ele == b) {
							// cout<<"YES\n" ; 
							flag = 1 ; 
							// while(q2.empty()==false) q2.pop() ;
							break ; 
						}
					}
				}
			}

			if(flag==1)  cout<<"YES\n" ; 
			else cout<<"NO\n" ;
		}
	}

}
