#include <iostream>

using namespace std;

class singleton{
	private:
		singleton(){}
		static singleton* p;
	public:
		static singleton* getinstance();
		void showMessage(){
			cout << "test singleton" << endl;
		}
};
singleton* singleton::p = new singleton;
singleton* singleton::getinstance(){
	return p;
}

int main(){
	singleton* test1 = singleton::getinstance();
	singleton* test2 = singleton::getinstance();

	if(test1 == test2) {
		cout << " only one instance" << endl;
	}
	
	return 0;
}
