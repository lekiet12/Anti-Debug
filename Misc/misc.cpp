#include<iostream>
#include<windows.h>
#include<vector>
using namespace std;

// Tạo danh sách các tên lớp cửa sổ các debugger
const vector<string> vWindowClasses = { 
    "antidbg",
    "ID",           
    "ntdll.dll",       
    "OLLYDBG",
    "WinDbgFrameClass", 
    "IDA"
};

bool IsDebugged()
{
    // Sử dụng vòng lặp for để kiểm tra các cửa sổ đang bật có phải là một debugger không
    for (int i=0;i<vWindowClasses.size();i++)
    { 
        string sWndClass=vWindowClasses[i]; 
        // Cấu trúc: FindWindowA(lpClassName,lpWindowName)  -> tìm cửa sổ có tên là lpClassName có đang bật hay không. Nếu không trả về NULL
        // lpClassName: là tên lớp của cửa sổ, là con trỏ kiểu char 
        // lpWindowName: title của cửa sổ.
        if (NULL != FindWindowA(NULL,sWndClass.c_str())) //sWndClass.c_str() : chuyển chuỗi sang con trỏ kiểu char
            return true;
    }
    return false;
}
int main(){
    // Kiểm tra chương trình có đang debug không. Nếu có thì exit.
    if(IsDebugged()){
        cout<<"Detect debug";
        exit(-1);
    }
    else{
        cout<<"No Detect Debug";
    }
    return 0;
}