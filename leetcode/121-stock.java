
public class Stock {

    /**
     * Leetcode#121
     */
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(prices==null || prices.length<1)
            return 0;
        int res, min, max;
        min  = max = prices[0];
        res = 0;
        for(int i=1; i<prices.length; i++){
            if(prices[i]>max){
                max = prices[i];
                res = Math.max(max-min, res);
            }else if(prices[i]<min){
                max = min = prices[i];
            }
        }
        return res;
    }


    /**
     * Leetcode#122
     */
    private int findBottom(int[] arr, int s, int e){
        while(s<e && arr[s+1]<=arr[s])
            s++;
        return s;
    }
    private int findTop(int[] arr, int s, int e){
        while(s<e && arr[s+1]>=arr[s])
            s++;
        return s;
    }
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(prices==null || prices.length<1)
            return 0;
        int len=prices.length, sum=0;
        for(int i=0; i<len;){
            int minIdx = findBottom(prices, i, len-1);
            int maxIdx = findTop(prices, minIdx, len-1);
            if(maxIdx>minIdx)
                sum += prices[maxIdx]-prices[minIdx];
            i = maxIdx + 1;
        }
        return sum;
    }


    /**
     * Leetcode#123变种，两次交易，每次交易的买入卖出不限制
     */
    public int maxProfit(int[] prices){
        // Start typing your Java solution below
        // DO NOT write main() function
        return maxProfit1(prices)+maxProfit1(prices);
    }
    private int maxProfit1(int[] prices) {
        if(prices==null || prices.length<1)
            return 0;
        int minIdx=0, maxIdx=0, res=0, resMinIdx=0, resMaxIdx=0;
        for(int i=1; i<prices.length; i++){
            if(prices[i]<prices[minIdx]){
                maxIdx = minIdx = i;
            }else if(prices[i]>prices[maxIdx]){
                maxIdx = i;
                if(prices[maxIdx]-prices[minIdx]>res){
                    res = prices[maxIdx]-prices[minIdx];
                    resMinIdx = minIdx;
                    resMaxIdx = maxIdx;
                }
            }
        }
        if(res>0){
            prices[resMaxIdx] = prices[resMaxIdx-1];
            prices[resMinIdx] = prices[resMinIdx+1];
            if(resMaxIdx-resMinIdx==1){
                if(resMaxIdx<prices.length-1){
                    prices[resMaxIdx] = prices[resMinIdx] = prices[resMaxIdx+1];
                }else if(resMinIdx>0){
                    prices[resMaxIdx] = prices[resMinIdx] = prices[0];
                }
            }
        }
        return res;
    }

    /**
     * Leetcode#213
     */
    public int maxProfit(int[] prices){
        // Start typing your Java solution below
        // DO NOT write main() function
        return maxProfit(prices, 0, prices.length-1, false, 2);
    }
    public int maxProfit(int[] prices, int s, int e, boolean reverse, int count){
        count --;
        if(s>=e)
            return 0;
        
        int minIdx, maxIdx, res=0, resMinIdx=0, resMaxIdx=0;
        if(!reverse){
            minIdx = maxIdx = s;
            for(int i=s+1; i<=e; i++){
                if(prices[i]>prices[maxIdx]){
                    maxIdx = i;
                    if(res<prices[maxIdx]-prices[minIdx]){
                        res = prices[maxIdx]-prices[minIdx];
                        resMaxIdx = maxIdx;
                        resMinIdx = minIdx;
                    }
                }else if(prices[i]<prices[minIdx]){
                    maxIdx = minIdx = i;
                }
            }
        }else{
            minIdx = maxIdx = e;
            for(int i=e-1; i>=s; i--){
                if(prices[i]>prices[maxIdx]){
                    maxIdx = i;
                    if(res < prices[maxIdx]-prices[minIdx]){
                        res = prices[maxIdx]-prices[minIdx];
                        resMaxIdx = maxIdx;
                        resMinIdx = minIdx;
                    }
                }else if(prices[i]<prices[minIdx]){
                    maxIdx = minIdx = i;
                }
            }
        }
        // 这两个判断条件开始都没注意到==!
        if(res > 0 && count>=1){
        	if(reverse){
        		resMinIdx ^= resMaxIdx;
        		resMaxIdx ^= resMinIdx;
        		resMinIdx ^= resMaxIdx;
        	}
	        int secRes = 0;
	        if(resMaxIdx>resMinIdx+2)
	        	secRes = Math.max(secRes, maxProfit(prices, resMinIdx+1, resMaxIdx-1, true, count));
	        if(resMinIdx>s+1)
	        	secRes = Math.max(secRes, maxProfit(prices, s, resMinIdx-1, false, count));
	        if(resMaxIdx+1<e)
	        	secRes = Math.max(secRes, maxProfit(prices, resMaxIdx+1, e, false, count));
	        res += secRes;
        }
        return res;
    }

    /**
     * 这个是别人的方法，比较好～～～
     */
    public int maxProfit2(int[] prices){
		if(prices == null || prices.length<1)
			return 0;
		int res = 0, len = prices.length;
		int[] left = new int[len], right = new int[len];
		int min=prices[0];
		left[0] = 0;
		for(int i=1; i<len; i++){
			if(prices[i]<min)
				min = prices[i];
			left[i] = Math.max(left[i-1], prices[i]-min);
		}
		right[len-1]= 0; int max=prices[len-1];
		for(int i=len-2; i>=0; i--){
			if(prices[i]>max)
				max = prices[i];
			right[i] = Math.max(right[i+1], max-prices[i]);
			res = Math.max(res, right[i]+left[i]);
		}
		return res;
	}

}
