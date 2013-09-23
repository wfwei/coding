import java.util.LinkedList;
import java.util.Queue;

public class SurroundedRegions {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] strs = {
				"XOOOOOOOOOOOOOOOOOOO",
				"OXOOOOXOOOOOOOOOOOXX",
				"OOOOOOOOXOOOOOOOOOOX",
				"OOXOOOOOOOOOOOOOOOXO",
				"OOOOOXOOOOXOOOOOXOOX",
				"XOOOXOOOOOXOXOXOXOXO",
				"OOOOXOOXOOOOOXOOXOOO",
				"XOOOXXXOXOOOOXXOXOOO",
				"OOOOOXXXXOOOOXOOXOOO",
				"XOOOOXOOOOOOXXOOXOOX",
				"OOOOOOOOOOXOOXOOOXOX",
				"OOOOXOXOOXXOOOOOXOOO",
				"XXOOOOOXOOOOOOOOOOOO",
				"OXOXOOOXOXOOOXOXOXOO",
				"OOXOOOOOOOXOOOOOXOXO",
				"XXOOOOOOOOXOXXOOOXOO",
				"OOXOOOOOOOXOOXOXOXOO",
				"OOOXOOOOOXXXOOXOOOXO",
				"OOOOOOOOOOOOOOOOOOOO",
				"XOOOOXOOOXXOOXOXOXOO"};
		char[][] board = new char[strs.length][strs[0].length()];
		for(int i=0; i<strs.length; i++){
			for(int j=0; j<strs[i].length(); j++)
				board[i][j] = strs[i].charAt(j);
		}
		SurroundedRegions sol = new SurroundedRegions();
		long st = System.currentTimeMillis();
		sol.solve(board);
		st = System.currentTimeMillis()-st;
		System.out.println(st +" ms");
	}
	
	public void solve(char[][] board) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(board==null || board.length<3 || board[0].length<3)
            return;
        int rowcnt=board.length, colcnt=board[0].length;
        for(int i=0; i<rowcnt; i++){
            if(board[i][0]=='O')
                connect(board, i, 0);
            if(board[i][colcnt-1]=='O')
                connect(board, i, colcnt-1);
        }
        for(int j=0; j<colcnt; j++){
            if(board[0][j]=='O')
                connect(board, 0, j);
            if(board[rowcnt-1][j]=='O')
                connect(board, rowcnt-1, j);
        }
        for(int i=0; i<rowcnt; i++){
            for(int j=0; j<colcnt; j++){
                if(board[i][j]=='M')
                    board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
    // 递归 超时
    private void connect2(char[][] board, int i, int j){
        board[i][j]='M';
        
        if(i<board.length-1 && board[i+1][j]=='O')
            connect(board, i+1, j);
        if(i>0 && board[i-1][j]=='O')
            connect(board, i-1, j);
        if(j<board[0].length-1 && board[i][j+1]=='O')
            connect(board, i, j+1);
        if(j>0&&board[i][j-1]=='O')
            connect(board, i, j-1);
    }
    // 使用队列，超时！！！
    private void connect(char[][] board, int i, int j){
        
        Queue<Integer> qu = new LinkedList<Integer>();
        int colcnt=board[0].length;
        int rowcnt=board.length;
        
        qu.add(i*colcnt+j);
        
        while(!qu.isEmpty()){
            int row = qu.poll();
            int col = row%colcnt;
            row = row/colcnt;
            
            board[row][col]='M';
            
            if(row<rowcnt-1&&board[row+1][col]=='O')
                qu.add((row+1)*colcnt+col);
            if(row>0 && board[row-1][col]=='O')
                qu.add((row-1)*colcnt+col);
            if(col<colcnt-1&&board[row][col+1]=='O')
                qu.add(row*colcnt+col+1);
            if(col>0 && board[row][col-1]=='O')
                qu.add(row*colcnt+col-1);
            
        }

    }
    // others just pass...
    public void solve_others(char[][] board) {
        if(board == null || board.length == 0) return;
        int m = board.length, n = board[0].length;
        for(int i = 0; i < n; i++) {bfs(0, i, board); bfs(m - 1, i, board);}
        for(int j = 1; j < m- 1; j++) {bfs(j, 0, board); bfs(j, n - 1, board);}
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '+') board[i][j] = 'O';
    }
    public void bfs(int i, int j, char[][] board){
        Queue<Integer> q = new LinkedList<Integer>(); 
        visit(i, j, q, board);
        while(!q.isEmpty()){
            int cur = q.poll();
            int t = cur / board[0].length;
            int s = cur % board[0].length;
            visit(t - 1, s, q, board);
            visit(t, s - 1, q, board);
            visit(t + 1, s, q, board);
            visit(t, s + 1, q, board);
        }
    }
    public void visit(int i, int j, Queue<Integer> q, char[][] board){
        int m = board.length, n = board[0].length;
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        board[i][j] = '+';
        q.offer(i * n + j);
    }

}
