#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_LENGTH 8192

enum DIRECTIONS { NORTH = '^', EAST = '>', WEST = '<', SOUTH = 'v' };
enum HOUSE_NUMBER { AT_NORTH = 0, AT_EAST, AT_WEST, AT_SOUTH };

typedef struct GridArea {
  int newHouse;
  int lastHouse;
  int visited;
} GridArea;

int deliveredPresents(char *input) {
  GridArea visited[4];
  for (int i = 0; i < 4; i++)
    visited[i].visited = 0;
  int posX = 0;
  int posY = 0;
  int presentsDelivered = 0;

  /* 2 dim. array
   * [ (1,1),   (1, 2),
   *   (0,0)   (0, 2) ]
   *
   * Track the position and calc by mod 4, if the newElement is equal to the
   * lastElement then im looping in same grid area
   */
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == NORTH) {
      if (!visited[AT_NORTH].visited ||
          visited[i].newHouse != visited[i].lastHouse) {
        presentsDelivered += 1;
      }
    } else if (input[i] == EAST) {
      if (!visited[AT_EAST].visited ||
          visited[i].newHouse != visited[i].lastHouse) {
        presentsDelivered += 1;
      }
    } else if (input[i] == WEST) {
      if (!visited[AT_WEST].visited ||
          visited[i].newHouse != visited[i].lastHouse) {
        presentsDelivered += 1;
      }
    } else {
      if (!visited[AT_SOUTH].visited ||
          visited[i].newHouse != visited[i].lastHouse) {

        presentsDelivered += 1;
      }
    }
  }
  return presentsDelivered;
}
int main() {
  FILE *f = fopen("1.txt", "r");
  char *input = malloc(sizeof(char) * FILE_LENGTH);
  fgets(input, FILE_LENGTH, f);
  int ret = deliveredPresents(input);
  printf("%d\n", ret);
  free(f);
  free(input);
  return 0;
}
