/* code by DO KHOA HAI PHONG */
/* use Dev-C++ 5.11 */

#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

void input_s (string &s) {
	cin>>s;
}
int convert_s_i(string loops) { // ham chuyen doi string sang int
	int a = atoi(loops.c_str());
	return a;
}

string xnKytu(string a, int n) { // ham sao chep : a3=aaa
	string an;
	for ( int j=0; j< n; j++) {
		an+=a;
	}
	return an;
}

void process_s (string s, string &r ) { // procedure xu ly S;
 string loops ;
 string temp1 ;
 string temp2 ;
	for (int i=0; i<s.length(); i++) {

		if (int(s[i])==40) { // kiem tra '('

			while (int(s[i])!=41) {

				i++;
				if ( (int(s[i])>=65 && int(s[i]) <=90) || (int(s[i])>=97 && int(s[i]) <=122) ) { // kiem tra ky tu la alphabet ma ASCII
					
					temp1+=s[i]; // luu kt tu alphabet
				} else {
					loops+=s[i]; // luu so
					
					if (int(s[i+1]<48) || int(s[i+1]>57)) { // kiem tra ky tu tiep theo khong la so - ASCII
						temp2+=xnKytu(temp1,convert_s_i(loops)); // sao chep trong cap ky tu () a2d3=aaddd
						temp1.erase(); // xoa du lieu
						loops.erase();
					}
				}
			}
			i++;
			loops.erase();
			loops+=s[i];
			r+=xnKytu(temp2,convert_s_i(loops)); // sao chep temporay2 vao result
			loops.erase();
			
		}

		if ( (int(s[i])>=65 && int(s[i]) <=90) || (int(s[i])>=97 && int(s[i]) <=122) ) {
			temp1 += s[i];
		} else {
			loops +=s[i];
			if (int(s[i+1]<48) || int(s[i+1]>57)) { 
			
				r+=xnKytu(temp1,convert_s_i(loops)); //sao chep temporay2 vao result
				temp1.erase();
				loops.erase();
			} 
		}
	}
}

int main() {
	string s;
	string r;
	input_s(s);
	process_s(s,r);
	cout<<r;
}
