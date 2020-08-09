vector<int> convert_into_factoradic(int x){
    vector<int>v;
    int p=x;
    int i=1;
    while(p){
        v.eb(p%i);
        p=p/x;
        i++;
    }
    reverse(all(v));
    return v;
}

int factoradic_to_decimal(vector<int>& v){
    int n=v.size();
    int ans=0;
    for(int i=0,mul=n;i<n;i++,mul--) {
        ans=(ans*mul%MOD+v[i])%MOD;
    }
    return ans;
}

vector<int> find_perm(int n,vector<int>&v){
    ordered_set<int>st;
    int siz = v.size();
    vector<int>v1;
    for(int i=0;i<n-siz;i++){
        v1.pb(i);
    }
    for(int i=n-siz;i<n;i++){
        st.insert(i);
    }
    for(int i=0;i<siz;i++){
        int perm_i = *st.fbo(v[i]);//find by order
        v1.pb(perm_i);
        st.erase(perm_i);
    }
    return v1;
}

vector<int> kth_perm(int n, int k){
    vector<int> v = convert_into_factoradic(k);
    return find_perm(n,v);
}

vector<int> find_order_of_perm(vector<int>&v){
    ordered_set<int>st;
    int n = v.size();
    for(int i=0;i<n;i++){
        st.insert(v[i]);
    }
    vector<int> fac;
    for(int i=0;i<n;i++){
        int x = st.ook(v[i]);
        fac.pb(x);
        st.erase(v[i]);
    }
    return fac;
}

int order(vector<int> &v){
    vector<int> fac = find_order_of_perm(v);
    return factoradic_to_decimal(fac);
}