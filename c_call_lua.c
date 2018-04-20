#include <stdio.h>
// ����Ҫinclude�⼸��luaͷ�ļ�
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "c_call_lua.h"

lua_State* L;

int luaAdd(int x, int y)
{
    int sum;
    /*������*/
    lua_getglobal(L,"add");
    /*������ջ*/
    lua_pushnumber(L, x);
    /*������ջ*/
    lua_pushnumber(L, y);
    /*��ʼ���ú�������2��������1������ֵ*/
    lua_call(L, 2, 1);
    /*ȡ������ֵ*/
    sum = (int)lua_tonumber(L, -1);
    /*�������ֵ��ջ*/
    lua_pop(L,1);
    return sum;
}

void cCallLua()
{
    int sum;
    L = luaL_newstate();  /* ����lua״̬�� */
    luaL_openlibs(L);   /* ��Lua״̬��������Lua��׼�� */
    /*����lua�ű�*/
    luaL_dofile(L, "add.lua");
    /*����C�����������������lua����*/
    sum = luaAdd(99, 100);
    printf("The sum is %d \n",sum);
    /*���Lua*/
    lua_close(L);
}
