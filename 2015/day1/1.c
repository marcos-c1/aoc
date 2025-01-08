#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(char *input) {
  int sum = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == '(') {
      sum += 1;
    } else if (input[i] == ')') {
      sum -= 1;
    }
  }
  return sum;
}

int main() {
  FILE *f = fopen("1.txt", "r");
  char *input = malloc(sizeof(char) * 7000);
  fgets(input, 100000, f);
  printf("%s\n", input);
  int floor = solution(input);
  printf("%d\n", floor);
  free(input);
  free(f);
  return 0;
}
