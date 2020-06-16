#include <bits/stdc++.h>
#define rf freopen("inp.in","r",stdin)
#define ll long long
#define F first
#define S second

using namespace std;

const int MAX = 3e5 + 50;

const ll MOD1 = (ll)(1e9 + 7);
const ll MOD2 = (ll)(1e9 + 297);

vector < int > adjList[MAX];

ll C[MAX];
int P[MAX] , N;

ll  PRIME = 137;
ll  H1[MAX] , H2[MAX] , A[MAX];

set < pair < ll , ll > > S[MAX], S2[MAX];

int root( int x ){ // Path Compression
	if( P[x] == x ) return x;
	return P[x] = root( P[x] );
}

void merge( int a , int b ){ // Union by Size
	
	a = root(a) , b = root(b);
	
	if( a == b ) return;
	
	if( S[a].size() < S[b].size() ) swap( a , b );
	
	for( pair < ll , ll > cur : S[b] )
		S[a].insert( cur );

	S[b].clear();
	P[b] = a;
}

void dfs1( int node , int par ){ // Compute Prefix Hashes
	
	H1[node] = ( H1[par] * PRIME + A[node] ) % MOD1 ; // First Hash
	H2[node] = ( H2[par] * PRIME + A[node] ) % MOD2 ; // Second Hash

	for( int next : adjList[node] ){
		if( next == par ) continue;
		dfs1( next , node );
	}

}

void dfs2( int node , int par ){
	
	S[node].insert( { H1[node] , H2[node] } );

	for( int next : adjList[node] ){
		if( next == par ) continue;
		dfs2( next , node );
		merge( node , next );
	}

    S2[node] = S[root(node)];
}

int main(){
	
	//rf;
	cin.tie(0) , ios::sync_with_stdio(false);
	cin >> N;

	for(int i = 1 ; i <= N ; i++){
		cin >> C[i];
		P[i] = i;
	}

	for(int i = 1 ; i <= N ; i++){
		char x;
		cin >> x;
		A[i] = ( x - 'a' + 1 );
	}

	for(int i = 1 ; i < N ; i++){
		int u , v;
		cin >> u >> v;
		adjList[u].emplace_back(v);
		adjList[v].emplace_back(u);
	}

	dfs1(1 , 0);
	dfs2(1 , 0);
	
    // cerr<<"\n\n";
	// for(int i = 1; i <= N; i++){
	//     D2[i] = S2[i].size();
    //     // cerr<<D[i]<<" "<<D2[i]<<"\n";
	// }


	ll mx = 0 , mxcnt = 0;
	for(int i = 1 ; i <= N ; i++){
		if( S2[i].size() + C[i] > mx )
			mx = S2[i].size() + C[i] , mxcnt = 1;
		else if( S2[i].size() + C[i] == mx )
			mxcnt++;
	}

	cout << mx << endl;
	cout << mxcnt << endl;

}