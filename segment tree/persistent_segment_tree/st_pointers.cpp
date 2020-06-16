
const int mxn = 2e5+1;
int a[mxn], p[mxn];
int n, q;

struct Node{
    Node *left;
    Node *right;
    int cnt;

    Node(Node *l = NULL, Node *r = NULL, int s = 0){
        left = l;
        right = r;
        cnt = s;
    }
};

Node* version[mxn];

void build(Node* node, int tl=0, int tr=n-1){
    if(tl==tr){
        node->cnt = 0;
        return; 
    }

    int mid = (tl+tr)/2;
    node->left = new Node();
    node->right = new Node();
    build(node->left, tl, mid);
    build(node->right, mid+1, tr);
    node->cnt = node->left->cnt + node->right->cnt;
}

int query(Node* root, int ql, int qr, int tl=0, int tr=n-1){
    if(tl > tr || tr < ql || tl > qr) return 0;
    if(ql <= tl && tr <= qr){
        return root->cnt;
    }

    int mid = (tl+tr)/2;
    int lcnt = query(root->left, ql, qr, tl, mid);
    int rcnt = query(root->right, ql, qr, mid+1, tr);
    return lcnt + rcnt;
}

void update(Node *prev_version, Node *cur_version, int ind, int val, int tl=0, int tr=n-1){
    if(tl > tr){
        return;
    } 
    
    if(ind < tl || ind > tr){
        cur_version = prev_version;
        return;
    }

    if(tl == tr){
        cur_version->cnt = val;
        return;
    }

    int mid = (tl+tr)/2;
    cur_version->left = new Node();
    cur_version->right = new Node();
    update(prev_version->left, cur_version->left, ind, val, tl, mid);
    update(prev_version->right, cur_version->right, ind, val, mid+1, tr);
    cur_version->cnt = cur_version->left->cnt + cur_version->right->cnt;
}


void upgrade(Node *prev_version, Node *cur_version, int ind, int val, int tl=0, int tr=n-1){
    if(ind < tl || ind > tr){
        return;
    }

    if(tl == tr){
        cur_version->cnt = val;
        return;
    }

    int mid = (tl+tr)/2;
    if(ind <= mid){
        cur_version->left = NULL;
        cur_version->right  = prev_version->right;
        upgrade(prev_version->left, cur_version->left, ind, val, tl, mid);
    }
    else{
        cur_version->right = NULL;
        cur_version->left  = prev_version->left;
        upgrade(prev_version->right, cur_version->right, ind, val, mid+1, tr);
    }

    cur_version->cnt = cur_version->left->cnt + cur_version->right->cnt;
}

void solve_bamboo(){
    version[0] = new Node();
    build(version[0]);

    int last_occ[n+1];
    memset(last_occ, -1, sizeof(last_occ));

    for(int i = 0; i<n; i++){
        version[i+1] = new Node();
       
        if(last_occ[a[i]] != -1){

            Node *new_root = new Node();
            assert(query(version[i], last_occ[a[i]], last_occ[a[i]])==1);
            upgrade(version[i], new_root, last_occ[a[i]], 0);
        
            assert(query(new_root, last_occ[a[i]], last_occ[a[i]])==0);
            assert(query(new_root, i, i)==0);

            upgrade(new_root, version[i+1], i, 1);
            assert(query(version[i+1], i, i)==1);
        }
        else{
            assert(query(version[i], i, i)==0);
            upgrade(version[i], version[i+1], i, 1);
            assert(query(version[i+1], i, i)==1);
        }
        last_occ[a[i]] = i;
    }
    int ans = 0, x, d;
    int l, r;
    for(int i = 0; i < q; i++){
        cin>>x>>d;
        x ^= ans;
        d ^= ans;
        x--;
        r = min(n-1, x + d);
        ans = query(version[r+1], x, r, 0, n-1);
        cout<<ans<<"\n";
    }

    
    // for(int i = 0; i < q; i++){
    //     cin>>l>>r;
    //     l--, r--;
    //     // cerr<<l<<" "<<r<<"\n";
    //     cout<<query(version[r+1], l, r)<<"\n";
    // }
    for(int i = 0; i <= n; i++) version[i] = NULL;
}