public class SortBySign {
	
	private int findFirstPos(int[] arr, int s){
		while(s<arr.length && arr[s]<0)
			s ++;
		return s;
	}
	
	private int findFirstNeg(int[] arr, int s){
		while(s<arr.length && arr[s]>=0)
			s ++;
		return s;
	}
	
	private void reverse(int[] arr, int s, int e){
		while(s<e){
			int tmp = arr[s];
			arr[s] = arr[e];
			arr[e] = tmp;
			s++; e--;
		}
	}
	
	public void sortBySign(int[] arr, int s , int e){
		
		while(s<e){
			int reverse = 1;
			for(int i=s; i<=e; ){
				
				int firPos = findFirstPos(arr, i);
				int firNeg = findFirstNeg(arr, firPos);
				int secPos = findFirstPos(arr, firNeg);
				
				if(firNeg<e && reverse>0){
					reverse(arr, firPos, firNeg-1);
					reverse(arr, firNeg, secPos-1);
					reverse(arr, firPos, secPos-1);
				}
				
				if(i==s){
					s += secPos - firNeg;
				}
				
				if(secPos>=e){
					e -= firNeg - firPos;
				}
				
				reverse = - reverse;
				i = secPos;
			}
		}
	}

	public static void main(String[] args) {
        int[] arr = {1,2,-3,-4,3,5,-2,-1};
        new SortBySign().sortBySign(arr, 0, arr.length-1);
        for(int val:arr){
            System.out.println(val);
        }
	}
}
