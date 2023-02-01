
#include <crtdbg.h>

#include "System/A.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    A a;
    a.Hello();
    a.Test();
    B b;
    b.Start();

    
    return 0;
}
