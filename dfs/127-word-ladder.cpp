//
// Created by 成翔昊 on 2020/7/11.
//

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iterator>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 如果wordList太长会超出时间限制
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        const int size = wordList.size();
        if (size == 0) return 0;
        if (find(wordList.begin(),wordList.end(), endWord)==wordList.end()) return 0;

        this->beginWord = beginWord;
        this->endWord = endWord;
        this->wordList = wordList;

        vector<string> path;
        unordered_set<string> visited;
        int min_step = wordList.size() + 1;

        dfs(visited, path, beginWord, min_step);
        return min_step > wordList.size() ? 0 : min_step + 1;
    }

private:
    void dfs(unordered_set<string> &visited, vector<string> &path, string &prev, int &min_step) {
        if (prev==endWord) {
            min_step = min(min_step, int(path.size()));
            return;
        }
        for (int i = 0; i < wordList.size(); i++) {
            // 未访问且可达
            if (visited.find(wordList[i]) == visited.end() && reachable(prev, wordList[i])) {
                path.push_back(wordList[i]);
                visited.insert(wordList[i]);
                prev = wordList[i];
                dfs(visited, path, prev, min_step);
                path.pop_back();
                visited.erase(wordList[i]);
                prev = path.empty() ? beginWord : path.back();
            }
        }
    }

    bool reachable(const string &from, const string &to) {
        if (from.size() != to.size()) return false;
        int count = 0;
        for (int i = 0; i < from.size(); i++) {
            if (from[i] != to[i]) count++;
            if (count > 1) return false;
        }
        return count == 1;
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