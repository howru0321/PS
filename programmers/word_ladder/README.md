# Word Ladder
[link](https://school.programmers.co.kr/learn/courses/30/lessons/43163)

## Category
- Brute Force
- BFS
- DFS
- Back Tracking
## Explain
### DFS
- time complexity : O(N!*L)
    - 최악의 경우 모든 경우의 수를 고려해야한다
- space complexity : O(N^2 * L)
    - DFS는 stack에 다음에 사용할 next_words리스트를 넣어줘야하므로 stack에 들어갈 N개의 원소에 대해 N개가 들어간다

### BFS
- time complexity : O(N^2*L)
    - 이미 다른 단어들과 비교된 단어의 경우, 다음에 고려될 필요가 없다. 각 경우는 최악의 경우 N개씩 검사한다
    - DFS는 각 경우에 대해 단어를 하나씩 줄여 나가 한 단어에 대한 비교 횟수는 적을 지 몰라도, 각 depth별로 state를 모르기에 다른 경로에서 검사한 단어에 대해서도 모두 처리해 주는 상황이 발생해 더 좋지 않다
- space complexity : O(N*L)
    - 최악의 경우 stack에 모든 단어가 들거간다


BFS가 더 효율적이다.
