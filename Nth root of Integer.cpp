// TC = O(log N)
// SC = O(1)

long long fun(int num, int n, int m) {
  long long mult = 1;

  // Perform multiplication n times
  for(int i = 0; i < n; i++) {
    mult *= num;

    // If the multiplication exceeds m, return 2
    if(mult > m)
      return 2;
  }

  // If the multiplication is less than m, return 0
  if(mult < m)
    return 0;

  // Otherwise, return 1
  return 1;
}

int NthRoot(int n, int m) {
  int low = 1, high = m;

  // Perform binary search within the range [low, high]
  while(low <= high) {
    int mid = (low + high) / 2;

    // Call the fun() function to check the result
    int val = fun(mid, n, m);

    if(val == 1)
      return mid; // Found the desired root

    else if(val == 2)
      high = mid - 1; // Adjust the high end of the range

    else
      low = mid + 1; // Adjust the low end of the range
  }

  // If no root is found, return -1
  return -1;
}
