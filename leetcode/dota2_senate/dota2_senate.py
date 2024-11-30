class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        n=len(senate)
        dire_idxs = deque()
        radiant_idxs = deque()

        for idx, senator in enumerate(senate):
            if senator=="D":
                dire_idxs.append(idx)
            elif senator=="R":
                radiant_idxs.append(idx)
        
        while dire_idxs and radiant_idxs:
            dire_idx = dire_idxs.popleft()
            radiant_idx = radiant_idxs.popleft()

            if dire_idx>radiant_idx:
                radiant_idxs.append(radiant_idx+n)
            else:
                dire_idxs.append(dire_idx+n)
        
        if len(dire_idxs)==0:
            return "Radiant"
        elif len(radiant_idxs)==0:
            return "Dire"
        else:
            return "what????"
