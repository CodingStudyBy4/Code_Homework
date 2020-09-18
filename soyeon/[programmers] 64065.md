## [튜플](https://programmers.co.kr/learn/courses/30/lessons/64065)

* 젤 많이 나오는 수가 가장 앞에 있는 수일 것이다
* HashMap에 수, 갯수의 쌍을 넣은 뒤 갯수에 대해서 정렬하여 리턴하도록 한다.

```java
import java.util.*;

class Solution {
	public int[] solution(String s) {
		HashMap<Integer, Integer> hashmap = new HashMap<Integer, Integer>();

		StringTokenizer st = new StringTokenizer(s, "{},", false);
		Integer input = 0;
		while (st.hasMoreTokens()) {
			input = Integer.valueOf(st.nextToken());

			hashmap.put(input, hashmap.getOrDefault(input, 0) + 1);
		}

		// hashmap 의 value 기준 정렬
		List<Integer> keySetList = new ArrayList<>(hashmap.keySet());
		Collections.sort(keySetList, new Comparator<Integer>() {

			@Override
			public int compare(Integer o1, Integer o2) {
				return hashmap.get(o2).compareTo(hashmap.get(o1));
			}

		});

		int index = 0;
		int answer[] = new int[keySetList.size()];
		for (Integer key : keySetList) {
			answer[index++] = key;
		}
		return answer;
	}
}
```
