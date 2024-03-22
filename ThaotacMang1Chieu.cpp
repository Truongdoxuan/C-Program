#include<stdio.h>
#define MAX 100

//Hàm nhập số lượng và giá trị phần tử mảng a
void NhapMangA(int a[], int &na)
{
	printf("Nhap so luong phan tu mang a (n>3): ");
	scanf("%d", &na);
	while (na < 3 || na > 50)
	{
		printf("Xin moi nhap lai: ");
		scanf("%d", &na);
	}
	//Nhập giá trị từng phần tử 
	for (int i = 0; i < na; i++) 
	{
		printf("a[%d]= ", i);
		scanf("%d", &a[i]);
	}
}

//Hàm xuất mảng a
void XuatMangA(int a[], int na) 
{
	for (int i = 0; i < na; i++) 
	{
		printf("%d\t", a[i]);
	}
	printf("\n");
}

//VD1 Đếm và trả về số lượng phần tử có giá trị bằng x trong mảng 
int DemSlPTX(int a[], int na, int x) {
	int countX = 0;
	for (int i = 0; i < na; i++) {
		if (a[i] == x) {
			countX++;
		}
	}
	return countX;
}

//VD2 Kiểm tra mảng a có các phần tử theo thứ tự tăng dần hay không 
int KtraTangDan(int a[], int na) 
{
	for (int i = 1; i < na; i++) 
	{
		if (a[i - 1] > a[i]) 
		{
			return 0;
		}
	}
	return 1;
}

void XuatKQKTTD(int a[], int na)
{
	if (KtraTangDan(a, na) == 1)
	{
		printf("\nMang duoc sap xep theo thu tu tang dan");
	}
	else printf("\nMang khong duoc sap xep theo thu tu tang dan");
}

//VD3 Tìm phần tử lớn nhất và nhỏ nhất trong mảng
int TimMax(int a[], int na) 
{
	int max = a[0];
	for (int i = 0; i < na; i++) 
	{
		if (a[i] > max) 
		{
			max = a[i];
		}
	}
	return max;
}

int TimMin(int a[], int na) 
{
	int min = a[0];
	for (int i = 0; i < na; i++) 
	{
		if (a[i] < min) 
		{
			min = a[i];
		}
	}
	return min;
}

//VD4 Sắp xếp mảng tăng/giảm dần đều
void SapxepTang(int a[], int na)
{
	int temp = 0;
	for (int i = 0; i < na; i++)
	{
		for (int j = i + 1; j < na; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

}

void SapxepGiam(int a[], int na) 
{
	int temp = 0;
	for (int i = 0; i < na;i++) 
	{
		for (int j = i + 1; j < na; j++) 
		{
			if (a[i] < a[j]) 
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

//VD5 Tách mảng a thành 2 mảng b (chứa pt chẵn) và mảng c (chứa pt lẻ)
void TachMangA(int a[], int na, int b[], int& nb, int c[], int& nc) {
	nb = 0;
	nc = 0;
	for (int i = 0; i < na; i++) {
		if (a[i] % 2 == 0) {
			b[nb] = a[i];
			nb++;
		}
		else {
			c[nc] = a[i];
			nc++;
		}
	}
}
/*void NhapMangB(int b[], int& nb) {
	printf("\nNhap so luong phan tu trong mang b: ");
	scanf("%d", &nb);
	for (int i = 0; i < nb; i++) {
		printf("b[%d]= ", i);
		scanf_s("%d", &b[i]);
	}
}
*/

//VD6 Chèn phần tử có giá trị x vào vtri phần tử lớn nhất trong mảng
int vtriMax(int a[], int na) {
	int max = a[0];
	int vt = 0;
	for (int i = 0;i < na;i++) {
		if (a[i] > max) {
			max = a[i];
			vt = i;
		}
	}
	return vt;
}

void ChenX(int a[], int *na, int x) {
	int vtri = vtriMax(a, *na);
	for (int i = *na; i > vtri; i--) {
		a[i] = a[i - 1];
	}
	(*na)++;
	a[vtri] = x;
}

//VD7 Xóa phần tử có giá trị lớn nhấ trong mảng 
void XoaptuMax(int a[], int& na) {
	int vtri = vtriMax(a, na);
	for (int i = vtri; i <= na - 1; i++)
	{
		a[i] = a[i + 1];
	}
	na--;
}


int main()
{
	int a[MAX], b[MAX], c[MAX];
	int na, nb, nc;
	NhapMangA(a, na);
	XuatMangA(a, na);
	//VD1
	int x;
	printf("Nhap x: ");
	scanf("%d", &x);
	printf("So luong phan tu co gia tri %d la: %d", x, DemSlPTX(a, na, x));
	//VD2
	XuatKQKTTD(a, na);
	//VD3
	printf("\nPhan tu lon nhat trong mang: %d", TimMax(a, na));
	printf("\nPhan tu nho nhat trong mang: %d", TimMin(a, na));
	//VD4
	SapxepTang(a, na);
	printf("\nMang duoc sap xep theo thu tu tang dan: ");
	for (int i = 0; i < na; i++)
	{
		printf("%d\t", a[i]);
	}
	SapxepGiam(a, na);
	printf("\nMang duoc sap xep theo thu tu giam dan: ");
	for (int i = 0; i < na; i++)
	{
		printf("%d\t", a[i]);
	}
	//VD5
	TachMangA(a, na, b, nb, c, nc);
	//Them ham sapxepTang de hien thi dep hon
	SapxepTang(b, nb);
	printf("\nMang b chua cac phan tu chan la: ");
	for (int i = 0; i < nb; i++) 
	{
		printf("%d\t", b[i]);
	}
	SapxepTang(c, nc);
	printf("\nMang c chua cac phan tu le la: ");
	for (int i = 0; i < nc; i++) 
	{
		printf("%d\t", c[i]);
	}
	//VD6
	vtriMax(a,na);
	ChenX(a,&na,x);
	printf("\nMang sau khi chen: ");
	SapxepTang(a, na);
	XuatMangA(a,na);
	//VD7
	printf("\nMang sau khi xoa phan tu lon nhat: ");
	XoaptuMax(a, na);
	SapxepTang(a, na);
	XuatMangA(a, na);
	//
	return 0;
}

