class Solution:
    def decodeString(self, s: str) -> str:
        num_stack=[]
        str_stack=[]
        curr_num=0
        curr_str=""
        for c in s:
            if "0"<=c<="9":
                curr_num=curr_num*10+int(c)
            elif c=="[":
                num_stack.append(curr_num)
                curr_num=0
                str_stack.append(curr_str)
                curr_str=""
            elif c=="]":
                prev_num=num_stack[-1]
                num_stack.pop()
                merged_str=str_stack[-1]
                str_stack.pop()
                for i in range(prev_num):
                    merged_str+=curr_str
                curr_str=merged_str
            else:
                curr_str+=c
        
        return curr_str
