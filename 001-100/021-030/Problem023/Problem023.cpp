#include <iostream>

using namespace std;
//#define NUM_STUDENTS ( 20 )
#define MAX_NAME_LEN ( 20 )

enum STUDENTS {
	DEREK, YUAN, IRFAN, THARIKA, CHENGYI, CHEN, YITONG, EMRAN,
	MICHAEL, ZIQI, LIANG, JENNA, RAY, JOSH, TINGYAO, MANUEL,
	CALLUM, SHIHAO, AHMED, HYOEUN, JUNTIAN, NUM_STUDENTS
};

const char students[NUM_STUDENTS][MAX_NAME_LEN] = {
	"Derek",	"Yuan",	"Irfan",	"Tharika",	"Chengyi",	"Chen",	"Yitong",	"Emran",
	"Michael",	"Ziqi",	"Liang",	"Jenna","Ray", "Josh",	"Tingyao",	"Manuel",
	"Callum",	"Shihao",	"Ahmed",	"Hyoeun",	"Juntian" };

int main()
{
	unsigned int idx;
	std::cin >> idx;
	
	if (idx < NUM_STUDENTS)
		cout << "The students name is: " << students[idx];
	else
		cout << "Not in the class.";
	
	
	cin.get();
	system("pause");
}


