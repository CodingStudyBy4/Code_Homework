## [구명보트](https://programmers.co.kr/learn/courses/30/lessons/42885)

* 효율성에서 통과하지 못한 코드
  * 처음에는 최대한 limit에 가깝게 구명보트에 태우려고 이렇게 짰다.

```java
class Solution {
	public int solution(int[] people, int limit) {

		int answer = 0;

		Arrays.sort(people);
		int[][] boats = new int[people.length][2]; 
		// boats[i][0]: i번째 보트에 탄 사람들의 무게
		// boats[i][1]: i번째 보트에 탄 사람들의 수
    
		for (int i = people.length - 1; i >= 0; i--) {
			int person = people[i];
			int index = 0;
			while (true) {
				if (boats[index][0] + person <= limit && boats[index][1] <= 1) {
					boats[index][0] += person;
					boats[index][1]++;
					answer = Math.max(answer, index);
					break;
				} else {
					index++;
				}
			}
		}

		return answer + 1; // 보트 번호는 0부터 시작하므로 보트의 갯수를 구하기 위해서는 1을 더해준다.
	}
}
```

* 효율성에서 통과한 코드
  * 구명보트에는 어차피 2명만 태우면 되므로 가장 무거운 사람 + 가벼운 사람의 조합으로 태워보고 limit 보다 크면 무거운 사람을 혼자 태우는 식으로 풀도록

```java
class Solution {
	public int solution(int[] people, int limit) {

		int answer = 0;
		int index = 0;
		Arrays.sort(people);
		for (int i = people.length - 1; i >= 0 && i >= index; i--) {
			int personBig = people[i];
			int personSmall = people[index];

			if (i == index) {
				answer++;
				break;
			}

			if (personBig + personSmall <= limit) {
				answer++;
				index++;
			} else {
				answer++;
			}

		}

		return answer;
	}
}
```
