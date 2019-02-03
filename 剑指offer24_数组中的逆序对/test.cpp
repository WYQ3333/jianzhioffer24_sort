#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int num(vector<int> array, int temp){
		int i = temp;
		int result = 0;
		for (i = temp; i >= 0; --i){
			if (array[i] > array[temp]){
				++result;
			}
		}
		return result;
	}
	int InversePairs(vector<int> data) {
		int result = 0;
		int temp = 0;
		int i = 0, j = 1;
		for (; j < data.size();++i,++j){
			if (i<j&&data[j] < data[i]){
				result += num(data, j);
			}
		}
		return result % 1000000007;
	}
};

void TestFunc(){
	//vector<int> array = { 364, 637, 341, 406, 747, 995, 234, 971, 571, 219, 993, 
	//	407, 416, 366, 315, 301, 601, 650, 418, 355, 460, 505, 360, 965, 516, 648, 
	//	727, 667, 465, 849, 455, 181, 486, 149, 588, 233, 144, 174, 557, 67, 746, 
	//	550, 474, 162, 268, 142, 463, 221, 882, 576, 604, 739, 288, 569, 256, 936,
	//	275, 401, 497, 82, 935, 983, 583, 523, 697, 478, 147, 795, 380, 973, 958,
	//	115, 773, 870, 259, 655, 446, 863, 735, 784, 3, 671, 433, 630, 425, 930, 
	//	64, 266, 235, 187, 284, 665, 874, 80, 45, 848, 38, 811, 267, 575 };
	vector<int> array = { 6, 7, 3, 4 };
	Solution s;
	int result = 0;
	result = s.InversePairs(array);
	cout << "逆序对的个数为：";
	cout << result << endl;
}

int main(){
	TestFunc();
	system("pause");
	return 0;
}