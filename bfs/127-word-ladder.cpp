//
// Created by 成翔昊 on 2020/7/11.
//

#include <iostream>
#include <string>
#include <cmath>
#include <queue>
#include <vector>
#include <iterator>
#include <unordered_set>

using namespace std;

class Solution {
private:
    struct State {
        string word;
        int step;
    };

public:
    // 使用dfs的话如果wordList太长会超出时间限制
    // 使用bfs如果str长度和wordList都很长会超出时间限制
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_set<string> visited;
        if (wordList.empty()) return 0;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        this->beginWord = beginWord;
        this->endWord = endWord;
        this->wordList = wordList;

        queue<State &> q;
        q.push(State(beginWord, 0));

        while (!q.empty()) {
            state = q.front();
            if (state.word == endWord) return state.step + 1;
            unordered_set<State> new_states;
            state_extend(new_states, state, visited);
            q.pop();
            for(auto &new_state:new_states) {
                q.push(new_state);
                visited.insert(new_state.word);
            }
        }
        return 0;
    }

private:
    void state_extend(unordered_set<State> &new_states, State &state, unordered_set<string> &visited) {
        for (int i = 0; i < state.word.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == state.word[i]) continue;
                string new_word = state.word;
                new_word[i] = c;
                // 新单词在集合中，且未被访问
                if (find(wordList.begin(), wordList.end(), new_word) != wordList.end() &&
                    visited.find(new_word) == visited.end()) {
                    State new_state(new_word, state.step + 1);
                    new_states.insert(new_state);
                }
            }
        }
    }

private:
    string beginWord;
    string endWord;
    vector<string> wordList;
};

int main() {
    auto solution = Solution();
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    cout << solution.ladderLength("hit", "cog", wordList) << endl;
}