import java.util.ArrayList;
import java.util.Arrays;

public class Test {

    /**
     * ʹ�õݹ鷽��������֮��Ϊ��ֵ����
     * 
     * candidatesΪ����Ϊn�����������飬����ѡȡ�������֣�ÿ�����ֿ����ظ���ʹ���Ϊtarget���ú���������������������б�
     */
    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates,
	    int target) {
	ArrayList<ArrayList<Integer>> results = new ArrayList<ArrayList<Integer>>();
	Arrays.sort(candidates);
	// int[] limits = new int[candidates.length];
	// for (int i = 0; i < candidates.length; i++)
	// limits[i] = target / candidates[i];
	// sumeq1(candidates, limits, 0, target, new ArrayList<Integer>(), results);
	sumeq2(candidates, 0, target, new ArrayList<Integer>(), results);
	return results;
    }

    public ArrayList<ArrayList<Integer>> combinationSum2(int[] candidates,
	    int target) {
	// Start typing your Java solution below
	// DO NOT write main() function
	ArrayList<ArrayList<Integer>> results = new ArrayList<ArrayList<Integer>>();
	Arrays.sort(candidates);
	int[] limits = new int[candidates.length];
	for (int i = 0; i < candidates.length; i++)
	    limits[i] = target / candidates[i];
	sumeq3(candidates, 0, target, new ArrayList<Integer>(), results);
	// remove duplicates in results
	for (int i = 0; i < results.size(); i++) {
	    ArrayList<Integer> cur = results.get(i);
	    for (int j = results.size() - 1; j > i; j--) {
		ArrayList<Integer> pre = results.get(j);
		if (cur.size() == pre.size()) {
		    int k = cur.size() - 1;
		    while (k >= 0) {
			if (cur.get(k) != pre.get(k))
			    break;
			else
			    k--;
		    }
		    if (k < 0)
			results.remove(j);
		}
	    }
	}

	return results;
    }

    // ÿ������ʹ�������
    // ʹ��limits�����¼ÿ�����ֻ���ʹ�õĴ����������˿ռ临�Ӷ�
    private void sumeq1(int[] cans, int[] limits, int s, int target,
	    ArrayList<Integer> list, ArrayList<ArrayList<Integer>> res) {

	for (int i = s; i < cans.length; i++) {
	    if (limits[i] > 0) {
		list.add(cans[i]);
		limits[i] -= 1;
		if (target == cans[i]) {
		    res.add(new ArrayList<Integer>(list));
		} else if (target > cans[i]) {
		    sumeq1(cans, limits, i, target - cans[i], list, res);
		}
		list.remove(list.size() - 1);
		limits[i] += 1;
	    }
	}
    }

    // ÿ�����ֿ���ʹ�������
    private void sumeq2(int[] cans, int s, int target, ArrayList<Integer> list,
	    ArrayList<ArrayList<Integer>> res) {

	for (int i = s; i < cans.length; i++) {
	    list.add(cans[i]);
	    if (cans[i] == target) {
		res.add(new ArrayList<Integer>(list));
	    } else if (cans[i] < target) {
		sumeq2(cans, i, target - cans[i], list, res);
	    } else {
		i = cans.length; // stop search
	    }
	    list.remove(list.size() - 1);
	}
	return;
    }

    // ÿ�����������һ��
    private void sumeq3(int[] cans, int s, int target, ArrayList<Integer> list,
	    ArrayList<ArrayList<Integer>> res) {

	for (int i = s; i < cans.length; i++) {
	    list.add(cans[i]);
	    if (cans[i] == target) {
		res.add(new ArrayList<Integer>(list));
	    } else if (cans[i] < target) {
		sumeq3(cans, i + 1, target - cans[i], list, res);
	    } else {
		i = cans.length; // stop search
	    }
	    list.remove(list.size() - 1);
	}
	return;
    }

    public static void main(String[] args) {
	Test t = new Test();
	ArrayList<ArrayList<Integer>> results = t.combinationSum2(new int[] {
		1, 1 }, 1);
	System.out.println(results);
    }
}