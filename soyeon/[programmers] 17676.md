## [추석트래픽](https://programmers.co.kr/learn/courses/30/lessons/17676)

* 일단 문제를 제대로 읽어야 한다. `시작시간` + `걸리는 시간`이 아니라, `종료시간` + `걸리는 시간`임

* 틀린 풀이: 86.4 / 100.0
  * 밀리세컨드로 전처리 한 풀이
  * 단순히 구간 +1000ms -1000ms를 할 때, 시간의 단위는 60진법인데 minutes와 hours로 올림 되는 경우를 신경 써주지 않아서 틀린 것 같다

```java
import java.util.*;

class Solution {
	public int solution(String[] lines) {
		int answer = 0;
		Log[] logs = lineToLogs(lines);

		for (int i = 0; i < logs.length; i++) {
			int serverNumStartAfter = 0;
			int serverNumEndAfter = 0;
			int serverNumStartBefore = 0;
			int serverNumEndBefore = 0;

			long startTime = logs[i].startTime;
			long endTime = logs[i].endTime;

			for (int j = 0; j < logs.length; j++) {
				if (isInBoundary(logs[j].startTime, logs[j].endTime, startTime, startTime + 999)) {
					serverNumStartAfter++;
				}

				if (isInBoundary(logs[j].startTime, logs[j].endTime, endTime, startTime + 999)) {
					serverNumEndAfter++;
				}
				if (isInBoundary(logs[j].startTime, logs[j].endTime, startTime - 999, startTime)) {
					serverNumStartBefore++;
				}
				if (isInBoundary(logs[j].startTime, logs[j].endTime, endTime - 999, endTime)) {
					serverNumEndBefore++;
				}
			}
			answer = Math.max(answer, serverNumStartAfter);
			answer = Math.max(answer, serverNumEndAfter);
			answer = Math.max(answer, serverNumStartBefore);
			answer = Math.max(answer, serverNumEndBefore);
		}

		return answer;
	}

	public boolean isInBoundary(long startTime, long endTime, long startDuration, long endDuration) {
		if (startTime <= startDuration && startDuration <= endTime) {
			return true;
		}
		if (startTime <= endDuration && endDuration <= endTime) {
			return true;
		}
		if (startTime <= startDuration && endDuration <= endTime) {
			return true;
		}
		if (startDuration <= startTime && endTime <= endDuration) {
			return true;
		}
		return false;
	}

	public Log[] lineToLogs(String[] lines) {
		Log[] logs = new Log[lines.length];
		for (int i = 0; i < lines.length; i++) {
			StringTokenizer st = new StringTokenizer(lines[i]);
			String date = st.nextToken();
			String endTime = st.nextToken();
			String duration = st.nextToken();

			duration = duration.replace("s", "");
			logs[i] = new Log(endTime);
			logs[i].setStartTime(duration);
		}

		return logs;
	}
}

class Log {
	long startTime;
	long endTime;

	public Log(String endTimes) {
		StringTokenizer st = new StringTokenizer(endTimes, ":");
		long hour = Integer.valueOf(st.nextToken());
		long minute = Integer.valueOf(st.nextToken());
		double second = Double.valueOf(st.nextToken());
		this.endTime = 1000 * 60 * 60 * hour + 1000 * 60 * minute + (long) Math.round(1000 * second);
	}

	public void setStartTime(String duration) {
		this.startTime = this.endTime - (long) Math.round((Double.valueOf(duration) * 1000 - 1));
	}

	@Override
	public String toString() {
		return startTime + " ~ " + endTime;
	}
}
```

* java에 있는 `SimpleDateFormat`과 `Calendar`를 사용해 보아야겠다
