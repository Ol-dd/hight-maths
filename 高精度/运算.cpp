#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

int big(string a,string b){
	if(a == b) return 0;
	if(a.size() > b.size()) return 1;
	if(a.size() < b.size()) return -1;
	if(a.compare(b) > 0) return 1;
	if(a.compare(b) < 0) return -1;
	return 0;
}
string qzero(string a){
	while(a[0] == '0') a.erase(0,1);
	if(a == "") a = "0";
	return a;
}
string zero(string a,int b){
	for(int i = 0;i < b;i++){
		a = a + "0";
	}
	return a;
}
string add(string a,string b){
	a = qzero(a);
	b = qzero(b);
	int num,j = 0;
	if(b.size() > a.size()) swap(a,b);
	for(int i = 0;i < b.size();i++){
		num = a[a.size() - i - 1] + b[b.size() - i - 1] + j - '0' - '0';
		j = num / 10;
		num %= 10;
		a[a.size() - i - 1] = num + '0';
	}
	for(int i = 0;i < a.size() - b.size();i++){
		if(j == 0) break;
		num = a[a.size() - b.size() - i - 1] + j - '0';
		j = num / 10;
		num %= 10;
		a[a.size() - b.size() - i - 1] = num + '0';
	}
	if(j == 1) a = "1" + a;
	return qzero(a);
}
string jf(string a,string b){
	a = qzero(a);
	b = qzero(b);
	if(a == b) return "0";
	else{
		int num,t1 = 0,t2 = 0;
		for(int i = 0;i < b.size();i++){
			if(a[a.size() - i - 1] - t2 < b[b.size() - i - 1]) t1 = 1;
			num = a[a.size() - i - 1] + t1 * 10 - b[b.size() - i - 1] - t2;
			t2 = t1;
			t1 = 0;
			a[a.size() - i - 1] = num + '0';
		}
		for(int i = 0;i < a.size() - b.size();i++){
			if(t2 == 0) break;
			if(a[a.size() - b.size() - i - 1] - '0' - t2 < 0) t1 = 1;
			num = a[a.size() - b.size() - i - 1] + t1 * 10 - t2 - '0';
			t2 = t1;
			t1 = 0;
			a[a.size() - b.size() - i - 1] = num + '0';
		}
		return qzero(a);
	}
}
string cf(string a,string b){
	a = qzero(a);
	b = qzero(b);
	string num = "0";
	if(b.size() > a.size()) swap(a,b);
	for(int i = 0;i < b.size();i++){
		int m,j = 0;
		string nm = "";
		for(int jj = 0;jj < a.size();jj++){
			m = (a[a.size() - jj - 1] - '0') * (b[b.size() - i - 1] - '0') + j;
			if(m > 9){
				j = m / 10;
				m %= 10;
			}
			else j = 0;
			string ad = "0";
			ad[0] = ('0' + m);
			nm = ad + nm;
		}
		if(j != 0){
			string ad = "0";
			ad[0] = '0' + j;
			nm = ad + nm;
		}
		num = add(num,zero(nm,i));
	}
	return qzero(num);
}
string chu(string a,string b){
	a = qzero(a);
	b = qzero(b);
	int n,j;
	string num = "",m = "0";
	n = a.size() - b.size();
	if(big(b,a.substr(0,b.size())) > 0) n--;
	j = n;
	for(int i = 0;i <= j;i++){
		m = "0";
		while(big(a,zero(b,n)) >= 0){
			a = jf(a,zero(b,n));
			m[0]++;
		}
		num = num + m;
		n--;
	}
	return qzero(num);
}
string mo(string a,string b){
	return jf(a,cf(chu(a,b),b));
}
int main(){
	string a,b;
	int c;
	cin>>a>>b>>c;
	switch (c) {
		case 1:
			cout<<add(a,b)<<endl;
			break;
		case 2:
			cout<<jf(a,b)<<endl;
			break;
		case 3:
			cout<<cf(a,b)<<endl;
			break;
		case 4:
			cout<<chu(a,b)<<endl<<mo(a,b)<<endl;
			break;
	}
	system("pause");
	return 0;
}
