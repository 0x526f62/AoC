// nob.c
#define NOB_IMPLEMENTATION
#include "nob.h"

Nob_Proc build_program(const char* source_path, const char* output_path) {
    Nob_Cmd cmd = { 0 };
    nob_cmd_append(&cmd, "cl.exe");
    nob_cmd_append(&cmd, "/nologo", "-IC:\\Users\\robert.orton\\OneDrive\\AoC\\nob", "-IC:\\Users\\robert.orton\\OneDrive\\AoC\\include");
    nob_cmd_append(&cmd, "/Fe:", output_path);
    nob_cmd_append(&cmd, source_path);
    return nob_cmd_run_async(cmd);
}

int main(int argc, char** argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);
    nob_set_current_dir("C:\\Users\\robert.orton\\OneDrive\\AoC\\nob");
    if (!nob_mkdir_if_not_exists(".\\out\\nob\\")) return 1;
    Nob_Procs procs = { 0 };
    nob_da_append(&procs, build_program(".\\2015\\Day01.c", ".\\out\\nob\\Day01.exe"));
    nob_da_append(&procs, build_program(".\\2015\\Day02.c", ".\\out\\nob\\Day02.exe"));
    nob_da_append(&procs, build_program(".\\2015\\Day03.c", ".\\out\\nob\\Day03.exe"));
    if (!nob_procs_wait(procs)) return 1;
    return 0;
}