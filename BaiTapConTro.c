#include <stdio.h>
#include <stdlib.h>

void nhap(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nhap a[%d]: ", i);
        scanf("%d", a + i);// &a[i]
    }
}
void xuat(int* a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%5d", *(a + i));
}

int tongDuong(int* a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (*(a + i) > 0)
            sum += *(a + i);
    return sum;
}
int demChan(int* a, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (*(a + i) % 2 == 0)
            dem++;
    return dem;
}
// ===== Cap bo nho ====================
int* taoMang(int* n)
{
    do {
        printf("Nhap n (>0): ");
        scanf("%d", n);
    } while (*n <= 0);

    int* a = (int*)malloc((*n) * sizeof(int));
    if (a == NULL)
    {
        printf("Khong du bo nho!\n");
        exit(0);
    }

    nhap(a, *n);
    return a;
}

// ===== Them phan tu ====================
void themPhanTu(int** a, int* n, int x, int h)
{
    if (h < 0 || h > *n)
    {
        printf("Vi tri khong hop le!\n");
        return;
    }

    int* b;  // mang moi co kich thuoc n+1
    b = (int*)malloc((*n + 1) * sizeof(int));
    if (b == NULL)
    {
        printf("Khong du bo nho!\n");
        exit(0);
    }

    for (int i = 0; i < h; i++) // copy phan tu tu 0 den h-1
        *(b + i) = *(*a + i);// b[i] = a[i];

    *(b + h) = x;// tuong duong b[h] = x;

    for (int i = h; i < *n; i++) // copy phan tu tu h den n-1
        *(b + i + 1) = *(*a + i); // b[i+1] = a[i];

    free(*a);
    *a = b;
    (*n)++;
}

// ===== Xoa phan tu ===================
void xoaPhanTu(int** a, int* n, int h)
{
    if (h < 0 || h >= *n)
    {
        printf("Vi tri xoa khong hop le!\n");
        return;
    }

    int* b;
    b = (int*)malloc((*n - 1) * sizeof(int));
    if (b == NULL)
    {
        printf("Khong du bo nho!\n");
        exit(0);
    }

    for (int i = 0; i < h; i++)
        *(b + i) = *(*a + i);

    for (int i = h + 1; i < *n; i++)
        *(b + i - 1) = *(*a + i);

    free(*a);
    *a = b;
    (*n)--;
}

// ===== Xoa theo gia tri ====================
void xoaTheoGiaTri(int** a, int* n, int x)
{
    int dem = 0;
    for (int i = 0; i < *n; i++)
        if (*(*a + i) != x)
            dem++;

    if (dem == *n)
    {
        printf("Khong co %d trong mang!\n", x);
        return;
    }

    int* b;

    b = (int*)malloc(dem * sizeof(int));
    if (b == NULL)
    {
        printf("Khong du bo nho!\n");
        exit(0);
    }

    int j = 0;
    for (int i = 0; i < *n; i++)
        if (*(*a + i) != x)
        {
            *(b + j) = *(*a + i);
            j++;
        }

    free(*a);
    *a = b;
    *n = dem;
}

void xoaXuatHienDau(int** a, int* n, int x)
{
    int h = -1;
    int* b;


    for (int i = 0; i < *n; i++)
    {
        if (*(*a + i) == x)
        {
            h = i;
            break;
        }
    }

    if (h == -1)
    {
        printf("Khong tim thay %d trong mang!\n", x);
        return;
    }

    b = (int*)malloc((*n - 1) * sizeof(int));
    if (b == NULL)
    {
        printf("Khong du bo nho!\n");
        exit(0);
    }

    for (int i = 0; i < h; i++)
        *(b + i) = *(*a + i);

    for (int i = h + 1; i < *n; i++)
        *(b + i - 1) = *(*a + i);


    free(*a);
    *a = b;
    (*n)--;
}


void xoaDau(int** a, int* n)
{
    if (*n == 0)
    {
        printf("Mang rong!\n");
        return;
    }

    int* b = (int*)malloc((*n - 1) * sizeof(int));
    if (b == NULL)
    {
        printf("Khong du bo nho!\n");
        exit(0);
    }


    for (int i = 1; i < *n; i++)
        *(b + i - 1) = *(*a + i);

    free(*a);
    *a = b;
    (*n)--;
}
void xoaCuoi(int** a, int* n)
{
    if (*n == 0)
    {
        printf("Mang rong!\n");
        return;
    }

    int* b = (int*)malloc((*n - 1) * sizeof(int));
    if (b == NULL)
    {
        printf("Khong du bo nho!\n");
        exit(0);
    }

    // Copy tu a[0] -> a[n-2]
    for (int i = 0; i < *n - 1; i++)
        *(b + i) = *(*a + i);

    free(*a);
    *a = b;
    (*n)--;
}

// ===== Xoa So Nguyen To ==============
int laSNT(int x)
{
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}
void xoaSNT(int** a, int* n)
{
    int dem = 0;
    for (int i = 0; i < *n; i++)
        if (!laSNT(*(*a + i)))
            dem++;

    if (dem == 0)
    {
        free(*a);
        *a = NULL;
        *n = 0;
        return;
    }

    int* b;
    b = (int*)malloc(dem * sizeof(int));
    if (b == NULL)
    {
        printf("Khong du bo nho!\n");
        exit(0);
    }

    int j = 0;
    for (int i = 0; i < *n; i++)
        if (!laSNT(*(*a + i)))
        {
            *(b + j) = *(*a + i);
            j++;
        }

    free(*a);
    *a = b;
    *n = dem;
}
/* ================= MAIN ================= */
int main()
{
    int thoat = 1;
    do
    {
        printf("\n===== MENU =====\n");
        printf("1. Nhap & xuat mang\n");
        printf("2. Tong so duong, dem so chan\n");
        printf("3. Them phan tu\n");
        printf("4. Xoa theo vi tri\n");
        printf("5. Xoa theo gia tri\n");
        printf("6. Xoa so nguyen to\n");
        printf("7. Xoa lan dau\n");
        printf("8. Xoa dau\n");
        printf("9. Xoa cuoi\n");
        printf("0. Thoat\n");
        printf("=======================================\n");

		int chon;
        printf("Chon: ");
        scanf("%d", &chon);

        int n;
        int* a = taoMang(&n);

        switch (chon)
        {
        case 0:
            printf("Thoat chuong trinh!\n");
            thoat = 0;
            exit(0);
			break;

        case 1:
            xuat(a, n);
            break;

        case 2:
            xuat(a, n);
            printf("\nTong duong: %d", tongDuong(a, n));
            printf("\nSo chan: %d", demChan(a, n));
            break;

        case 3:
        {
            int x, h;
            printf("\nNhap gia tri can them: ");
            scanf("%d", &x);
            printf("Nhap vi tri: ");
            scanf("%d", &h);
            themPhanTu(&a, &n, x, h);
            xuat(a, n);
            break;
        }

        case 4:
        {
            int h;
            printf("\nNhap vi tri can xoa: ");
            scanf("%d", &h);
            xoaPhanTu(&a, &n, h);
            xuat(a, n);
            break;
        }

        case 5:
        {
            int x;
            printf("\nNhap gia tri can xoa: ");
            scanf("%d", &x);
            xoaTheoGiaTri(&a, &n, x);
            xuat(a, n);
            break;
        }

        case 6:
            xoaSNT(&a, &n);
            xuat(a, n);
            break;

		case 7:
            int x;
            printf("\nNhap gia tri can xoa lan dau: ");
            scanf("%d", &x);
            xoaXuatHienDau(&a, &n, x);
            xuat(a, n);
            break;
		
         case 8:
            xoaDau(&a, &n);
            xuat(a, n);
			break;   

         case 9:
            xoaCuoi(&a, &n);
            xuat(a, n);
			break;

        default:
            printf("Lua chon khong hop le!\n");
        }

        if (a != NULL)
            free(a);

    } while (thoat == 1);

    return 0;
}
