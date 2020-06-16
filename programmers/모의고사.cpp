#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int num1[] = { 1,2,3,4,5 };
    int num2[] = { 2,1,2,3,2,4,2,5 };
    int num3[] = { 3,3,1,1,2,2,4,4,5,5 };
    int cnt[3] = { 0, };
    int cnt_max;
    int ans_size = answers.size();
    
    for (int i = 0; i < ans_size; i++) {
        if (answers[i] == num1[i % 5]) cnt[0]++;
        if (answers[i] == num2[i % 8]) cnt[1]++;
        if (answers[i] == num3[i % 10]) cnt[2]++;
    }

    cnt_max = max({cnt[0],cnt[1],cnt[2]});

    for (int i = 0; i < 3; i++) {
        if (cnt_max == cnt[i]) answer.push_back(i+1);
    }

    //vector print test
    int size = answer.size();
    for (int i = 0; i < size; i++) {
        cout << answer[i] << endl;
    }

    return answer;
}