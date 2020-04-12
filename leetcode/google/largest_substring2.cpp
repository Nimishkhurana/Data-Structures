def largest_subarray(a, k):
  # store first starting index for a subarray as the largest, since 'a' will always be <= 'k'
  first_idx = 0
  # check indices where a subarray of size k can be made
  for x in range(1, len(a) - k + 1):
    # replace the largest first index if a larger value is found
    if a[first_idx] < a[x]:
      first_idx = x

  # return subarray starting at that largest possible first index with size k
  return a[first_idx:first_idx+k]
// O(n) time and O(1) space

// Small modification if values are nonunique:

def largest_subarray(a, k):
  first_idx = 0
  for x in range(1, len(a) - k + 1):
    # compare values at each index for the would be sub arrays
    for i in range(k):
      # replace the largest index and break out of the inner loop is larger value is found
      if a[first_idx + i] <= a[x + i]:
        first_idx = x
        break
      # if the current stored largest subarray is larger than the current subarray, move on
      else:
        break

  return a[first_idx:first_idx+k]