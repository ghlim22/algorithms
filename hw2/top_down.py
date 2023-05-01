def memoize(f):
    memo = {}
    def helper(x):
        if (x) not in memo:
            memo[x] = f(x)
        return memo[x]
    return helper

def get_tree_cnt(n):
    if n == 0: return 1
    if n == 1: return 1
    sum = 0
    if (n % 2 == 0):
        for i in range(0, n // 2):
            sum += 2*get_tree_cnt(i)*get_tree_cnt(n - 1 - i)
    else:
        for i in range(0, n // 2):
            sum += 2*get_tree_cnt(i)*get_tree_cnt(n - 1 - i)
        sum += get_tree_cnt(n//2)*get_tree_cnt(n//2)
    return sum

get_tree_cnt=memoize(get_tree_cnt)
