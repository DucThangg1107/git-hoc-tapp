#include <stdio.h>
#include <math.h>

#define MAX 100

// ============= NHẬP – XUẤT ================
void nhapMT(int a[][MAX], int* m, int* n)
{
	do
	{
		printf("Nhap so dong: ");
		scanf("%d", m);
		printf("Nhap so cot: ");
		scanf("%d", n);
		if (*m <= 0 || *n <= 0)
			printf("Dong va cot phai > 0\n");
	} while (*m <= 0 || *n <= 0);

	for (int i = 0; i < *m; i++)
		for (int j = 0; j < *n; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
}

void xuatMT(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}

// ================ TỔNG DÒNG – CỘT ==============
int tongDong(int a[][MAX], int dong, int n)
{
	int tong = 0;
	for (int j = 0; j < n; j++)
		tong += a[dong][j];
	return tong;
}

int tongCot(int a[][MAX], int m, int cot)
{
	int tong = 0;
	for (int i = 0; i < m; i++)
		tong += a[i][cot];
	return tong;
}

void tongMoiDong(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
		printf("Tong dong %d = %d\n", i, tongDong(a, i, n));
}

void tongMoiCot(int a[][MAX], int m, int n)
{
	for (int j = 0; j < n; j++)
		printf("Tong cot %d = %d\n", j, tongCot(a, m, j));
}

// ================ DÒNG / CỘT ĐẶC BIỆT ===============
int dongTongMax(int a[][MAX], int m, int n)
{
	int dongMax = 0;
	int tongMax = tongDong(a, 0, n);

	for (int i = 1; i < m; i++)
	{
		int tong = tongDong(a, i, n);
		if (tong > tongMax)
		{
			tongMax = tong;
			dongMax = i;
		}
	}
	return dongMax;
}

int CotTongMax(int a[][MAX], int m, int n)
{
	int cotMax = 0;
	int tongMax = tongCot(a, m, 0);

	for (int j = 1; j < n; j++)
	{
		int tong = tongCot(a, m, j);
		if (tong > tongMax)
		{
			tongMax = tong;
			cotMax = j;
		}
	}
	return cotMax;
}

int CotTongChanMax(int a[][MAX], int m, int n)
{
	int cotMax = -1;
	int tongMax = -1;

	for (int j = 0; j < n; j++)
	{
		int tong = tongCot(a, m, j);
		if (tong % 2 == 0 && tong > tongMax)
		{
			tongMax = tong;
			cotMax = j;
		}
	}
	return cotMax;
}

int DongTongLeMin(int a[][MAX], int m, int n)
{
	int dongMin = -1;
	int tongMin;

	for (int i = 0; i < m; i++)
	{
		int tong = tongDong(a, i, n);
		if (tong % 2 != 0)
		{
			if (dongMin == -1 || tong < tongMin)
			{
				tongMin = tong;
				dongMin = i;
			}
		}
	}
	return dongMin;
}

// ============== SỐ NGUYÊN TỐ ===============
int laNguyenTo(int x)
{
	if (x < 2) return 0;
	for (int i = 2; i*i <= x; i++)
		if (x % i == 0) return 0;
	return 1;
}

void nguyenToLonNhat(int a[][MAX], int m, int n)
{
	int found = 0, maxNT;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (laNguyenTo(a[i][j]))
			{
				if (!found || a[i][j] > maxNT)
				{
					maxNT = a[i][j];
					found = 1;
				}
			}

	if (found)
		printf("So nguyen to lon nhat = %d\n", maxNT);
	else
		printf("Khong co so nguyen to\n");
}

void ChanLonNhat(int a[][MAX], int m, int n)
{
	int found = 0, maxChan;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j % 2 == 0])
			{
				if (!found || a[i][j] > maxChan)
				{
					maxChan = a[i][j];
					found = 1;
				}
			}

	if (found)
		printf("So chan lon nhat = %d\n", maxChan);
	else
		printf("Khong co so chan\n");
}

// ================= MAIN =================
int main()
{
	int a[MAX][MAX];
	int m = 0, n = 0;
	int thoat = 1;

	do
	{
		printf("\n===== MENU =====\n");
		printf("1. Nhap va xuat ma tran\n");
		printf("2. Tong moi dong\n");
		printf("3. Tong moi cot\n");
		printf("4. Dong co tong lon nhat\n");
		printf("5. Cot co tong lon nhat\n");
		printf("6. Cot co tong chan lon nhat\n");
		printf("7. Dong co tong le nho nhat\n");
		printf("8. So nguyen to lon nhat\n");
		printf("9. So chan lon nhat\n");
		printf("0. Thoat\n");
		int chon;
		printf("Chon bai muon xem: ");
		scanf("%d", &chon);

		switch (chon)
		{
		case 1:
			nhapMT(a, &m, &n);
			xuatMT(a, m, n);
			break;
		case 2:
			tongMoiDong(a, m, n);
			break;
		case 3:
			tongMoiCot(a, m, n);
			break;
		case 4:
			printf("Dong tong lon nhat: %d\n", dongTongMax(a, m, n));
			break;
		case 5:
			printf("Cot tong lon nhat: %d\n", CotTongMax(a, m, n));
			break;
		case 6:
			printf("Cot tong chan lon nhat: %d\n", CotTongChanMax(a, m, n));
			break;
		case 7:
			printf("Dong tong le nho nhat: %d\n", DongTongLeMin(a, m, n));
			break;
		case 8:
			nguyenToLonNhat(a, m, n);
			break;
		case 9:
			ChanLonNhat(a, m, n);
			break;
		case 0:
			printf("Thoat chuong trinh\n");
			break;
		default:
			printf("Lua chon khong hop le\n");
		}
	} while (thoat == 1);

	return 0;
}
