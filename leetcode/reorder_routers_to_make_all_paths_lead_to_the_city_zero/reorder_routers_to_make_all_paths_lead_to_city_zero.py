class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        n=len(connections)
        adjacency_list=defaultdict(list)
        original_dirs=set()
        for connection in connections:
            start=connection[0]
            end=connection[1]
            adjacency_list[start].append(end)
            adjacency_list[end].append(start)
            original_dirs.add((start,end))
        
        stack=deque()
        stack.append(0)
        ans=0
        visited=set()
        visited.add(0)
        while stack:
            node=stack.pop()
            for child_node in adjacency_list[node]:
                if child_node in visited:
                    continue
                stack.append(child_node)
                visited.add(child_node)
                if (child_node, node) not in original_dirs:
                    ans+=1

        return ans