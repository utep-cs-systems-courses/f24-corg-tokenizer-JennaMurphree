#include <stdlib.h>
#include <stdio.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c == ' ' || c == '\t'){
    return 1;
  }
  else{
    return 0;
  }
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */
int non_space_char(char c){
  if(c != ' ' && c != '\t'){
    return 1;
  }
  else{
    return 0;
  }
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  while(*str != 0){
    if(non_space_char(*str)){
      return str;
    }
    str++;
  }
  return 0;
}


/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  while(*token != 0){
    if(space_char(*token)){
      return token;
    }
    token++;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int res = 0;
  while (*str != 0){
    str = token_start(str);
    str = token_terminator(str);
    res++;
  }
  return res;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *strCopy = malloc((1+len)*sizeof(char));
  char *copyP = strCopy;
  for(int i =0; i < len; i++){
    copyP[i] = inStr[i];
  }
  copyP[len] = 0;
  return strCopy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated
 space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  int len = count_tokens(str);
  char **tokens = malloc((1+len)*sizeof(char *));
  char *strCopy = str;
  for(int i = 0; i < len; i++){
    char *start = token_start(strCopy);
    char *end = token_terminator(start);
    short len = end - start;
    tokens[i] = copy_str(start, len);
    strCopy = end;
  }
  tokens[len] = 0;
  return tokens;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  while(*tokens != 0){
    printf(*tokens);
    printf("\n");
    tokens++;
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
