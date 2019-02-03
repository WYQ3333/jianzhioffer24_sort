#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int num(vector<int> array, int temp){
		int i = temp;
		int result = 0;
		for (i = temp; i > 0; --i){
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
				result++;
				result += num(data, j);
			}
		}
		return result % 1000000007;
	}
};

void TestFunc(){
	vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 0 };
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