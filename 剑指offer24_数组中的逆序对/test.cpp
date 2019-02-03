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
		int i = 0, j = 0;
		for (; j < data.size();++i,++j){
			if (data[j] < data[i]){
				result += num(data, i);
			}
		}
		return result;
	}
};

void TestFunc(){

}

int main(){
	TestFunc();
	system("pause");
	return 0;
}