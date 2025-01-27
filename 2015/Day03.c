// this program will read a file from the provided commandline argument into a
// buffer for processing the buffer will be in an arena.
#include <corecrt.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct {
    FILE* fp;
    size_t seekcount;
} myfile;

static bool filecheck(myfile* fp, int const* argc, char const* argv[]) {
    if (*argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return false;
    }
    fp->fp = fopen(argv[1], "r");
    if (fp->fp == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        return false;
    }
    else {
        fseek(fp->fp, 0, SEEK_END);
        fp->seekcount = ftell(fp->fp);
        fseek(fp->fp, 0, SEEK_SET);
        return true;
    }
}

#define ARENA_IMPLEMENTATION
#include <arena.h>

static Arena default_arena = { 0 };
static Arena* context_arena = &default_arena;
static void* context_alloc(size_t size) {
    assert(context_arena);
    return arena_alloc(context_arena, size);
}

#define NOB_IMPLEMENTATION
#include <nob.h>

typedef struct Buffer Buffer;
struct Buffer {
    Arena* data;
    size_t size;
    size_t capacity;
    size_t* position; 
};


int main(int argc, char const *argv[]) {
  myfile fp ={0};
  
  Buffer buffer = { 0 };
  buffer.data = context_alloc(0);
  buffer.capacity = buffer.data->end - buffer.data->begin;
  buffer.position = buffer.data->end;
  

  if (filecheck(&fp, &argc, argv)) {
    printf("Opened %s  of length %llu \n ", argv[1], fp.seekcount);
    if (fp.seekcount > buffer.size) {
       buffer.data = arena_realloc(buffer.data, buffer.data, buffer.size,fp.seekcount);
    }
   // while (fgets(buffer.data, fp.seekcount, fp.fp) != NULL) {
     //   printf("got data\n");
    //}
    for (int i = 0; i < buffer.size; i++) {
    }

  } else {
    printf("Failed to open file: %s\n", argv[1]);
    return 1;
  }


  return 0;
}
