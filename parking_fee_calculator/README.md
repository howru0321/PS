# Parking Fee Calculator
[link](https://school.programmers.co.kr/learn/courses/30/lessons/92341)

- time complexity : O(N logN)
    - map은 자동정렬이 되므로 각 N번의 insert마다 log N
- space complexity : O(N)


N=1000이여서 이중 for문(O(N^2)=10^6)도 잘 돌아가지만, hash_map을 통해 O(N logN)으로 최적화
