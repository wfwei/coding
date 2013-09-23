import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Copy_3_of_Main {

  static String sim(HashSet<Integer> sa, HashSet<Integer> sb){
		HashSet<Integer> nc = new HashSet<Integer>();
		HashSet<Integer> nt = new HashSet<Integer>();
		nc.addAll(sa);nc.removeAll(sb);
		nt.addAll(sa);nt.addAll(sb);
		double sim = 100.0 * (sa.size()-nc.size()) / nt.size();
		return String.format("%.1f", sim) + "%";
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<HashSet<Integer>> list = new ArrayList<HashSet<Integer>>();
		int N=sc.nextInt();
		for(int i=0; i<N; i++){
			int M = sc.nextInt();
			HashSet<Integer> set = new HashSet<Integer>();
			for(int j=0; j<M; j++){
				set.add(sc.nextInt());
			}
			list.add(set);
		}
		int K = sc.nextInt();
		for(int i=0; i<K; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			System.out.println(sim(list.get(a-1), list.get(b-1)));
		}
	}
}
