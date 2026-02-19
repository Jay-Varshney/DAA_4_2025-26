int maxMin(int k, vector<int> arr) {
    long long n = arr.size();
    sort(arr.begin(), arr.end());
    // for(auto i: arr){
    //     cout << i << " ";
    // }
    int diff = INT_MAX;
    for(int i = 0 ; i < n-k+1; i++){
        diff = min(arr[k-1+i] - arr[i], diff);
    }
    return diff;
    // long long f = max(arr[0], arr[k-1]) - min(arr[0], arr[k-1]);
    // long long s = max(arr[n-k], arr[n-1]) - min(arr[n-k], arr[n-1]);
    // cout << "\n" << f << " " << s << "\n";
    // return min(f, s);
}