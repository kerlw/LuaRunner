/*
 * engine.c
 *
 *  Created on: 2016.12.31
 *      Author: kerlw
 */

#include "engine.h"

#include <stdlib.h>

#include "lualib.h"
#include "lauxlib.h"

lua_proc* createLuaProc() {
	lua_State *state = luaL_newstate();
	lua_proc *ret = NULL;
	if (state) {
		luaL_openlibs(state);
		ret = (lua_proc*) malloc(sizeof(lua_proc));
		ret->state = state;
	}

	return ret;
}

void cleanLuaProc(lua_proc **proc) {
	if (*proc) {
		if ((*proc)->state)
			lua_close((*proc)->state);
		free(*proc);
		*proc = NULL;
	}
}

int executeLuaFile(lua_proc *proc, const char* path) {
	if (proc && proc->state && path)
		return luaL_dofile(proc->state, path);
	return -1;
}
