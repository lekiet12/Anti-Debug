#include <iostream>
#include <Windows.h>
using namespace std;
bool IsDebugger() {
    bool first = false, second = true;
    __try {
        first = BlockInput(true);
        second = BlockInput(true);
    }
    __finally
    {
        BlockInput(false);
    }
    return first && second;
}

int main() {
    if (IsDebugger()) {
        cout << "Detect Debug";
        ExitProcess(-1);
    }
    else {
        cout << "No Detect Debug";
    }
    return 0;
}