#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc,char**argv){
	float a = 3, b = 10 - a;
	std::cout << b;
	unordered_map<int, int> hmap;
	if (hmap.find(0) != hmap.end()) {
		std::cout << "find: " << hmap[0] << std::endl;
	}
	std::cout << hmap[0] << std::endl;

	if (hmap.find(0) != hmap.end()) {
		std::cout << "find: " << hmap[0] << std::endl;
	}
	system("pause");
	return 0;
}