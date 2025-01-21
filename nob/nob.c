// nob.c
#define NOB_IMPLEMENTATION
#include "nob.h"

int main(int argc, char **argv) {
  NOB_GO_REBUILD_URSELF(argc, argv);
  Nob_Cmd cmd = {0};

  nob_cmd_append(
      &cmd, "cl.exe", "/nologo", "-IC:\\Users\\robert.orton\\OneDrive\\AoC\\include","/Fe:nob.exe", "nob.c");
  if (!nob_cmd_run_sync(cmd))
    return 1;
  return 0;
}