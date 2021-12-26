// C++ program for illustration
// of map::find() function
#include <bits/stdc++.h>
using namespace std;

int main()
{

	// Initialize container
	map<int, int> mp;

	// Insert elements in random order
	mp.insert({ 2, 30 });
	mp.insert({ 1, 40 });
	mp.insert({ 3, 20 });
	mp.insert({ 4, 50 });

	cout << "Elements from position of 3 in the map are : \n";
	cout << "KEY\tELEMENT\n";

	// find() function finds the position
	// at which 3 is present
	for (auto itr = mp.find(3); itr != mp.end(); itr++) {
	
		cout << itr->first << '\t' << itr->second << '\n';
	}

	
  map<string, string> dc;
  dc.insert({"zsd","srf"});
  dc.insert({"fsd","smf"});
  dc.insert({"zhd","wmf"});
  dc.insert({"esd","ymf"});
  dc.insert({"bsd","smyf"});
  dc.insert({"dsd","suf"});
  
  map<string, string>::iterator itr = dc.end();
  if(itr == dc.end()){
      cout<<"end catched";
  }
  map<string, string>::iterator itr2 = dc.find("asd");
  if(itr2 == dc.end()){
      cout<<"end catched2";
  }
  return 0;
}
/*
zcc7vSN$szM5sM5
Please note your Reference ID: DT20218131091 for all further communication with TCS.*/