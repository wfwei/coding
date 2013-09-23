public class RotatedArraySearch {
	private static final int OVER = -1;

	/**
	 * Leetcode#81 & #33
	 * 
	 * search 'target' in rotated sorted array 'arr'
	 * if found return the index, else return -1
	 */
	public int search(int[] arr, int target) {
		// Start typing your Java solution below
		// DO NOT write main() function
		return searchVal(arr, 0, arr.length - 1, target);
	}

	private int searchVal(int[] arr, int s, int e, int target) {
		int tarIdx = OVER;
		if (s <= e) {
			int mid = s + (e - s) / 2;
			int midVal = arr[mid];

			if (midVal > target) {
				// '=' make it able to deal with duplicates
				if (arr[e] <= midVal) {
					tarIdx = searchVal(arr, mid + 1, e, target);
				}
				if (tarIdx == OVER)
					tarIdx = searchVal(arr, s, mid - 1, target);
			} else if (midVal < target) {
				// '=' make it able to deal with duplicates
				if (arr[s] >= midVal) {
					tarIdx = searchVal(arr, s, mid - 1, target);
				}
				if (tarIdx == OVER)
					tarIdx = searchVal(arr, mid + 1, e, target);
			} else
				tarIdx = mid;
		}
		return tarIdx;
	}

	/**
	 * search the minimum value is rotated array 'arr' and return it's index
	 */
	public int getMinVal(int[] arr) {
		// Start typing your Java solution below
		// DO NOT write main() function
		return searchMin(arr, 0, arr.length - 1);
	}

	private int searchMin(int[] arr, int s, int e) {
		if (s > e)
			return OVER; // over

		int min = arr[s], minIdx = s;
		if (arr[e] < min) {
			min = arr[e];
			minIdx = e;
		}

		int mid = s + (e - s) / 2;
		int midVal = arr[mid];

		if (midVal < min) {
			min = midVal;
			minIdx = mid;
		}

		int news, newe, newMinIdx;
		if (midVal > arr[s]) {
			// check the right part
			news = mid + 1;
			newe = e - 1;
		} else if (midVal < arr[s] || arr[e] < arr[s]) {
			// check the left part
			news = s + 1;
			newe = mid - 1;
		} else {
			// when midVal == arr[s] and arr[e] >= arr[s]
			// min val may appear both parts
			news = s + 1;
			newe = e - 1;

			// Another solution is:
			// // extra check on the left part
			// news = s + 1; newe = mid - 1;
			// newMinIdx = searchMinIdx(arr, news, newe);
			// if (newMinIdx != OVER && min > arr[newMinIdx]) {
			// min = arr[newMinIdx];
			// minIdx = newMinIdx;
			// }
			// // then check the right part
			// news = mid + 1;
			// newe = e - 1;
		}

		newMinIdx = searchMin(arr, news, newe);
		if (newMinIdx != OVER && min > arr[newMinIdx]) {
			min = arr[newMinIdx];
			minIdx = newMinIdx;
		}

		return minIdx;
	}

	public static void testGetMinVal() {
		RotatedArraySearch s = new RotatedArraySearch();
		int[] arr = { 3, 4, 5, 6, 7, 1, 2 };
		System.out.format("5 == %d \n", s.getMinVal(arr));

		int[] arr1 = { 6, 7, 1, 2, 3, 4, 5 };
		System.out.format("2 == %d \n", s.getMinVal(arr1));

		int[] arr2 = { 1, 2, 3, 4, 5, 6, 7 };
		System.out.format("0 == %d \n", s.getMinVal(arr2));

		int[] arr3 = { 5, 4, 5, 5, 5, 5, 5 };
		System.out.format("1 == %d \n", s.getMinVal(arr3));

		int[] arr4 = { 5, 5, 5, 5, 5, 5, 4, 5, 5 };
		System.out.format("6 == %d \n", s.getMinVal(arr4));

		int[] arr5 = { 5, 5, 5, 5, 5, 5, 5, 5, 5 };
		System.out.format("0 == %d \n", s.getMinVal(arr5));

		int[] arr6 = { 5, 5, 5, 5, 5, 5, 5, 7, 5 };
		System.out.format("0 == %d \n", s.getMinVal(arr6));
	}

	public static void testSearchVal() {
		RotatedArraySearch s = new RotatedArraySearch();

		int[] arr0 = { 1,3,1,1,1};
		System.out.format("1 == %d \n", s.searchVal(arr0,0,arr0.length-1, 3));

		int[] arr = { 3, 4, 5, 6, 7, 1, 2 };
		System.out.format("2 == %d \n", s.searchVal(arr, 0, arr.length-1, 5));

		int[] arr1 = { 6, 7, 1, 2, 3, 4, 5 };
		System.out.format("6 == %d \n", s.searchVal(arr1,0,arr1.length-1, 5));

		int[] arr2 = { 1, 2, 3, 4, 5, 6, 7 };
		System.out.format("4 == %d \n", s.searchVal(arr2,0,arr2.length-1, 5));

		int[] arr3 = { 5, 4, 5, 5, 5, 5, 5 };
		System.out.format("1 == %d \n",
				s.searchVal(arr3, 0, arr3.length - 1, 4));

		int[] arr4 = { 5, 5, 5, 5, 5, 5, 4, 5, 5 };
		System.out.format("6 == %d \n",
				s.searchVal(arr4, 0, arr4.length - 1, 4));

		int[] arr5 = { 5, 5, 5, 5, 5, 5, 5, 5, 5 };
		System.out.format("-1 == %d \n",
				s.searchVal(arr5, 0, arr5.length - 1, 4));

	}

	public static void main(String args[]) {
		testGetMinVal();
		testSearchVal();
	}
}
