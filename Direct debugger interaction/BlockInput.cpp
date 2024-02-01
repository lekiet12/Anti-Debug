

#include <iostream>
#include <Windows.h>

bool IsDebugger()
{
    bool first = false, second = true;
    __try {
        first = BlockInput(true);
        second = BlockInput(true);
     }
    __finally
    {
        second=BlockInput(false);
    }
    return first && second;
}

int main()
{
    if (IsDebugger())
    {
        cout << "Detect Debug";
        ExitProcess(-1);
    }
    else
    {
        cout << "Hello";
    }

    cout << " Kiet";
    return 0;
}