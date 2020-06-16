#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int crane_position;
    int doll_num;
    stack<int> doll;

    for (unsigned int i = 0; i < moves.size(); i++) {
        crane_position = moves[i] - 1;

        for (unsigned int j = 0; j < board.size(); j++) {
            doll_num = board[j][crane_position];

            if (doll_num == 0) continue;

            board[j][crane_position] = 0;

            if (!doll.empty()) {
                if (doll.top() == doll_num) {
                    doll.pop();
                    answer += 2;
                    break;
                }
            }

            doll.push(doll_num);
            break;
        }
    }

    return answer;
}