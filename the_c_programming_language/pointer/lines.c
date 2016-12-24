#include <stdio.h>
#include <string.h>
#include "lines.h"


int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getLine(line, MAXLEN)) > 0) {
    if (nlines >= maxlines) {
      return -1;
    } else {
      line[len] = '\0';
      strcpy(lineptr[nlines++], line);
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines) {
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

int getLine(char s[], int lim) {
  int c, i = 0;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  return i;
}
