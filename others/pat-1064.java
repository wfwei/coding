import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	static int findMid(int arr[], int s, int e) {
		int count = e - s + 1;
		
		if(count==1)
			return s;
		if(count==2)
			return e;
		
		int fullDepth = (int)(Math.log(count)/Math.log(2));
		int fullCount = (int)Math.pow(2, fullDepth)-1;
		int remaider = count - fullCount;
		int remainderLeft = remaider > ((int) Math.pow(2, fullDepth-1))?((int) Math.pow(2, fullDepth-1)):remaider;
		int mid = s + remainderLeft + fullCount/2;
		return mid;
		
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder res = new StringBuilder();
		int N = sc.nextInt();
		int[] arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		Queue<Integer> workq = new LinkedList<Integer>();
		workq.add(0);
		workq.add(N - 1);
		while (workq.size() > 0) {
			int s = workq.poll();
			int e = workq.poll();
			int mid = findMid(arr, s, e);
			res.append(arr[mid]).append(" ");
			if (s < mid) {
				workq.add(s);
				workq.add(mid - 1);
			}
			if (mid < e) {
				workq.add(mid + 1);
				workq.add(e);
			}
		}
		res.setLength(res.length() - 1);
		System.out.println(res.toString());
	}

}
