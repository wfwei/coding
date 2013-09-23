public int[] plusOne(int[] digits) {
    // Start typing your Java solution below
    // DO NOT write main() function
    int over = 1;
    for(int i=digits.length-1; i>=0&&over==1; i--){
        if(digits[i]==9)
            digits[i] = 0;
        else{
            digits[i]+=1;
            over = 0;
        }
    }
    if(over == 1){
        int[] nres = new int[digits.length+1];
        nres[0]=1;
        return nres;
    }else
        return digits;
}
