#include <cache.hpp>

int* AllocArray() {
  return new int[ARRAY_SIZE];
}

void FillArray(int *array, int rows) {
  int columns = ARRAY_SIZE / rows;

  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      int currentIndex = j * OFFSET + i;

      if (j + 1 == rows && i + 1 == columns) {
        array[currentIndex] = 0;
        continue;
      }

      if (j + 1 == rows) {
        array[currentIndex] = (i + 1);
        continue;
      }

      array[currentIndex] = (j + 1) * OFFSET + i;
    }
  }
}
