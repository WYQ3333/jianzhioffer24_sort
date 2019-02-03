#include<iostream>
#include<vector>

using namespace std;

class Solution1 {
public:
	int num(vector<int> array, int temp){
		if (temp == 0){
			return 0;
		}
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
		int i = 0;
		for (i = 0; i < data.size(); ++i){
			result += num(data, i);
		}
		return result % 1000000007;
	}
};

class Solution2 {
public:
	int num(vector<int> data, int p){
		int index = 0;
		int temp = data[p];
		int i = 0;
		for (i = p+1; i < data.size(); ++i){
			if (data[i] < temp)
				++index;
		}
		return index;
	}
	int InversePairs(vector<int> data) {
		int result = 0;
		int i = 0;
		int index = num(data, 0);
		result = index;
		for (i = 1; i < data.size(); ++i){
			index = num(data, i);
			result += index;
		}
		return result % 1000000007;
	}
};

class Solution {
public:
	int InversePairs(vector<int> data) {
		int length = data.size();
		if (length <= 0)
			return 0;
		//vector<int> copy=new vector<int>[length];
		vector<int> copy;
		for (int i = 0; i<length; i++)
			copy.push_back(data[i]);
		long long count = InversePairsCore(data, copy, 0, length - 1);
		//delete[]copy;
		return count % 1000000007;
	}
	long long InversePairsCore(vector<int> &data, vector<int> &copy, int start, int end)
	{
		if (start == end)
		{
			copy[start] = data[start];
			return 0;
		}
		int length = (end - start) / 2;
		long long left = InversePairsCore(copy, data, start, start + length);
		long long right = InversePairsCore(copy, data, start + length + 1, end);

		int i = start + length;
		int j = end;
		int indexcopy = end;
		long long count = 0;
		while (i >= start&&j >= start + length + 1)
		{
			if (data[i]>data[j])
			{
				copy[indexcopy--] = data[i--];
				count = count + j - start - length;          //count=count+j-(start+length+1)+1;
			}
			else
			{
				copy[indexcopy--] = data[j--];
			}
		}
		for (; i >= start; i--)
			copy[indexcopy--] = data[i];
		for (; j >= start + length + 1; j--)
			copy[indexcopy--] = data[j];
		return left + right + count;
	}
};

void TestFunc(){
	vector<int> array = { 364, 637, 341, 406, 747, 995, 234, 971, 571, 219, 993, 
		407, 416, 366, 315, 301, 601, 650, 418, 355, 460, 505, 360, 965, 516, 648, 
		727, 667, 465, 849, 455, 181, 486, 149, 588, 233, 144, 174, 557, 67, 746, 
		550, 474, 162, 268, 142, 463, 221, 882, 576, 604, 739, 288, 569, 256, 936,
		275, 401, 497, 82, 935, 983, 583, 523, 697, 478, 147, 795, 380, 973, 958,
		115, 773, 870, 259, 655, 446, 863, 735, 784, 3, 671, 433, 630, 425, 930, 
		64, 266, 235, 187, 284, 665, 874, 80, 45, 848, 38, 811, 267, 575 };
	/*vector<int> array = { 1,2,3,4,5,6,7,0};*/
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