DIRS = (0, 1), (1, 0), (0, -1), (-1, 0)
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m=len(matrix)
        n=len(matrix[0])
        i=j=dir=0
        ans=[]
        for _ in range(m*n):
            ans.append(matrix[i][j])
            matrix[i][j]=None
            x,y=i+DIRS[dir][0],j+DIRS[dir][1]
            if x<0 or x>=m or y<0 or y>=n or matrix[x][y]==None:
                dir=(dir+1)%4
            i+=DIRS[dir][0]
            j+=DIRS[dir][1]
        return ans