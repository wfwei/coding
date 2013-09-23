public int lengthOfLastWord(String s) {
    // Start typing your Java solution below
    // DO NOT write main() function
    if(s==null || s.length()==0)
        return 0;
    int lasti = s.length()-1;
    while(lasti>=0 && s.charAt(lasti)==' ')
        lasti --;
    int cnt = 0;
    while(lasti>=0 && s.charAt(lasti)!=' ' && (++cnt)>=0)
        lasti --;
    return cnt;
}
