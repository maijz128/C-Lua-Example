#include <stdio.h>
// 你需要include这几个lua头文件
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "c_call_lua.h"

lua_State* L;

int luaAdd(int x, int y)
{
    int sum;
    /*函数名*/
    lua_getglobal(L,"add");
    /*参数入栈*/
    lua_pushnumber(L, x);
    /*参数入栈*/
    lua_pushnumber(L, y);
    /*开始调用函数，有2个参数，1个返回值*/
    lua_call(L, 2, 1);
    /*取出返回值*/
    sum = (int)lua_tonumber(L, -1);
    /*清除返回值的栈*/
    lua_pop(L,1);
    return sum;
}

void cCallLua()
{
    int sum;
    L = luaL_newstate();  /* 创建lua状态机 */
    luaL_openlibs(L);   /* 打开Lua状态机中所有Lua标准库 */
    /*加载lua脚本*/
    luaL_dofile(L, "add.lua");
    /*调用C函数，这个里面会调用lua函数*/
    sum = luaAdd(99, 100);
    printf("The sum is %d \n",sum);
    /*清除Lua*/
    lua_close(L);
}
