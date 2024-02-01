#include<iostream>
#include<windows.h>
using namespace std;
bool check(){
    CHAR szFileName[MAX_PATH]; //

    if (0 == GetModuleFileNameA(NULL, szFileName, sizeof(szFileName)))
        return false;
    return INVALID_HANDLE_VALUE == CreateFileA(szFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, 0);
}
int main(){
    //Gọi hàm check kiểm tra xem có debug không
    if(check()){
        cout<<"detect debug";
        exit(-1);
    }
    else{
        cout<<"Hello";
    }
    cout<<" Kiet";
}