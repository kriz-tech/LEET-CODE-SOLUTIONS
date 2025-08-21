class Solution(object):
    def countHist(self, h):
        n = len(h)
        st = []
        sum_arr = [0] * n
        ans = 0

        for j  in range(n):
            while st and h[st[-1]] >= h[j]:
                st.pop()

            if st:
                prev = st[-1]
                sum_arr[j] = sum_arr[prev] + h[j] * (j - prev)
            else:
                sum_arr[j] = h[j] * (j + 1)
            
            ans += sum_arr[j]
            st.append(j)
        return ans

    def numSubmat(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        m, n = len(mat), len(mat[0])
        h = [0] * n
        res = 0

        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    h[j] = 0
                else:
                    h[j] += 1
                
            res += self.countHist(h)
        return res

