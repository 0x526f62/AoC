// Day 2

// # DAY02 part 1
// includes the standard input/output library
#include <stdio.h>
#define ARENA_IMPLEMENTATION
#include <arena.h>

// Day02 will take a file called Day02Input.txt and parse the file to identify 3
// integers on each line separated with x's

// here are some static variables and structs we may like to use
static Arena default_arena = {0};
static Arena *context_arena = &default_arena;

static void *context_alloc(size_t size) {
  assert(context_arena);
  return arena_alloc(context_arena, size);
}

// takes thre pointers to integers and sorts the values by swaping values in
// memory
static void sortThreeInts(int *a, int *b, int *c) {
  int temp = 0;
  if (*a > *b) {
    temp = *a;
    *a = *b;
    *b = temp;
    sortThreeInts(a, b, c);
  }
  if (*b > *c) {
    temp = *b;
    *b = *c;
    *c = temp;
    sortThreeInts(a, b, c);
  }
}
// sort the ints ascending then calculate the area of the cube plus the slack
// room needed.
static int findArea(int a, int b, int c) {
  return 2 * a * b + 2 * b * c + 2 * c * a + a * b;
}

// main program definition, will take a parameter for the file name
int main(int argc, char const *argv[]) {
  // sanity check the command arguments
if (argc != 2) {
    printf("Usage: Day02 <filename>\n");
    return 1;
  } else {
    // open the input file to count the characters
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
      printf("Failed to open file: %s\n", argv[1]);
      return 1;
    } else {
      // ask operating system how big the file is
      fseek(fp, 0, SEEK_END);
      long seekcount = ftell(fp);
      fseek(fp, 0, SEEK_SET);
      // allocate a context arena based on the cast to size_t of count
      char *buffer = context_alloc(seekcount );
      int totalarea = 0;
      int totalribon = 0;
      while (fgets(buffer, seekcount, fp) != NULL) {
        int a = 0;
        int b = 0;
        int c = 0;
        sscanf_s(buffer, "%d x %d x %d", &a, &b, &c);
        sortThreeInts(&a, &b, &c);

        totalarea += 2 * a * b + 2 * b * c + 2 * c * a + a * b;
        totalribon += 2 * a + 2 * b + a * b * c;
        printf("a: %d b: %d c: %d tot: %d Rib: %d\n", a, b, c, totalarea,totalribon);
      }
    }
  }
}
