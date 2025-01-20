// # DAY01 part 1
// includes the standard input/output library
#include <stdio.h>
#define ARENA_IMPLEMENTATION
#include <arena.h>

// Day01 will take a file called Day01Input.txt and display a count of the
// number of characters.

// here are some static variables and structs we may like to use
static Arena default_arena = {0};
static Arena *context_arena = &default_arena;

void *context_alloc(size_t size) {
  assert(context_arena);
  return arena_alloc(context_arena, size);
}

int main(int argc, char const *argv[]) {
  // sanity check the command arguments
  if (argc != 2) {
    printf("Usage: Day01 <filename>\n");
    return 1;
  } else {
    // open the input file to count the characters
    int count = 0;
    int floor = 0;
    int basementchar = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
      printf("Failed to open file: %s\n", argv[1]);
      return 1;
    } else {
      // ask operating system how big the file is
      fseek(fp, 0, SEEK_END);
      size_t seekcount = ftell(fp);
      fseek(fp, 0, SEEK_SET);
      // allocate a context arena based on the cast to size_t of count
      context_alloc((size_t)seekcount);
      char *buffer = context_alloc(seekcount * 2);
      while (fgets(buffer, seekcount, fp) != NULL) {
        count += strlen(buffer);
      }
      printf("Read file: %s os reported %zd bytes with %d characters.\n",
             argv[1], seekcount, count);

      // using the buffer assess each character and update the floor value, also
      // print up or down to a new line
      for (int i = 0; i < count; i++) {
        if (buffer[i] == '(') {
          floor += 1;
          printf("up-");
        } else if (buffer[i] == ')') {
          floor -= 1;
          printf("down-");
        }
        if (floor == 0) {
          printf("\n");
        }
        if (basementchar == 0 && floor < 0) {
          basementchar = i;
        }
      }
    }
    printf("\nFloor: %d\nBasement: %d\n", floor, basementchar);
    // rewind the file pointer to beginning
    fseek(fp, 0, SEEK_SET);
    fclose(fp);
  }

  return 0;
}
