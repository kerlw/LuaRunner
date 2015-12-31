/*
 ============================================================================
 Name        : LuaRunner.c
 Author      : wuke
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include<sys/wait.h>

#include "engine.h"

#define MAIN_LUA_SCRIPT  "lua_workbench/main.lua"

int main(int argc, char* argv[]) {
	int childpid;
	pid_t pid = fork();
	if (pid < 0) {
		printf("create lua execute process failed!\n");
	} else if (pid == 0) {
		lua_proc* proc = createLuaProc();
		if (executeLuaFile(proc, MAIN_LUA_SCRIPT) != 0) {
			perror("execute lua file failed!");
			exit(-1);
		}
		cleanLuaProc(&proc);
		return 0;
	} else {
		wait(&childpid);
	}

	return 0;
}
