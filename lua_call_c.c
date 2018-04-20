#include <stdio.h>
#include <string.h>
// ����Ҫinclude�⼸��luaͷ�ļ�
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "lua_call_c.h"

static int l_SayHello(lua_State *L)
{
    const char *d = luaL_checkstring(L, 1);//��ȡ�������ַ�������
    int len = strlen(d);
    char str[100] = "hello ";
    strcat(str, d);
    lua_pushstring(L, str);  // ���ظ�lua��ֵѹջ
    return 1;
}

void luaCallC()
{
    lua_State *L = luaL_newstate();  // ����lua״̬��
    luaL_openlibs(L);   // ��Lua״̬��������Lua��׼��
    lua_register(L, "SayHello", l_SayHello);// ע��C������lua

    const char* testfunc = "print(SayHello('Lua!'))";// lua�е���c����
    if(luaL_dostring(L, testfunc))    // ִ��Lua���
        printf("Failed to invoke.\n");

    // ���Lua
    lua_close(L);
}
