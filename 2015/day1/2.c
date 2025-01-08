#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_LENGTH 7000
#define INFINITY 1000000

int solution(char *input) {
  int sum = 0;
  int pos = INFINITY;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == '(') {
      sum += 1;
    } else if (input[i] == ')') {
      sum -= 1;
    }

    if (sum == -1) {
      pos = i + 1;
      break;
    }
  }
  if (pos == INFINITY)
    return -99;
  return pos;
}

int main() {
  FILE *f = fopen("2.txt", "r");
  char *input = malloc(sizeof(char) * FILE_LENGTH);
  fgets(input, FILE_LENGTH, f);
  printf("%s\n", input);
  int floor = solution(input);
  printf("%d\n", floor);
  free(input);
  free(f);

  return 0;
}
