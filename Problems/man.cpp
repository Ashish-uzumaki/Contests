int lef[n];
int rig[n];
int lef_hash[];
for(int i = 0 ;i < n; i++){
    hash[arr[i]] += 1; // frequency of the value;
    lef[i] = lef_hash[arr[i]]; // frequency of the ith value form (0 -> i);
}
int rig_hash[];
for(int i = n-1; i>= 0; i--){
    rig_hash[arr[i]]+=1;
    rig[i] = rig_hash[arr[i]];
}
int ans = 0;
for(int i = 0; i < n; i++){
    int val = lef[i];
    for(int j = i+1; j < n; j++){
        if( rig[j] < val){
            ans++;
        }
    }
}
cout << ans << endl;