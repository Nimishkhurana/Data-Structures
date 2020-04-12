#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

std::string extract_string(std::string &input)
{
	std::string output = "";
	for (char c : input)
	{
		if (c != ',')
			output += c;
		else
			break;
	}
	input.erase(0, output.length() + 1);
	return output;
}

int numVal(std::string A)
{
	std::unordered_map<char, int> map;
	char smallest = A[0];
	for (char c : A)
	{
		if (int(c) < smallest)
			smallest = c;
		map[c]++;
	}
	return map[smallest];
}

std::vector<int> strictly_less(std::string A, std::string B)
{
	std::vector<int> ret, setA, setB, numBelow(11, 0);

	while (A != "")
		setA.push_back(numVal(extract_string(A)));
	while (B != "")
		setB.push_back(numVal(extract_string(B)));

	for (int i : setA){
        for (int j = i + 1; j < numBelow.size(); j++)
			numBelow[j]++;
        // cout<<i<<" ";
    }
		

	for (int i : setB)
		ret.push_back(numBelow[i]);

	return ret;
}

int main(){
    string A,B;
    getline(cin,A);
    getline(cin,B);

    vector<int> res = strictly_less(A,B);
    for(auto x: res){
        cout<<x<<" ";
    }
}