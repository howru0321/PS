class Solution:
    def recurF(self, idx, s: str):
        curr_num=0
        curr_str=""

        while idx<len(s):
            c = s[idx]
            if "0"<=c<="9":
                curr_num=curr_num*10+int(c)
            elif c=="[":
                next_idx, added_str=self.recurF(idx+1,s)
                for _ in range(curr_num):
                    curr_str+=added_str
                idx=next_idx
                curr_num=0
            elif c=="]":
                return idx, curr_str
            else:
                curr_str+=c
            
            idx+=1
        
        return idx, curr_str

    def decodeString(self, s: str) -> str:
        _, ans = self.recurF(0, s)
        return ans