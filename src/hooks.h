#ifndef hooks_h
#define hooks_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <dlfcn.h>
#include <dirent.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>

typedef void*(*malloc_t)(size_t);
typedef void(*free_t)(void*);
typedef DIR*(*opendir_t)(const char*);
typedef struct dirent*(*readdir_t)(DIR*);
typedef int(*open_t)(const char*, int, ...);
typedef int(*connect_t)(int, const struct sockaddr*, socklen_t);
typedef pid_t(*fork_t)(void);

extern malloc_t o_malloc;
extern free_t o_free;
extern opendir_t o_opendir;
extern readdir_t o_readdir;
extern open_t o_open;
extern connect_t o_connect;
extern fork_t o_fork;

void init_hooks(void);

#endif
