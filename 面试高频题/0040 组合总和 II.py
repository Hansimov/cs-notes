from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(begin, path, remain):
            if remain == 0:
                res.append(path[:])
                return
            for i in range(begin, size):
                if candidates[i] > remain:
                    break
                if i > begin and candidates[i-1] == candidates[i]:
                    continue
                path.append(candidates[i])
                dfs(i+1, path, remain-candidates[i])
                path.pop()
        size = len(candidates)
        if size == 0:
            return []
        candidates.sort()
        res = []
        dfs(0, [], target)
        return res


