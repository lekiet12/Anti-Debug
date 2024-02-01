#include<iostream>
#include<windows.h>
using namespace std;
int main(){
// Gọi APT windows IsDebuggerPresent() kiểm tra xem có debug không nếu có thì in ra : Detect debug và thoát khỏi chương trình
    if(IsDebuggerPresent()){  
        cout<<"Detect debug";
        exit(-1);
    }
    else{
        cout<<"No Detect Debug";
    }
    return 0;
}