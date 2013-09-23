import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Copy_2_of_Main {

  static class tv implements Comparable<tv>{
		String entry;
		int vg, tg;
		int value;
		public tv(String entry, int vg, int tg){
			this.entry = entry; this.vg = vg; this.tg = tg;
			this.value = calcVal();
		}
		public static int L=60, H=80;
		
		public String toString(){
			return entry;
		}
		
		@Override
		public int compareTo(tv o) {
			if(this.value>o.value)
				return -1;
			else if(this.value<o.value)
				return 1;
			else{
				return this.entry.compareTo(o.entry);
			}
		}
		
		private int calcVal(){
			int value = 0;
			if(vg>=H){
				if(tg>=H)
					value +=400000000;
				else
					value +=300000000;
			}else{
				if(tg<H && vg>=tg){
					value += 200000000;
				}else{
					value +=100000000;
				}
			}
			value += (tg+vg)*1000 + vg;
			return value;
		}
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int N=sc.nextInt();	tv.L=sc.nextInt();tv.H=sc.nextInt();
		ArrayList<tv> list = new ArrayList<tv>();
		sc.nextLine();
		for(int i=0; i<N; i++){
			String entry = sc.nextLine();
			String[] strs = entry.split(" ");
			int vg = Integer.parseInt(strs[1]);
			int tg = Integer.parseInt(strs[2]);
			if(vg>=tv.L && tg>=tv.L){
				list.add(new tv(entry, vg, tg));
			}
		}
		Collections.sort(list);
		System.out.println(list.size());
		for(tv item:list){
			System.out.println(item);
		}
	}

}
