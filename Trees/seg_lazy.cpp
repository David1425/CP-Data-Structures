long long lazy[MV+2] = {0}, seg[MV+2] = {0};

void build(int i, int l, int r) {
    if (l >= n) {
        seg[i] = 0;
        return;
    }
    if (l == r-1) {
        seg[i] = a[l];
        return;
    }
    
    build((i<<1)+1, l, (l+r)>>1);
    build((i<<1)+2, (l+r)>>1, r);
    seg[i] = seg[(i<<1)+1]+seg[(i<<1)+2];
}

void upd(int i, int x, int y, int v, int l, int r) {
    if (lazy[i]) {
        seg[i] += (r-l)*lazy[i];
        if (l < r-1) {
            lazy[(i<<1)+1] += lazy[i];
            lazy[(i<<1)+1] += lazy[i];
        }
        lazy[i] = 0;
    }
    
    if (r <= x || l >= y) return;
    if (l >= x && r <= y) {
        seg[i] += (r-l)*v;
        if (l < r-1) {
            lazy[(i<<1)+1] += v;
            lazy[(i<<1)+2] += v;
        }
        return;
    }
    
    upd((i<<1)+1, x, y, v, l, (l+r)>>1);
    upd((i<<1)+2, x, y, v, (l+r)>>1, r);
    seg[i] = seg[(i<<1)+1] + seg[(i<<1)+2];
}

long long qry(int i, int x, int y, int l, int r) {
    if (lazy[i]) {
        seg[i] += (r-l)*lazy[i];
        if (l < r-1) {
            lazy[(i<<1)+1] += lazy[i];
            lazy[(i<<1)+1] += lazy[i];
        }
        lazy[i] = 0;
    }
    
    if (r <= x || l >= y) return 0;
    if (l >= x && r <= y) return seg[i];
    
    return qry((i<<1)+1, x, y, l, (l+r)>>1) + qry((i<<1)+2, x, y, (l+r)>>1, r);
}
