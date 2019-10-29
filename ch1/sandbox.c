#include <stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0

/* write a program that removes trailing blanks and tabs
 * from each line of input, and to delete entirely blank lines
 */

// prototype
int getLine(char s[], int lim);
 
int main(void){
    int len;
    char line[MAXLINE];
 

    while((len = getLine(line, MAXLINE)) > 0) {
        printf("%s", line);
    }  
}

int getLine(char s[], int lim) {
    int c, i;
    int state = OUT;
    
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c == ' ' || c == '\t') {
            if (state == OUT) {
                s[i] = c;
                state = IN;
            }
        }
        else {
            s[i] = c;
            state = OUT;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
