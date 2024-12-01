class Solution:
    def DFS(self, order: str, digists: str, idx: int, ans: List[str]):
        if idx>=len(digists):
            if order!="":
                ans.append(order)
            return

        digist=int(digists[idx])

        if digist==2:

            self.DFS(order+"a", digists, idx+1, ans)
            self.DFS(order+"b", digists, idx+1, ans)
            self.DFS(order+"c", digists, idx+1, ans)
        elif digist==3:
            self.DFS(order+"d", digists, idx+1, ans)
            self.DFS(order+"e", digists, idx+1, ans)
            self.DFS(order+"f", digists, idx+1, ans)
        elif digist==4:
            self.DFS(order+"g", digists, idx+1, ans)
            self.DFS(order+"h", digists, idx+1, ans)
            self.DFS(order+"i", digists, idx+1, ans)
        elif digist==5:
            self.DFS(order+"j", digists, idx+1, ans)
            self.DFS(order+"k", digists, idx+1, ans)
            self.DFS(order+"l", digists, idx+1, ans)
        elif digist==6:
            self.DFS(order+"m", digists, idx+1, ans)
            self.DFS(order+"n", digists, idx+1, ans)
            self.DFS(order+"o", digists, idx+1, ans)
        elif digist==7:
            self.DFS(order+"p", digists, idx+1, ans)
            self.DFS(order+"q", digists, idx+1, ans)
            self.DFS(order+"r", digists, idx+1, ans)
            self.DFS(order+"s", digists, idx+1, ans)
        elif digist==8:
            self.DFS(order+"t", digists, idx+1, ans)
            self.DFS(order+"u", digists, idx+1, ans)
            self.DFS(order+"v", digists, idx+1, ans)
        elif digist==9:
            self.DFS(order+"w", digists, idx+1, ans)
            self.DFS(order+"x", digists, idx+1, ans)
            self.DFS(order+"y", digists, idx+1, ans)
            self.DFS(order+"z", digists, idx+1, ans)


    def letterCombinations(self, digits: str) -> List[str]:
        ans=[]
        self.DFS("", digits, 0, ans)

        return ans