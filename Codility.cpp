// Codility.cpp : Defines the entry point for the console application.
// 2018.05.14 add to github test
// 2018.05.14 test after push failed 

#include "stdafx.h"
// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int solution_7_1(vector<int> &H);
int solution_7_2(vector<int> &A, vector<int> &B);
int solution_7_3(string &S);
int solution_17_2(vector<int> &A);

int solution(vector<int> &A, vector<int> &B);

int main()
{
	//test 7.2
	//int A[] = {4,3};
	//int B[] = {1,0};
	//vector<int> AA(A, A + sizeof(A) / sizeof(int));
	//vector<int> BB(B, B + sizeof(B) / sizeof(int));
	//int r = solution_7_2(AA,BB);
	//cout << "fish left:" << r << endl;

	//// test 7.3
	//std::string S = "(()(()()))";
	//int r = solution_7_3(S);
	//cout << std::boolalpha;
	//cout << " is properly nested? " << r << endl;

	// test 17.2
	int A[] = { 1,2,5,-2 };
	vector<int> AA(A, A + sizeof(A) / sizeof(int));
	int r = solution_17_2(AA);
	cout << r << endl;
    return 0;
}



// 7.3 parenthesis, 100% 75% Correctness
//▶ broad_tree_with_deep_paths
//string of the form(TTT...T) of 300 T's, each T being '(((...)))' nested 200-fold, length=1 million ✘RUNTIME ERROR 
//tested program terminated with exit code 1
//1. 0.012 s RUNTIME ERROR, tested program terminated with exit code 1
//stderr:
//Segmentation Fault
//2. 0.001 s OK

int solution_7_3(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	if (!S.length()) return 1;
	if (S.length() < 2 || S.length() % 2) return 0;

	stack<char> P;
	P.push(S[0]);
	char top;
	for (unsigned int i = 1; i < S.length(); i++) {
		top = P.top();
		if (top == '(' && S[i] == ')') P.pop();
		else P.push(S[i]);
	}
	return !P.size();
}

// 7.2 fish, correctness: 100% Performace: 75%
//▶ extreme_range1
//all except one fish flowing in the same direction ✘RUNTIME ERROR
//tested program terminated with exit code 1
//1. 0.012 s RUNTIME ERROR, tested program terminated with exit code 1
//stderr:
//Segmentation Fault
//2. 0.008 s OK
int solution_7_2(vector<int> &A, vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)
	int cnt = A.size();

	if (cnt < 2) return cnt;

	struct fish { int a;int b; };
	stack<fish> river;

	fish head = {A[0], B[0]};
	river.push(head);
	
	fish next;
	fish prev;

	for (int i = 1; i < cnt; i++) {
		next.a = A[i], next.b = B[i];
		prev = river.top();

		// 0, whatever
		if (!prev.b) {
			river.push(next);
			continue;
		}

		// 1 , 0
		while(prev.b != next.b && i<cnt){
		
			if (prev.a < next.a) {
				river.pop();
				prev = river.top();
				continue;
			}
			else {
				i++;
				if (i == cnt) break;
				next.a = A[i], next.b = B[i];
			}
		}

		if (i < cnt)
			river.push(next);

	}
	return river.size();

}

// 7.1 StoneWall Correctness 100%, Performance 11%
int solution_7_1(vector<int> &H) {
	// write your code in C++14 (g++ 6.2.0)
	if (H.size() == 0) return 0;
	if (H.size() == 1) return 1;

	int brk = 1, i = 1, j = 0;


	vector<int> stack;
	vector<int>::iterator L;
	L = H.begin();

	vector<int>::iterator it;
	it = H.begin();
	it++;
	//cout << "i:" << H[0] << "  brks: " << brk<< endl;
	for (i = 1; it != H.end(); it++, i++) {

		//if (H[i]==0) return 0;
		if (H[i] == H[i - 1]) {
			continue;
		}
		else if (H[i] > H[i - 1]) {
			stack.push_back(H[i]);
			j++;
			brk++;
		}
		else
		{
			while (j>1 && H[i] < stack[j - 1]) {
				stack.pop_back();
				j--;
			}

			if (j>0 && H[i] == stack[j - 1]) {
				continue;
			}
			//if (std::find(L, it, H[i])!=it) continue;
			stack.push_back(H[i]);
			j++;
			brk++;

		}

		//cout << "i:" << H[i] << "  brks: " << brk<< endl;

	}

	return brk;
}

// 7.1 StoneWall Correctness 100%, Performance 11%

int solution1(vector<int> &H) {
	// write your code in C++14 (g++ 6.2.0)
	if (H.size() == 0) return 0;
	if (H.size() == 1) return 1;

	int brk = 1, i = 1;

	vector<int>::iterator L;
	L = H.begin();

	vector<int>::iterator it;
	it = H.begin();
	it++;
	for (i = 1; it != H.end(); it++, i++) {

		if (H[i] == 0) return 0;
		if (H[i] == H[i - 1]) {
			continue;
		}
		else if (H[i] > H[i - 1]) {
			brk++;
		}
		else
		{
			if (std::find(L, it, H[i]) != it) continue;

			brk++;
			if (H[i] < *L) {
				L = it;
			}

		}
	}

	return brk;
}



int solution_17_2(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
}
