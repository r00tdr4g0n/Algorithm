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

int main()
{
    vector<int> answers1;
    vector<int> answers2;
    vector<int> answer;

    answers1.push_back(1);
    answers1.push_back(2);
    answers1.push_back(3);
    answers1.push_back(4);
    answers1.push_back(5);

    answers2.push_back(1);
    answers2.push_back(3);
    answers2.push_back(2);
    answers2.push_back(4);
    answers2.push_back(2);

    //answer = solution(answers1);
    answer = solution(answers2);

    return 0;
}