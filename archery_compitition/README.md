# Archery Compitition
[link](https://school.programmers.co.kr/learn/courses/30/lessons/92342)

- time complexity : O(3^10) < O(11H10)
    - 1은 10개의 활을 11개의 과녁에 중복되게 배치하는 경우 모두 brute force
    - 2는 각 index당 win/loss-할당x/loss-최대할당 총 세가지 경우에 대해 brute force
    - remain고려하지 않고 모든 경우를 돌면 10^11=1000초로 backtracking을 하여도 시간초과가 일어난다
    - DFS brute force는 모든 경우을 어떻게 정하는지가 가장 중요하다!
- space complexity : O(11)