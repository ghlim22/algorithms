def get_tree_cnt(n):
  memo = {}
  if n==0: return 1
  if n==1: return 1
  memo[0]=1
  memo[1]=1
  for i in  range(2, n + 1):
    memo[i] = 0
    for j in range(0, i // 2):
      memo[i] += 2 * memo[j] * memo[i - 1 - j]
    if (i % 2 == 1):
      memo[i] += memo[i // 2] * memo[i // 2]
  return memo[n]