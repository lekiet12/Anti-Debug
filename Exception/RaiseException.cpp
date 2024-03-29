﻿#include <iostream>
#include <Windows.h>
using namespace std;

bool Check() {
    __try
    {
        // Tạo một ngoại lệ DBG_CONTROL_C, DBG_CONTROL_C tương tự như breakpoint. 
        // RaiseException(DBG_CONTROL_C, 0, 0, NULL) chỉ tạo thành công trong môi trường debug.
        RaiseException(DBG_CONTROL_C, 0, 0, NULL);
        return true;
    }
    // GetExceptionCode() == DBG_CONTROL_C Kiểm tra ngoại lệ có phải là DBG_CONTROL_C không.
    //Nếu phải thì sẽ thực thi khối lệnh trong except. Nếu không thì sẽ tiếp tục tìm kiếm 
    __except (GetExceptionCode() == DBG_CONTROL_C ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
    {
        return false;
    }
}

int main()
{
    //Kiểm tra có thực hiện debug không
    if (Check()) {
        cout << "Detected debug";
    }
    else {
        cout << "No Detect Debug";
    }
    return 0;
}