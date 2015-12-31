/*
 * engine.h
 *
 *  Created on: 2016.12.31
 *      Author: kerlw
 */
#ifndef ENGINE_H_
#define ENGINE_H_

#include "lua.h"

struct lua_proc {
	lua_State *state;
};

typedef struct lua_proc lua_proc;

lua_proc* createLuaProc();

void cleanLuaProc(lua_proc **proc);

int executeLuaFile(lua_proc *proc, const char* path);

#endif /* ENGINE_H_ */
