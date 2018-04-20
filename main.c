#include <stdio.h>
#include <stdlib.h>

#include "c_call_lua.h"
#include "lua_call_c.h"


int main()
{
//    printf("Hello world!\n");
    cCallLua();
    luaCallC();
    return 0;
}
