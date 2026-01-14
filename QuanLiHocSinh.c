#include<stdio.h>
#include<string.h>
#include<conio.h>
struct sinhVien 
{
	char ma[11];
	char ten[31];
	char ngaysinh[20];
	float toan;
	float ly;
	float hoa;
};
// ======== Ham NHAP & XUAT ===========
void docSinhVienTuFile(sinhVien sv[],int& n)
{
	FILE* f = fopen("SinhVien.txt", "rt");
	if (f == NULL)
	{
		printf("Khong mo duoc file");
		return;
	}
	fscanf(f, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%[^#]#", sv[i].ma);
		fscanf(f, "%[^#]#", sv[i].ten);
		fscanf(f, "%[^#]#", sv[i].ngaysinh);
		fscanf(f, "%f#", &sv[i].toan);
		fscanf(f, "%f#", &sv[i].ly);
		fscanf(f, "%f\n", &sv[i].hoa);
	}
	fclose(f);
	printf("\n=> Da doc xong file\n");
}
float tbc(sinhVien sv)
{
	float tbc;
	return tbc = (sv.toan + sv.ly + sv.hoa) / 3;
}
void xuatFile(sinhVien sv[], int n)
{
	printf("\n%-15s %-25s %-20s %-13s %-13s %-13s %-13s\n", "Ma sinh vien", "Ten sinh vien", "Ngay sinh", "Diem toan", "Diem ly", "Diem hoa","Diem trung binh");
	printf("=======================================================================================================================\n");
	for (int i = 0; i < n; i++)
	{
		printf("%-15s %-25s %-20s %-13.2f %-13.2f %-13.2f %-13.2f\n",sv[i].ma, sv[i].ten, sv[i].ngaysinh, sv[i].toan, sv[i].ly, sv[i].hoa,tbc(sv[i]));
	}
}

// ========= Sap xep theo diem trung binh ========
void thiSinhTBCMax(sinhVien sv[], int n)
{
	float maxTBC = tbc(sv[0]);

	for (int i = 0; i < n; i++)
	{
		if(tbc(sv[i]) > maxTBC)
		{
			maxTBC = tbc(sv[i]);
			
		}
	}
	printf("\n%-15s %-25s %-20s %-13s %-13s %-13s %-13s\n", "Ma sinh vien", "Ten sinh vien", "Ngay sinh", "Diem toan", "Diem ly", "Diem hoa", "Diem trung binh");
	printf("=======================================================================================================================\n");
	for (int i = 0; i < n; i++)
	{
		if (tbc(sv[i]) == maxTBC)
		{
			printf("%-15s %-25s %-20s %-13.2f %-13.2f %-13.2f %-13.2f\n", sv[i].ma, sv[i].ten, sv[i].ngaysinh, sv[i].toan, sv[i].ly, sv[i].hoa, tbc(sv[i]));
		}
	}
}
void swap(sinhVien& a, sinhVien& b)
{
	sinhVien temp = a;
	a = b;
	b = temp;
 }
void sapXepTheoDiem(sinhVien sv[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (tbc(sv[i]) < tbc(sv[j]))
				swap(sv[i], sv[j]);
		}
	}
}

// ============= Xuat thi sinh rot ===================
void xuatThiSinhRot(sinhVien sv[], int n)
{
	printf("\n%-15s %-25s %-20s %-13s %-13s %-13s %-13s\n", "Ma sinh vien", "Ten sinh vien", "Ngay sinh", "Diem toan", "Diem ly", "Diem hoa", "Diem trung binh");
	printf("=======================================================================================================================\n");
	for (int i = 0; i < n; i++)
	{
		if(tbc(sv[i]) <4.0)
		printf("%-15s %-25s %-20s %-13.2f %-13.2f %-13.2f %-13.2f\n", sv[i].ma, sv[i].ten, sv[i].ngaysinh, sv[i].toan, sv[i].ly, sv[i].hoa, tbc(sv[i]));
	}
}

// ========= Sap xep theo ten ========
void layten(char s[], char ten[])
{
	int n = strlen(s);
	int i;
	for ( i = n - 1; i >= 0 && s[i] != ' '; i--)
	{

	}

	int k = 0;
	int j;
	for( j = i+1;j < n ;j++ )
	{
		ten[k++] = s[j];
	}
	ten[k] = '\0';
}
void sapXepTheoTen(sinhVien sv[], int n)
{
	char tentam1[100], tentam2[100];
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			layten(sv[i].ten, tentam1);
			layten(sv[j].ten, tentam2);
			if (strcmp(tentam1, tentam2) > 0)
			{
				swap(sv[i], sv[j]);
			}
		}
	}
}

// ======== Tim hoc sinh theo ten hoac ma ==========
void timTheoMa(sinhVien sv[], int n)
{
	int found = 0;
	char ma2[100];
	printf("Nhap ma sinh vien can tim: ");
	rewind(stdin);
	gets_s(ma2);
	printf("\n%-15s %-25s %-20s %-13s %-13s %-13s %-13s\n", "Ma sinh vien", "Ten sinh vien", "Ngay sinh", "Diem toan", "Diem ly", "Diem hoa", "Diem trung binh");
	printf("=======================================================================================================================\n");
	for (int i = 0; i < n; i++)
	{
		if(strcmp(sv[i].ma,ma2)==0)
		{
			printf("%-15s %-25s %-20s %-13.2f %-13.2f %-13.2f %-13.2f\n", sv[i].ma, sv[i].ten, sv[i].ngaysinh, sv[i].toan, sv[i].ly, sv[i].hoa, tbc(sv[i]));
			found = 1;
		}
	}
	if (found == 0)
	{
		printf("Khong thay ma sinh vien nay!\n");
		return;
	}

}
void timTheoTen(sinhVien sv[], int n)
{
	int found = 0;
	char ten[100];
	printf("Nhap ho va ten sinh vien can tim: ");
	rewind(stdin);
	gets_s(ten);
	printf("\n%-15s %-25s %-20s %-13s %-13s %-13s %-13s\n", "Ma sinh vien", "Ten sinh vien", "Ngay sinh", "Diem toan", "Diem ly", "Diem hoa", "Diem trung binh");
	printf("=======================================================================================================================\n");
	for (int i = 0; i < n; i++)
	{
		if (stricmp(sv[i].ten, ten) == 0)
		{
			printf("%-15s %-25s %-20s %-13.2f %-13.2f %-13.2f %-13.2f\n", sv[i].ma, sv[i].ten, sv[i].ngaysinh, sv[i].toan, sv[i].ly, sv[i].hoa, tbc(sv[i]));
			found = 1;
		}
	}
	if (found == 0)
	{
		printf("Khong tim thay sinh vien nay!\n");
		return;
	}
}

// =============== Them va xoa hoc sinh =================
int kiemTraTrungMa(sinhVien sv[], int n,char ma[])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(sv[i].ma, ma) == 0)
			return 1;
	}
	return 0;
}
void ghiFile(sinhVien sv[], int& n)
{
	FILE* f = fopen("SinhVien.txt", "w");
	if (f == NULL)
	{
		printf("Khong mo file duoc");
	}
	fprintf(f, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%s#", sv[i].ma);
		fprintf(f, "%s#", sv[i].ten);
		fprintf(f, "%s#", sv[i].ngaysinh);
		fprintf(f, "%.2f#", sv[i].toan);
		fprintf(f, "%.2f#", sv[i].ly);
		fprintf(f, "%.2f\n", sv[i].hoa);
	}
	printf("\n*****(File da thay doi du lieu)*****\n");
	fclose(f);

}
void themSinhVien(sinhVien sv[], int& n)
{
	sinhVien sv2;
	while (1)
	{
		 printf("Nhap ma:"); rewind(stdin); gets_s(sv2.ma);
		if (strlen(sv2.ma) == 0)
		{
			printf("Khong duoc de trong ! \n");
			continue;
		}
		if(kiemTraTrungMa(sv,n,sv2.ma))
		{
			printf("Loi: Ma so da ton tai! Nhap lai.\n");
		}
		else
		{
			break;
		}
	}
	printf("Nhap ten: ");       rewind(stdin);    gets_s(sv2.ten);
	printf("Nhap ngay sinh: "); rewind(stdin);    gets_s(sv2.ngaysinh);
	printf("Nhap diem toan: "); scanf_s("%f", &sv2.toan);
	printf("Nhap diem ly: "); scanf_s("%f", &sv2.ly);
	printf("Nhap diem hoa: "); scanf_s("%f", &sv2.hoa);
	sv[n] = sv2; 
	n++; 
	printf("-> Them thanh cong!\n");
	ghiFile(sv, n);
}
void xoaSinhVien(sinhVien sv[], int& n)
{
	char ma[15];
	printf("Nhap ma cua sinh vien can xoa : ");
	rewind(stdin);
	gets_s(ma);

	int viTri = -1;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(sv[i].ma, ma) == 0)
		{
			viTri = i;
			break;
		}
	}

	if (viTri == -1)
	{
		printf("Khong tim thay ma so nay!\n");
	}
	else
	{
		for (int i = viTri; i < n - 1; i++)
			sv[i] = sv[i + 1];
		n--;
		printf("-> Da xoa nhan vien ma so %s\n", ma);
		ghiFile(sv, n);
	}
}

// ================ Sua Thong Tin =====================
void dieuChinhTT(sinhVien sv[], int n)
{
	char ma[11];
	int timthay = 0;
	printf("Nhap ma cua hoc sinh can hieu chinh: ");
	rewind(stdin);
	gets_s(ma);
	
	for (int i = 0; i < n; i++)
	{
		if (strcmp(sv[i].ma, ma) == 0)
		{
			printf("\nDa tim thay hoc sinh: \n");
			printf("\n%-15s %-25s %-20s %-13s %-13s %-13s %-13s\n", "Ma sinh vien", "Ten sinh vien", "Ngay sinh", "Diem toan", "Diem ly", "Diem hoa", "Diem trung binh");
			printf("=======================================================================================================================\n");
			printf("%-15s %-25s %-20s %-13.2f %-13.2f %-13.2f %-13.2f\n", sv[i].ma, sv[i].ten, sv[i].ngaysinh, sv[i].toan, sv[i].ly, sv[i].hoa, tbc(sv[i]));


			do {
				printf("Nhap diem toan moi (0-10): ");
				scanf("%f", &sv[i].toan);
			} while (sv[i].toan < 0 || sv[i].toan > 10);

			do {
				printf("Nhap diem ly moi (0-10): ");
				scanf("%f", &sv[i].ly);
			} while (sv[i].ly < 0 || sv[i].ly > 10);

			do {
				printf("Nhap diem hoa moi (0-10): ");
				scanf("%f", &sv[i].hoa);
			} while (sv[i].hoa < 0 || sv[i].hoa > 10);


			timthay = 1;
			printf("\n=> Hieu chinh thanh cong!\n");
			ghiFile(sv, n);
			break;
		}
	}
	if (timthay == 0)
		printf("Khong tim thay sinh vien co ma %s\n", ma);
}

// =============== So Thi Sinh Dau Va Rot ====================
void soThiSinhDaVaRot(sinhVien sv[],int n)
{
	if (n == 0)
	{
		printf("Danh sach rong vui long doc file !\n");
		return;
	}
	int demdau = 0, demrot = 0;
	for (int i = 0; i < n; i++)
	{
		float dtb = tbc(sv[i]);
		if(dtb >= 4.0)
			demdau++;
		else
			demrot++;
	}
	printf("So hoc sinh dau ki thi: %d\n", demdau);
	printf("So hoc sinh rot ki thi: %d\n", demrot);
	printf("=> Vay ti le dau ky thi cua cac hoc sinh la %.2f %%\n", (100.0 * demdau) / n);

}

// ==================== Xep Loai Hoc Luc ===================
const char* xepLoaiHocLuc(sinhVien sv)
{
	float dtb = tbc(sv);

	if (dtb >= 8 && sv.toan >= 6 && sv.ly >= 6 && sv.hoa >= 6)
		return "Gioi";
	else if (dtb >= 6.5 && sv.toan >= 5 && sv.ly >= 5 && sv.hoa >= 5)
		return "Kha";
	else if (dtb >= 5)
		return "Trung binh";
	else
		return "Yeu";
}
void ghiFileCoHocLuc(sinhVien sv[], int& n)
{
	FILE* f = fopen("SinhVien_CoHocLuc.txt", "w");
	if (f == NULL)
	{
		printf("Khong mo file duoc");
	}
	fprintf(f, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%s#", sv[i].ma);
		fprintf(f, "%s#", sv[i].ten);
		fprintf(f, "%s#", sv[i].ngaysinh);
		fprintf(f, "%.2f#", sv[i].toan);
		fprintf(f, "%.2f#", sv[i].ly);
		fprintf(f, "%.2f", sv[i].hoa);
		fprintf(f, "%s\n", xepLoaiHocLuc(sv[i]));
	}
	printf("\n*****(File da thay doi du lieu)*****\n");
	fclose(f);

}
void docSinhVienTuFileHocLuc(sinhVien sv[], int& n)
{
	FILE* f = fopen("SinhVien_CoHocLuc.txt", "rt");
	if (f == NULL)
	{
		printf("Khong mo duoc file");
		return;
	}
	fscanf(f, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%[^#]#", sv[i].ma);
		fscanf(f, "%[^#]#", sv[i].ten);
		fscanf(f, "%[^#]#", sv[i].ngaysinh);
		fscanf(f, "%f#", &sv[i].toan);
		fscanf(f, "%f#", &sv[i].ly);
		fscanf(f, "%f#", &sv[i].hoa);

		char hocluc[20];
		fscanf(f, "%[^\n]\n", hocluc);
	}
	fclose(f);
	printf("\n=> Da doc xong file\n");
}
void xuatDanhSachCoHocLuc(sinhVien sv[], int n)
{
	printf("\n%-15s %-25s %-20s %-8s %-8s %-8s %-10s %-12s\n","Ma SV", "Ten SV", "Ngay sinh","Toan", "Ly", "Hoa","DTB", "Hoc luc");
	printf("=============================================================================================================\n");
	for (int i = 0; i < n; i++)
	{
		printf("%-15s %-25s %-20s %-8.2f %-8.2f %-8.2f %-10.2f %-12s\n",sv[i].ma, sv[i].ten, sv[i].ngaysinh,sv[i].toan, sv[i].ly, sv[i].hoa,tbc(sv[i]), xepLoaiHocLuc(sv[i]));
	}
}


void main()
{
	sinhVien sv[100];
	int n=0;
	int thoat = 1; 
	do
	{
		printf("\n=========== QUAN LY SINH VIEN ===========\n");
		printf(" 1. Doc danh sach sinh vien tu file\n");
		printf(" 2. Xuat danh sach sinh vien\n");
		printf(" 3. Thi sinh co DTB cao nhat\n");
		printf(" 4. Sap xep theo DTB (giam dan)\n");
		printf(" 5. Danh sach sinh vien rot\n");
		printf(" 6. Sap xep theo ten\n");
		printf(" 7. Tim sinh vien theo ma\n");
		printf(" 8. Tim sinh vien theo ten\n");
		printf(" 9. Them sinh vien\n");
		printf("10. Xoa sinh vien\n");
		printf("11. Sua thong tin sinh vien\n");
		printf("12. Thong ke dau / rot\n");
		printf("13. Xep loai hoc luc\n");
		printf("14. Xuat danh sach sinh vien co hoc luc\n");
		printf(" 0. Thoat\n");
		printf("=========================================\n");

		int chon;
		printf("Nhap bai thay muon xem: ");
		scanf_s("%d", &chon);
		switch (chon)
		{
		case 0:
			printf("\nDang thoat app quan ly.........\n");
			thoat = 0;
			break;
		case 1:
		{
			docSinhVienTuFile(sv, n);
			break;
		}
		case 2:
		{
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}

			xuatFile(sv, n);
			break;
		}
		case 3:
		{
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}

			thiSinhTBCMax(sv, n);
			break;
		}
		case 4:
		{
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}

			printf("\nBang thi sinh theo diem tbc: ");
			sapXepTheoDiem(sv, n);
			xuatFile(sv, n);
			break;
		}
		case 5:
		{
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}

			printf("\nBang thi sinh rot: ");
			xuatThiSinhRot(sv, n);
			break;
		}
		case 6:
		{
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}

			printf("\nBang thi sinh theo ten: ");
			sapXepTheoTen(sv, n);
			xuatFile(sv, n);
			break;
		}
		case 7:
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}

			timTheoMa(sv, n);
			break;
		case 8:
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}
			timTheoTen(sv, n);
			break;
		case 9:
			themSinhVien(sv, n);
			xuatFile(sv, n);
			break;
		case 10:
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}
			xoaSinhVien(sv, n);
			xuatFile(sv, n);
			break;
		case 11:
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}
			dieuChinhTT(sv, n);
			xuatFile(sv, n);
			break;
		case 12:
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}
			soThiSinhDaVaRot(sv, n);
			break;
		case 13:
			if (n == 0)
			{
				printf("Danh sach rong! Vui long doc file truoc\n");
				break;
			}
			xuatDanhSachCoHocLuc(sv, n);
			ghiFileCoHocLuc(sv, n);
			break;
		case 14:
			docSinhVienTuFileHocLuc(sv, n);
			xuatDanhSachCoHocLuc(sv, n);
			break;
		default:
			printf("Khong co chuc nang nay!\n");
			break;
		}
	} while (thoat == 1);
	_getch();
}