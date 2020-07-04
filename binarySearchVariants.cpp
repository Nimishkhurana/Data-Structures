

bool ok(int x) {
  //check if this x works

  return false; 
}

// T T T T F F F F ....   find last T
int lastOcc(int n) {
    // search space 0...n-1
    int l = 0, r = n, mid;
    while(l < r) {
        mid = l + (r - l + 1)/2;
        
        if(ok(mid))
            l = mid;
        else 
            r = mid - 1;
    }
    return l;
}

/// F F F F T T T T ...... find first T
int firstOcc(int n) {
    // search space 0...n-1
    int l = 0, r = n, mid;
    while(l < r) {
        mid = l + (r - l)/2;
        
        if(ok(mid))
            r = mid;
        else 
            l = mid + 1;
    }
    return l;
}