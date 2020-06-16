#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participants, vector<string> completions) {
    string answer = "";

    sort(participants.begin(), participants.end());
    sort(completions.begin(), completions.end());
    
    for (unsigned int i = 0; i < completions.size(); i++) {
        if (participants[i] != completions[i]) {
            answer = participants[i];
            return answer;
        }
    }

    answer = participants.back();

    return answer;
}

int main()
{
    vector<string> participant(
        {
            "leo",
            "kiki",
            "eden"
        }
    );
    vector<string> completion(
        {
            "eden",
            "kiki"
        }
    );

    cout << "answer : " << solution(participant, completion) << endl;

    return 0;
}