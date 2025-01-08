#include <stdio.h>
#include <stdlib.h>
#define FILE_LENGTH 8112

int min(int side1, int side2, int side3) {
  if (side1 <= side2 && side1 <= side3)
    return side1;
  else if (side2 <= side1 && side2 <= side3)
    return side2;
  return side3;
}

int surfaceArea(int length, int width, int height) {
  int side1 = (length * width);
  int side2 = (width * height);
  int side3 = (height * length);

  int minSide = min(side1, side2, side3);
  return (2 * side1 + 2 * side2 + 2 * side3) + minSide;
}

int main() {
  FILE *f = fopen("1.txt", "r");
  char *line = NULL;
  size_t len;
  ssize_t read;
  int l, w, h;
  int ret = 0;

  while ((read = getline(&line, &len, f)) != -1) {
    sscanf(line, "%dx%dx%d", &l, &w, &h);
    ret += surfaceArea(l, w, h);
  }
  printf("%d\n", ret);
  free(line);
  free(f);
}
