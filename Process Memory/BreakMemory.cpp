#include<iostream>
#include<windows.h>
using namespace std;
bool IsDebugged()
    
{
    CONTEXT ctx;// khai báo ctx để lưu thông tin của các luồng thực thi 
    ZeroMemory(&ctx, sizeof(CONTEXT)); // Thiết lập các byte trong trong ctx về 0
    ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS; // Chỉ định chỉ lấy thông tin của các thanh ghi gỡ lỗi.

    // Lấy thông tin của luồng thực thi hiện tại và lưu vào biến ctx
    if(!GetThreadContext(GetCurrentThread(), &ctx))
        return false;

    // Nếu bất kỳ thanh ghi gỡ lỗi nào khác 0 thì return true -> có debug
    return ctx.Dr0 || ctx.Dr1 || ctx.Dr2 || ctx.Dr3;
}
int main(){
    if(IsDebugged()){
        cout<<"Detect debug";
        exit(-1);
    }
    else{
        cout<<"No Detect Debug";
    }
    return 0;
}