public String addBinary(String a, String b) {
    // Start typing your Java solution below
    // DO NOT write main() function
    int aend=a.length()-1, bend=b.length()-1;
    StringBuilder sum = new StringBuilder();
    int carry=0;
    while(aend>=0 || bend>=0){
        int bsum = carry;
        if(aend>=0)
            bsum += a.charAt(aend) - '0';
        if(bend>=0)
            bsum += b.charAt(bend) - '0';
        
        carry = bsum/2;
        bsum %= 2;
        sum.append((char)(bsum+'0'));
        aend--; bend--;
    }
    if(carry==1)
        sum.append((char)(carry+'0'));
        
    return sum.reverse().toString();
}
