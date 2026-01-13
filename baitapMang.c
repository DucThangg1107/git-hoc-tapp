#include <stdio.h>
#include <math.h>

#define MAX 100

// ============= Nhap - Xuat ================
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

// ================ Tong cot va dong ==============
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

// ================ Cac dang cot va dong ===============
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
// ============== So Nguyen To ===============
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
			if (a[i][j] % 2 == 0)
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
// =============== DOi XUNG =================
int kiemTraDoiXung(int a[][MAX], int m, int n)
{
	if (m != n)
		return 0; 

	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i][j] != a[j][i])
				return 0;
	return 1;
}
// ============== so lon nhat cua moi dong,cot =======
 
void maxMoiDong(int a[][MAX], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		int max = a[i][0];

		for (int j = 1; j < n; j++)
			if (a[i][j] > max)
				max = a[i][j];

		printf("Dong %d co gia tri lon nhat = %d\n", i, max);
	}
}
void maxMoiCot(int a[][MAX], int m, int n)
{
	for (int j = 0; j < n; j++)
	{
		int max = a[0][j];

		for (int i = 1; i < m; i++)
			if (a[i][j] > max)
				max = a[i][j];

		printf("Cot %d co gia tri lon nhat = %d\n", j, max);
	}
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
		printf("10.Kiem tra doi xung\n");
		printf("11. Max moi dong\n");
		printf("12. Max moi cot\n");
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

			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}
			tongMoiDong(a, m, n);
			break;
		case 3:

			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}
			tongMoiCot(a, m, n);
			break;
		case 4:

			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}
			printf("Dong tong lon nhat: %d\n", dongTongMax(a, m, n));
			break;
		case 5:

			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}
			printf("Cot tong lon nhat: %d\n", CotTongMax(a, m, n));
			break;
		case 6:

			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}
			printf("Cot tong chan lon nhat: %d\n", CotTongChanMax(a, m, n));
			break;
		case 7:

			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}
			printf("Dong tong le nho nhat: %d\n", DongTongLeMin(a, m, n));
			break;
		case 8:

			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}
			nguyenToLonNhat(a, m, n);
			break;
		case 9:

			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}
			ChanLonNhat(a, m, n);
			break;
		case 10:
		{
			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}

			if (kiemTraDoiXung(a, m, n)==1)
				printf("Co doi xung");
			else
				printf("Khong doi xung");
			break;
		}
		case 11:

			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}
			maxMoiDong(a, m, n);
			break;
		case 12: 

			if (m == 0 || n == 0)
			{
				printf("Chua nhap ma tran!\n");
				break;
			}
			maxMoiCot(a, m, n);
			break;
		case 0:
			printf("Thoat chuong trinh\n");
			thoat = 0;
			break;
		default:
			printf("Lua chon khong hop le\n");
		}
	} while (thoat == 1);

	return 0;
}
