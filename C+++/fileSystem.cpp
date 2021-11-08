#include <iostream>
#include <string>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
using namespace fs;
using namespace std;

int main() {
    string path = current_path().string();
    cout << "Current working directory: " << path << endl;

    for (auto& entry : directory_iterator(path))
    {
        cout << "sub-directories include : \t" << (entry.path()).string()<<endl;
    }

    string j = "";
    getline(cin, j);
    
    return 0;
}
//dosent run bcz of the vs code config. but it is functional
/*

Current working directory: C:\Users\Shubham\Desktop
sub-directories include :       C:\Users\Shubham\Desktop\Adobe Premiere Pro CC 2018.lnk
sub-directories include :       C:\Users\Shubham\Desktop\codeTester.exe
sub-directories include :       C:\Users\Shubham\Desktop\desktop.ini
sub-directories include :       C:\Users\Shubham\Desktop\Eclipse IDE for Java Developers - 2021-03.lnk
sub-directories include :       C:\Users\Shubham\Desktop\eclipse.exe - Shortcut.lnk
sub-directories include :       C:\Users\Shubham\Desktop\MPC-HC.lnk
sub-directories include :       C:\Users\Shubham\Desktop\mySpacs - Shortcut.txt.lnk
sub-directories include :       C:\Users\Shubham\Desktop\New folder
sub-directories include :       C:\Users\Shubham\Desktop\PDFmaker!!
sub-directories include :       C:\Users\Shubham\Desktop\PDFmaker!!.rar
sub-directories include :       C:\Users\Shubham\Desktop\PL7.exe - Shortcut.lnk
sub-directories include :       C:\Users\Shubham\Desktop\rough - Copy.txt
sub-directories include :       C:\Users\Shubham\Desktop\rough.txt
sub-directories include :       C:\Users\Shubham\Desktop\studio64 - Shortcut.lnk
sub-directories include :       C:\Users\Shubham\Desktop\Telegram.lnk
sub-directories include :       C:\Users\Shubham\Desktop\Thumbs.db
sub-directories include :       C:\Users\Shubham\Desktop\utilities
sub-directories include :       C:\Users\Shubham\Desktop\Visual Studio Code.lnk
sub-directories include :       C:\Users\Shubham\Desktop\WhatsApp Documents
sub-directories include :       C:\Users\Shubham\Desktop\WhatsApp.lnk
sub-directories include :       C:\Users\Shubham\Desktop\Yandex.lnk

*/