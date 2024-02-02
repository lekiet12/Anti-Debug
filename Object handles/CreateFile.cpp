#include<iostream>
#include<windows.h>
using namespace std;
bool check(){
    CHAR szFileName[MAX_PATH]; // Tạo mảng kí tự chứa tên đường dẫn

    // Lấy đường dẫn của chương trình và lưu vào szFileName. Nếu lấy không được tức là không tồn tại tệp tin thực thì
    // Tham số NULL chỉ lấy đường dẫn của chương trình hiện tại
    if (0 == GetModuleFileNameA(NULL, szFileName, sizeof(szFileName)))
        return false;

    // Dùng CreateFileA để mở với quyền truy cập độc quyền. Nếu không được thì nó sẽ trả về INVALID_HANDLE_VALUE. Nếu thành công thì nó trả về con trỏ tới file để đọc
    return INVALID_HANDLE_VALUE == CreateFileA(szFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, 0);
}
int main(){
    //Gọi hàm check kiểm tra xem có debug không
    if(check()){
        cout<<"detect debug";
        exit(-1);
    }
    else{
        cout<<"No Detect Debug";
    }
    return 0;
}
