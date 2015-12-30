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

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#define DEFAULT_LUA_WORKBENCH "../lua_workbench"

int main(int argc, char* argv[]) {
	lua_State *L;
	lua_State *LT;

	L = luaL_newstate();
	printf("%d\n*\n", LUA_TTHREAD);

	lua_newthread(L);
	printf("%d\n", lua_type(L, -1));

	LT = lua_tothread(L, -1);
	printf("%d\n", lua_type(LT, -1));

	lua_close(L);

	return 0;
}
