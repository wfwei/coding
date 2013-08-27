public class Solution {

	// 不可达输出A的长度
	public int jump(int[] A) {
		return jump3(A);

		// int[] minSteps = new int[A.length];
		// Arrays.fill(minSteps, Integer.MAX_VALUE - 1);
		// jump2(A, 0, 0, minSteps);
		// return minSteps[A.length - 1];

		// return jump1(A, 0);
	}

	// 从后往前计算每一步的最小跳数
	private int jump3(int[] A) {
		if (A.length < 2)
			return 0;
		int e = A.length - 1;
		A[e] = 0;
		while (e > 0) {
			e--;
			if (A[e] <= 0)
				A[e] = A.length;
			else
				A[e] = min(A, e + 1, e + A[e]) + 1;
		}

		return A[0];
	}

	private int min(int[] A, int s, int e) {
		int min = A[s];
		if (e > A.length - 1)
			e = A.length - 1;
		while (s < e) {
			s++;
			if (A[s] < min)
				min = A[s];
		}
		return min;
	}

	// 从前向后dfs遍历 剪枝,还是TLE
	private void jump2(int[] A, int s, int curStep, int steps[]) {
		if (s > A.length - 1) {
			s = A.length;
		}
		if (curStep < steps[s])
			steps[s] = curStep;

		for (int next = s + 1; next <= s + A[s] && next < A.length; next++) {
			if (steps[next] <= curStep + 1)
				continue;
			jump2(A, next, curStep + 1, steps);
		}

	}

	// 从前向后dfs遍历 TLE
	private int jump1(int[] A, int s) {
		if (s >= A.length - 1)
			return 0;
		int len = A[s];
		int minStep = A.length;

		while (len > 0) {
			int step = jump1(A, s + len);
			if (step < minStep)
				minStep = step;
			len--;
		}
		return minStep + 1;
	}

	public static void main(String[] args) {
		Solution t = new Solution();
		System.out.println(t.jump(new int[] { 0, 5, 1, 4, 3 }));
	}
}

