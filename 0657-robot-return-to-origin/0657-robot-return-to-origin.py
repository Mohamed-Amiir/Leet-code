class Solution:
    def judgeCircle(self, moves: str) -> bool:
        r = 0 
        l = 0
        u = 0
        d = 0
        for c in moves : 
           if c == 'U': 
              u += 1
           if c == 'D': 
              d += 1
           if c == 'R': 
              r += 1
           if c == 'L': 
              l += 1
        if u == d and l == r :
           return True
        return False