#include <iostream>
#include <string>

using namespace std;

// input:(()()) return 6
int longestValidParentheses(string s){
  int available=0, result=0;
  int i;
  for(i=0; i<s.length(); i++){
    s[i];
    if(s[i]=='(')
      available ++;
    else{
      if(available > 0){
        available --;
        result ++;
      }
    }
  }
  /*
  char *c = s;
  while(*c != '\0'){
    if(*c=='('){
      available ++;
    }else{
      if(available>0){
        available --;
        result ++;
      }
    }
    c++;
  }
  */
  return result + result;
}



int main(){
  //printf("%d\n", longestValidParentheses("()())"));
 cout << longestValidParentheses("((()))") << "==3"; 
}
