## [H-Index](https://programmers.co.kr/learn/courses/30/lessons/42747)

* 어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index이다.

* 처음에 다 틀렸다가 아래 테스트 케이스를 보고 고쳤다

  * H-index는 citations의 원소가 아닐 수도 있다.

    [12,11,10,9,8,1] => 5

    [6,6,6,6,6,1] => 5

  * 모든 논문의 인용 횟수가 논문의 갯수보다 많을 때는 논문의 갯수를 return 해야 한다

    [20,21,22,23] => 4

    [4,4,4] => 3

```java
class Solution {
	public int solution(int[] citations) {
		Integer[] arr = new Integer[citations.length + 1];
		arr[0] = 0;
		for (int i = 1; i <= citations.length; i++) {
			arr[i] = citations[i - 1];
		}

		Arrays.sort(arr, 1, arr.length, Collections.reverseOrder());

		for (int i = arr.length - 1; i >= 0; i--) {
			if (arr[i] >= i) {
				return i;
			}
		}
		return 0;
	}
}
```
