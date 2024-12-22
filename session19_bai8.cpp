#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} SinhVien;

void studentNames(SinhVien arr[], int n);
void Show(SinhVien arr[], int n);

int main() {
    SinhVien sv[5] = {
        {1, "Nguyen Son Minh", 20, "0123456789"},
        {2, "Hoang Cuong Cat", 21, "0987654321"},
        {3, "Le Van Luyen", 22, "0345678901"},
        {4, "Tran Minh Cuong", 23, "0567890123"},
        {5, "Hoang Van Anh", 24, "0789012345"},
    };
    int soLuong = 5;

    printf("Danh sach sinh vien ban dau:\n");
    Show(sv, soLuong);

    studentNames(sv, soLuong);

    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    Show(sv, soLuong);

    return 0;
}

void studentNames(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].name, arr[j].name) > 0) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void Show(SinhVien arr[], int n) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               arr[i].id, arr[i].name, arr[i].age, arr[i].phoneNumber);
    }
}

