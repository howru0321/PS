# Bridge Trucks
[link](https://school.programmers.co.kr/learn/courses/30/lessons/42583)

- time complexity : O(N+L)
    - 1, 2는 최악의 경우 한번에 한 트럭이 다리를 지나간다.
    - optim에서 현재 다리에 트럭을 추가하지 못하면 다리 위에 트럭이 나갈 시간으로 바로 점프해서 각 계산마다 트럭을 다리에 집어넣을 수 있도록 구현=>O(N+L)
- space complexity : O(L)