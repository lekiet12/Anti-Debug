#include<iostream>
#include<windows.h>
using namespace std;
bool IsDebugged()
    
{
    CONTEXT ctx;
    ZeroMemory(&ctx, sizeof(CONTEXT)); 
    ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS; 

    if(!GetThreadContext(GetCurrentThread(), &ctx))
        return false;

    return ctx.Dr0 || ctx.Dr1 || ctx.Dr2 || ctx.Dr3;
}
int main(){
    if(IsDebugged()){
        cout<<"Detect debug";
        exit(-1);
    }
    else{
        cout<<"hello";
    }
    cout<<" Kiet";
}