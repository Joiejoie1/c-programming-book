#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TABLENGTH 4
#define MAXTABS 20

#define DISABLED 0
#define ENABLED 1

/* 
 * Modify the programs entab and detab from chapter 1 to 
 * accept a list of tabstop_markers as arguments. Use the default
 * tab settings if there no arguments.
 */

int getaline(char s[], int limit);
void entab(char s[], int strlen, int[]);
void detab(char s[], int str_len);
void add_tabstop_markers(int tabstop_markers[], char *tab_args[]);

int tab_count;
int custom_tabstops_enabled;

int main(int argc, char *argv[]) {
  int tabstop_markers[MAXTABS];
  int len;
  char line[MAXLINE];

  if (argc > 1) {
    tab_count = argc >= MAXTABS ? MAXTABS : argc - 1;
    custom_tabstops_enabled = ENABLED;
    add_tabstop_markers(tabstop_markers, argv);

  } else {
    custom_tabstops_enabled = DISABLED;
  }

  while ((len = getaline(line, MAXLINE)) != 0) {
    entab(line, len, tabstop_markers);
    printf("%s", line);
  }
}

void add_tabstop_markers(int tabstop_markers[], char *tab_args[]) {
  for (int i = 0; i < tab_count; i++) 
    tabstop_markers[i] = atoi(tab_args[i+1]); // plus one as first arg is program name
}

int getaline(char s[], int limit) {
  int i, c;

  for(i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void entab(char s[], int strlen, int tabstop_markers[]) {
  char scratch[MAXLINE];
  int scratch_i = 0;
  int space_count;
  int search_idx;
  int column = 0;
  int tab_idx = 0;
  int tab_length;
  char c;

  for(int i = 0; i <= strlen; ++i) {
    c = s[i];

    switch (c) {
      case ' ':
        search_idx = i+1;
        space_count = 1;

        if (custom_tabstops_enabled && tab_idx < tab_count) {
          tab_length = tabstop_markers[tab_idx++] - column;
        } else {
          tab_length = TABLENGTH;
        }

        for(int j = 1; j < TABLENGTH && search_idx <= strlen && s[search_idx] == ' '; ++j) {
          ++space_count;
          ++search_idx;
        }

        if (space_count == TABLENGTH) {
          i = search_idx-1;
          for (int k = 0; k < tab_length; k++)
            scratch[scratch_i++] = '%'; // use % to make tabs easier to see on the output
        } else {
          if (tabstop_markers[tab_idx] <= column)
            tab_idx++;
          scratch[scratch_i] = c;
        }

        ++scratch_i;
        break;
      case '\n':
        tab_idx = 0;
        column = 0;
        scratch[scratch_i] = c;
        ++scratch_i;
        break;
      default:
        scratch[scratch_i] = c;
        ++scratch_i;

    }

    column++;
  }

  for(int i = 0; i <= scratch_i; ++i)
    s[i] = scratch[i];
}

void detab(char s[], int str_len) {
  int i;
  int workspace_idx;
  char workspace[MAXLINE];

  for(i = 0, workspace_idx = 0; i <= str_len; ++i) {
    if(s[i] == '\t') {
      for(int j = 0; j < TABLENGTH; ++j) {
        workspace[workspace_idx] = ' ';
        ++workspace_idx;
      }

    } else {
      workspace[workspace_idx] = s[i];
      ++workspace_idx;
    }
  }
  
  for(i = 0; i <= workspace_idx; ++i)
    s[i] = workspace[i];
}
