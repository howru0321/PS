class Solution:
    def compress(self, chars: List[str]) -> int:
        write=0
        curr_char=chars[0]
        curr_num=0

        for c in chars:
            if curr_char==c:
                curr_num+=1
            else:
                chars[write]=curr_char
                write+=1
                curr_char=c
                if curr_num>1:
                    for d in str(curr_num):
                        chars[write]=d
                        write+=1
                curr_num=1
                
        chars[write]=curr_char
        write+=1
        if curr_num>1:
            for d in str(curr_num):
                chars[write]=d
                write+=1
        
        return write