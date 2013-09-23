
import java.util.Stack;

public class Solution {

	static class A {
		int start, end, height, area;

		public A(int s, int e, int height) {
			this.start = s;
			this.end = e;
			this.height = height;
			this.area = height * (e - s + 1);
		}

		public String toString() {
			return String.format("{%s, %s, %s, %s}", start, end, height, area);
		}
	}

	// TLE
	public int largestRectangleArea(int[] height) {

		Stack<A> astack = new Stack<A>();
		int maxArea = 0;

		for (int i = 0; i < height.length; i++) {
			if (astack.empty()) {
				astack.push(new A(0, i, height[i]));
			} else {
				A top = astack.peek();
				// remove all that higher or equal than current height
				while (!astack.empty() && astack.peek().height >= height[i]) {
					top = astack.pop();
				}

				// update all that lower than current height
				// 这里是性能瓶颈？当直方图是递增时，复杂度是O(n^2)
				for (A a : astack) {
					a.area += a.height;
					if (a.area > maxArea)
						maxArea = a.area;
				}

				// push new one
				int start = top.height < height[i] ? i : top.start;
				astack.push(new A(start, i, height[i]));

			}
			if (astack.peek().area > maxArea)
				maxArea = astack.peek().area;
		}
		return maxArea;
	}

	public static void main(String args[]) {
		Solution sol = new Solution();
		int[] height2 = { 3, 2, 4, 3, 4 };
		System.out.format("%d == %d\n", sol.largestRectangleArea(height2), 10);
		int[] height1 = { 2, 1, 5, 6, 2, 3 };
		System.out.format("%d == %d\n", sol.largestRectangleArea(height1), 10);
		int[] height = { 1, 1, 1, 1 };
		System.out.format("%d == %d\n", sol.largestRectangleArea(height), 4);
		int[] height3 = { 1, 1, 1, 1 };
		System.out.format("%d == %d\n", sol.largestRectangleArea(height3), 4);
	}
}
