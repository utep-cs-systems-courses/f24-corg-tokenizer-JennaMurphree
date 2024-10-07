#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{

  puts("Welcome to Tokenizer.  Would you like to tokenize a string or see history?");
  while(1){//infinite while loop
    fputs("For tokenize press t, for history press h, to exit press q. > ", stdout);
    fflush(stdout);/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)     /* terminate on end-of-file */
      goto done;
    // Given the user answer, select which method to call
    switch (c) {
    case 't': //tokenize
      puts("Please input string:");
      fputs(">",stdout);
      int s;
      while ((s=getchar())=='\n'); //skip any new lines
      while(1){// infinite loop
	putchar(s);
	if(s == '\n'){
	  break; //exit out of loop when you encounter a new line symbol
	}
	s = getchar();
      }
      break;
      
    case 'h':
      puts("Which string from history would you like to tokenize?\n");
      break;

    case 'q':
      puts("Bye!");
      goto done; /* terminate */

    case '\n':
      break;

    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }
 done:
  return 0;

}
