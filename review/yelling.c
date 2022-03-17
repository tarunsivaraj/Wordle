#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
  // You're going to have to use argc to decide whether to open up a file, or to
  // read from stdin.
  // If you haven't seen them before, you will likely want to use the functions
  // `fgetc()` and `fputc()`.
//  char str[1024];
  if (argc >= 2) {
    FILE *infile = fopen(argv[1], "r");
    if (infile == 0) {
      printf( "error\n" );
    } else{
//      char count;
      int x;
      while((x = fgetc(infile)) != EOF ) {
        putchar(toupper(x));
//        if(x >= 'a' && x <= 'z'){
//            count -= 32;
//            printf("%c", count);
//        }else{
//        printf("%c", x);
//        }
      }
    }
    fclose(infile);
  }
  else if(argc == 1) {
    char str[1024];
//    char countt;
    printf( "Enter a word : ");
//    scanf("%s", str);
//    printf("%s\n", str);
    while(fgets(str, 1024, stdin) != NULL) {
      for(size_t x = 0; str[x] != '\0'; x++) {
        char letter = toupper(str[x]);
        printf("%c", letter);
      }
    }
//    for(int a = 0; str[a] != '\0'; a++) {
//      if(str[a] >= 'a' && str[a] <= 'z') {
//         countt -= 32;
//         printf("%c", countt);
//      }else{
//        printf("%c", str[a]);
      }
      return 0;
    }
  
  

