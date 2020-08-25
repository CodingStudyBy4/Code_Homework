## [카펫](https://programmers.co.kr/learn/courses/30/lessons/42842)

```java
class Solution {
	public int[] solution(int brown, int yellow) {
		int[] answer = new int[2];

		int all = brown + yellow;
		int row = 3;
		while (true) {
			if (all % row == 0) {
				int col = all / row;

				if (yellow == (row - 2) * (col - 2)) {
					answer[0] = Math.max(row, col);
					answer[1] = Math.min(row, col);
					break;
				}
			}
			row++;
		}

		return answer;
	}
}
```
