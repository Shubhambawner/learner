
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
	
	string fileName = "trial.exe";
	char url[1000];
	strcpy_s(url, fileName.c_str());
	ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
    

	
}

/*
string fname = "C:\\z_PDFmaker!!";
	ifstream file(fname.c_str());
	if (!file.good()) {
		system("mkdir\\z_PDFmaker!!");
	}

	string fileName = "C:/PDFmaker/s.pdf";
			char url[1000] ;
			strcpy_s(url, fileName.c_str());
			ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
*/