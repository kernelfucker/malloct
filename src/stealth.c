#include <stdio.h>
#include <string.h>

#include "stealth.h"
#include "config.h"

void init_stealth(void){
}

int hide_file(const char* file){
	return strstr(file, hiddenf) != NULL || strstr(file, secretp) != NULL;
}
