#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapMang(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("a[%d]:  ", i);
        scanf("%d", a + i);
    }
}
void xuatMang(int* a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%5d", *(a + i));
    printf("\n");
}
int tongSoDuong(int* a, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        if (*(a + i) > 0)
            s += *(a + i);
    return s;
}

int laSoNguyenTo(int x)
{
    if (x < 2) 
        return 0;
    for (int i = 2; i*i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

int demSoNguyenTo(int* a, int n)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (laSoNguyenTo(*(a + i)))
            dem++;
    return dem;
}

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sapXepTang(int* a, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (*(a + i) > *(a + j))
            {
				swap(a + i, a + j);
            }
}


void nhapMaTran(int** a, int m, int n)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
}
void xuatMaTran(int** a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }
}

int tongCheoChinh(int** a, int m, int n)
{
    int s = 0;
    int min = m < n ? m : n;
    for (int i = 0; i < min; i++)
        s += a[i][i];
    return s;
}

void maxMoiDong(int** a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        int max = a[i][0];
        for (int j = 1; j < n; j++)
            if (a[i][j] > max)
                max = a[i][j];
        printf("Max dong %d = %d\n", i, max);
    }
}


int main()
{
    int choice;

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. BT2 - Mang 1 chieu\n");
        printf("2. BT3 - Ma tran 2 chieu\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int n;
            printf("Nhap n = ");
            scanf("%d", &n);

            int* a = (int*)malloc(n * sizeof(int));

            nhapMang(a, n);
			xuatMang(a, n);
            printf("Tong so duong = %d\n", tongSoDuong(a, n));
            printf("So nguyen to = %d\n", demSoNguyenTo(a, n));

            sapXepTang(a, n);
            printf("Mang sau sap xep: ");
            for (int i = 0; i < n; i++)
                printf("%d ", a[i]);

            free(a);
        }
        else if (choice == 2)
        {
            int m, n;
            printf("Nhap m = ");
            scanf("%d", &m);
            printf("Nhap n = ");
            scanf("%d", &n);

            int** a = (int**)malloc(m * sizeof(int*));
            for (int i = 0; i < m; i++)
                a[i] = (int*)malloc(n * sizeof(int));

            nhapMaTran(a, m, n);
			xuatMaTran(a, m, n);
            printf("Tong cheo chinh = %d\n", tongCheoChinh(a, m, n));
            maxMoiDong(a, m, n);

            for (int i = 0; i < m; i++)
                free(a[i]);
            free(a);
        }

    } while (choice != 0);

    return 0;
}
