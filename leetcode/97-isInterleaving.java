public boolean isInterleave(String s1, String s2, String s3) {
    // Start typing your Java solution below
    // DO NOT write main() function
    if(s1.length()+s2.length()==s3.length() && isInterleave(s1, 0, s2, 0, s3, 0))
        return true;
    else
        return false;
}

// TLE
private boolean isInterleave(String s1, int st1, String s2, int st2, String s3, int st3){
    if(st3>=s3.length())
        return true;
    if(st1<s1.length() && s1.charAt(st1)==s3.charAt(st3) 
        && isInterleave(s1, st1+1, s2, st2, s3, st3+1))
        return true;
    if(st2<s2.length() && s2.charAt(st2)==s3.charAt(st3) 
        && isInterleave(s1, st1, s2, st2+1,s3, st3+1))
        return true;
    return false;
}

public boolean isInterleave(String s1, String s2, String s3) {
    // Start typing your Java solution below
    // DO NOT write main() function
    if(s1.length()+s2.length()==s3.length() && isInterleave(s1, s1.length()-1, s2, s2.length()-1, s3, s3.length()-1))
        return true;
    else
        return false;
}


private boolean isInterleave(String s1, int e1, String s2, int e2, String s3, int e3){
    if(e3<0)
        return true;
    if(e1>=0 && s1.charAt(e1)==s3.charAt(e3) && isInterleave(s1, e1-1, s2, e2, s3, e3-1))
        return true;
    if(e2>=0 && s2.charAt(e2)==s3.charAt(e3) && isInterleave(s1, e1, s2, e2-1, s3, e3-1))
        return true;
    return false;
}
