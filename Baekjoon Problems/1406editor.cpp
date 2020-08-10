#include <list>
#include <iostream>

using namespace std;

int main(){
	char input = -1;

	int n = 0, cursor = 0;
	string str = "";
	list<char> l;

	cin >> str;
	cin >> n;

	cursor = str.length();

	for(int i = 0; i < cursor; i++)
		l.push_back(str.at(i));

	list<char>::iterator it = l.end();

	for(int i = 0; i < n; i++){
		cin >> input;
		if(input == 'P'){
			cin >> input;
			// l.insert(l.begin() +cursor, input);
			l.insert(it, input);
		}else if(input == 'L'){
			// if(cursor > 0)
			// 	cursor--;
			if(it != l.begin())
				it--;
		}else if(input == 'D'){
			// if(cursor != l.size())
			// 	cursor++;
			if(it != l.end())
				it++;
		}else if(input == 'B'){
			if(!l.empty() && it != l.begin()){
				it = l.erase(--it);
			}
		}
	}

	for(list<char>::iterator i = l.begin(); i != l.end(); i++){
		cout << *(i);
	}
	cout << endl;
}