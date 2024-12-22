#include <stdio.h>
#include <string.h>

struct SinhVien {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

typedef struct SinhVien sinhVien;

void delate(int id, sinhVien sv[], int *n);
void hienThiDanhSach(sinhVien sv[], int n);

int main() {
    sinhVien sv[5] = {
        {1, "Nguyen Son Minh", 20, "0123456789"},
        {2, "Hoang Cuong Cat", 21, "0987654321"},
        {3, "Le Van Luyen", 22, "0345678901"},
        {4, "Tran Minh Cuong", 23, "0567890123"},
        {5, "Hoang Van anh", 24, "0789012345"},
    };
    int n = 5;
    int id;

    printf("Danh sach sinh vien ban dau:\n");
    hienThiDanhSach(sv, n);

    printf("Moi ban nhap vao id sinh vien muon xoa: ");
    scanf("%d", &id);

    delate(id, sv, &n);

    printf("\nDanh sach sinh vien la:\n");
    hienThiDanhSach(sv, n);

    return 0;
}

void delate(int id, sinhVien sv[], int *n) {
    int found = 0;

    for (int i = 0; i < *n; i++) {
        if (sv[i].id == id) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                sv[j] = sv[j + 1];
            }
            (*n)--;

            printf("\nSinh vien co ID %d da duoc xoa.\n", id);
            break;
        }
    }
    if (!found) {
        printf("\nKhong tim thay sinh vien co ID %d trong danh sach.\n", id);
    }
}

void hienThiDanhSach(sinhVien sv[], int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d Name: %s Age: %d Phone: %s\n",sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
    }
}

