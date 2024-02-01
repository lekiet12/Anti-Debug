#include<iostream>
#include<windows.h>
using namespace std;
bool IsDebugged()
{
    //
    __try
    {    //Tạo breakpoint nếu tạo thành công return true.Ngược lại thì return false. 
        DebugBreak();
        return true;
    }
    __except(EXCEPTION_EXECUTE_HANDLER) //Nếu một ngoại lệ xảy ra (không đặt breakpoint) trong khối try thì khối lệnh trong except
    {
        return false;
    }
}
int main() {
    //Kiểm tra xem chương trình có debug không.
    if (IsDebugged()) {
        cout << "Detect debug";
    }
    else {
        cout << "No Detect Debug";
    }
    return 0;
}