public class Test {

	public int firstMissingPositive(int[] A) {
		int MAX = Integer.MAX_VALUE >> 3 + 1;
		if (MAX > A.length + 1)
			MAX = A.length + 1;
		java.util.BitSet s = new java.util.BitSet(MAX);
		for (int a : A) {
			if (a > 0 && a <= MAX)
				s.set(a);
		}
		return s.nextClearBit(1);
	}

    public static void main(String[] args) {
		Test t = new Test();
		System.out.println(t.firstMissingPositive(new int[] { 1, 2, 4, 5 }));
    }
}
