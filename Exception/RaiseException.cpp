#include <iostream>
#include <Windows.h>
using namespace std;

bool Check()
{
    __try
    {
        // Tạo một ngoại lệ DBG_CONTROL_C, DBG_CONTROL_C tương tự như breakpoint. 
        // RaiseException(DBG_CONTROL_C, 0, 0, NULL) chỉ tạo thành công trong môi trường debug.
        // Nếu tạo thành công thì sẽ return true, ngược lại sẽ thực thi lệnh trong khối except
        RaiseException(DBG_CONTROL_C, 0, 0, NULL);
        return true;
    }
    __except (GetExceptionCode() == DBG_CONTROL_C ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
    {
        return false;
    }
}

int main()
{
    //Kiểm tra có thực hiện debug không
    if (Check()){
        cout << "Detected debug";
    }
    else{
        cout << "Hello";
    }

    return 0;
}
