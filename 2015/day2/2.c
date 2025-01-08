#include <stdio.h>
#include <stdlib.h>
#define FILE_LENGTH 8112

int max(int side1, int side2, int side3) {
  if (side1 >= side2 && side1 >= side3)
    return 1;
  else if (side2 >= side1 && side2 >= side3)
    return 2;
  return 3;
}

int smallestDistance(int l, int w, int h) {
  int maxSide = max(l, w, h);
  int ribbon = -1;
  if (maxSide == 1) {
    ribbon = (2 * w) + (2 * h);
  } else if (maxSide == 2) {
    ribbon = (2 * l) + (2 * h);
  } else {
    ribbon = (2 * l) + (2 * w);
  }
  ribbon += l * w * h;
  return ribbon;
}

int main() {
  FILE *f = fopen("2.txt", "r");
  char *line = NULL;
  size_t len;
  ssize_t read;
  int l, w, h;
  int ret = 0;

  while ((read = getline(&line, &len, f)) != -1) {
    sscanf(line, "%dx%dx%d", &l, &w, &h);
    ret += smallestDistance(l, w, h);
  }
  printf("%d\n", ret);
  free(line);
  free(f);
}
