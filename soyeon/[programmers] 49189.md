## [가장 먼 노드](https://programmers.co.kr/learn/courses/30/lessons/49189)

```java
import java.util.*;
class Solution {
	public static int max = 0;

	public int solution(int n, int[][] edge) {
		int answer = 0;
		int isVisited[] = new int[n + 1];

		HashMap<Integer, LinkedList<Integer>> map = new HashMap<Integer, LinkedList<Integer>>();
		for (int i = 0; i < edge.length; i++) {
			int start = edge[i][0];
			int end = edge[i][1];

			if (map.containsKey(start)) {
				LinkedList<Integer> list = map.get(start);
				list.add(end);
				map.replace(start, list);
			} else {
				LinkedList<Integer> list = new LinkedList<Integer>();
				list.add(end);
				map.put(start, list);
			}
			
			if (map.containsKey(end)) {
				LinkedList<Integer> list = map.get(end);
				list.add(start);
				map.replace(end, list);
			} else {
				LinkedList<Integer> list = new LinkedList<Integer>();
				list.add(start);
				map.put(end, list);
			}
		}

		isVisited = updateDistance(map, isVisited);

		for (int i = 2; i <= n; i++) {
			if (isVisited[i] == max) {
				answer++;
			}
		}
		return answer;
	}

	public int[] updateDistance(HashMap<Integer, LinkedList<Integer>> map, int[] isVisited) {
		LinkedList<Integer> list = new LinkedList<Integer>();
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(1);
		while (!queue.isEmpty()) {
			int start = queue.poll();

			list = map.get(start);
			if (list == null) {
				continue;
			}

			for (int next : list) {
				if (isVisited[next] == 0 || isVisited[next] > isVisited[start] + 1) {
					queue.add(next);
					isVisited[next] = isVisited[start] + 1;
					max = Math.max(max, isVisited[start] + 1);
				}
			}
		}
		return isVisited;
	}
}
```
