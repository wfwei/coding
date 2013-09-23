import java.util.HashMap;

public class Trie {

	static class Node {
		int count;
		HashMap<Character, Node> children;
		public String toString(){
			return String.format("{count:%s, children:%s}", count, children);
		}
	}

	public Node buildTrie(String[] strs) {
		Node root = new Node();
		for (String str : strs) {
			Node cur = root;
			for (int i = 0; i < str.length(); i++) {
				if (cur.children == null) {
					cur.children = new HashMap<Character, Node>();
				}
				if (!cur.children.containsKey(str.charAt(i))) {
					cur.children.put(str.charAt(i), new Node());
				}
				cur = cur.children.get(str.charAt(i));
				cur.count ++;
			}
		}
		return root;
	}

	public String searchTrie(Node root, String str) {
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			sb.append(c);
			if (!root.children.containsKey(c) || root.count<=1) {
				break;
			}else
				root = root.children.get(c);
		}
		return sb.toString();
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Trie trie = new Trie();
		String[] strs = new String[] { "ebcd", "abdc", "acde" };
		Node trieRoot = trie.buildTrie(strs);
		for (String str : strs) {
			System.out.println(trie.searchTrie(trieRoot, str));
		}
	}

}
