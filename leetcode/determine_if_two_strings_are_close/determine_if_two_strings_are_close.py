class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if(len(word1)!=len(word2)):
            return False

        word1_dict=defaultdict(int)
        word1_nums=[]
        for c in word1:
            word1_dict[c]+=1
        for num in word1_dict.values():
            word1_nums.append(num)
        word1_nums.sort()

        word2_dict=defaultdict(int)
        word2_nums=[]
        for c in word2:
            word2_dict[c]+=1
        for num in word2_dict.values():
            word2_nums.append(num)
        word2_nums.sort()

        for idx, num in enumerate(word1_nums):
            if(num!=word2_nums[idx]):
                return False
        for c in word1_dict.keys():
            if word2_dict[c]==0:
                return False
        
        return True