#include<bits/stdc++.h>
using namespace std;

class SV{
	string msv, ten, ns, gt, qq;
public:
	SV();
	SV(string,string,string,string,string);
	friend ostream&operator<<(ostream &, SV);
	friend istream&operator>>(istream &, SV &);
};

SV::SV(){
	msv = ten = ns = gt = qq = "";
}

SV::SV(string msv, string ten, string ns, string gt,string qq)
{
	this->msv = msv;
	this->ten = ten;
	this->gt = gt;
	this->ns = ns;
	this->qq = qq;
}

ostream &operator<<(ostream &os, SV a)
{
	os << setw(10) << left << a.msv << "|" << setw(25) << left << a.ten << "|" << setw(10) << left << a.ns << "|" << setw(7) << left << a.gt << "|" << setw(15) << left << a.qq <<endl;
	return os;
}

istream &operator>>(istream &is, SV &a)
{
	cout << "MSV: ";
	is >> a.msv;
	cin.ignore();
	cout << "Ten: ";
	getline(cin, a.ten);
	cout << "Ngay sinh: ";
	is >> a.ns;
	cout << "Gioi tinh: ";
	is >> a.gt;
	cin.ignore();
	cout << "Que quan: ";
	getline(cin, a.qq);
	return is;
}

int main(){
	int n;
	cout << "Nhap so sinh vien: ";
	cin >> n;
	
	list<SV> ds;
	SV x;
	
	for(int i = 0; i < n; i++)
	{
		cout << "Sinh vien " << i + 1 << endl;
		cin >> x;
		ds.push_back(x);
	}
	
	cout << "Danh sach sinh vien vua nhap la: \n";
	for(auto it = ds.begin(); it != ds.end(); ++it)
	{
		cout << *it;
	}
	
	int syn, index;
	do{
		cout << "---------------------------------------------------------------------";
		cout << "\nChon 1 trong 5 chuc nang sau:";
		cout << "\n1.Them 1 sinh vien vao cuoi danh sach.";
		cout << "\n2.Them 1 sinh vien vao dau danh sach.";
		cout << "\n3.Xoa bo 1 sinh vien thu i ra khoi danh sach.";
		cout << "\n4.Thay the sinh vien thu i thanh 1 sinh vien moi.";
		cout << "\n5.In danh sach sinh vien.";
		cout << "\n\nHoac nhan '0' de thoat khoi chuong trinh!";
		cout << "\n---------------------------------------------------------------------";
		cout << "\nChon yeu cau thu: ";
		cin >> syn;
		
		if(syn > 5 || syn < 0){
			cout << "\nVui long nhap lai!!!";
			continue;
		}
		
		list<SV>::iterator it = ds.begin();
		
		switch(syn)
		{
			case 1:
				cout << "\n\nNhap thong tin sinh vien: \n";
				cin >> x;
				ds.push_back(x);
				break;
			case 2:
				cout << "\n\nNhap thong tin sinh vien: \n";
				cin >> x;
				ds.push_front(x);
				break;	
			case 3:
				cout << "\n\nNhap vi tri sinh vien can xoa: ";
				cin >> index;
				advance(it, index - 1);
				ds.erase(it);
				break;
			case 4:
				cout << "\n\nNhap thong tin sinh vien thay the: \n";
				cin >> x;
				cout << "Nhap vi tri can thay the: ";
				cin >> index;
				advance(it, index - 1);
				ds.insert(it, x);
				ds.erase(it);
				break;
			case 5:
				cout << "\n\nDanh sach sinh vien: \n";
				for(auto it1 = ds.begin(); it1 != ds.end(); ++it1)
				{
					cout << *it1;
				}	
		}
	} while (syn != 0);
}

