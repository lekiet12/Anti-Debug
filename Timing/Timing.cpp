#include <iostream>
#include <Windows.h>
#include<cmath>
using namespace std;

bool check() {
    // Gọi hàm GetTickCount64() để đo thời gian trước khi thực hiện công việc
    LONGLONG startTime = GetTickCount64();

    //Do somework
    int j = 0;
    for (int i = 0; i < 10; i++) {
        j+=i;
    }
    // Gọi hàm GetTickCount64() để đo thời gian sau khi thực hiện công việc
    LONGLONG endTime = GetTickCount64();
    return abs(endTime - startTime)!=0; //Nếu thời gian khác 0 tức là có breakpoint.
}

int main() {
    //Kiểm tra chương trình có đang debug không.
    if (check()) {
        cout << "Detected debug";
        exit(-1);
    }
    else {
        cout << "No Detect Debug";
    }
    return 0;

}