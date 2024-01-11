void merge_sort(vector<int>& arr, int l, int r) {
  if (r <= l) {
    return;
  } else {
    // Same as (l + r) / 2, but avoids overflow
    // for large l and r
    int m = l + (r - l) / 2;

    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);

    if (arr[m] > arr[m+1]) {
      return;
    } else {
      int p1 = m;
      int p2 = r;
      while ((p2 > p1) && (p1 >= 0)) {
        if (arr[p1] < arr[p2]) {
          int tmp = arr[p1];
          for (int i=p1; i<p2; i++){
            arr[i] = arr[i+1];
          }
          arr[p2] = tmp;
          p1--;
          p2--;
        } else {
          p2--;
        }
      }
    }
  }
}
