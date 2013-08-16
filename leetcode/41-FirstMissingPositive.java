public class Test {

    public int firstMissingPositive(int[] A) {
		int MAX = 1000000;
		java.util.BitSet s = new java.util.BitSet(MAX);
		for (int a : A) {
			if(a>0)
				s.set(a);
		}
		return s.nextClearBit(1);
    }

    public static void main(String[] args) {
		Test t = new Test();
		System.out.println(t.firstMissingPositive(new int[] { 1, 2, 4, 5 }));
    }
}