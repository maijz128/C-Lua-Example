#include <stdio.h>
#include <string.h>
// 你需要include这几个lua头文件
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "lua_call_c.h"

static int l_SayHello(lua_State *L)
{
    const char *d = luaL_checkstring(L, 1);//获取参数，字符串类型
    int len = strlen(d);
    char str[100] = "hello ";
    strcat(str, d);
    lua_pushstring(L, str);  // 返回给lua的值压栈
    return 1;
}

void luaCallC()
{
    lua_State *L = luaL_newstate();  // 创建lua状态机
    luaL_openlibs(L);   // 打开Lua状态机中所有Lua标准库
    lua_register(L, "SayHello", l_SayHello);// 注册C函数到lua

    const char* testfunc = "print(SayHello('Lua!'))";// lua中调用c函数
    if(luaL_dostring(L, testfunc))    // 执行Lua命令。
        printf("Failed to invoke.\n");

    // 清除Lua
    lua_close(L);
}
