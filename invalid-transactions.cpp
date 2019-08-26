//    2019年8月26日 
//    leetcode第151周赛第1题   https://leetcode-cn.com/contest/weekly-contest-151/problems/invalid-transactionsinvalid-transactions/ 

如果出现下述两种情况，交易 可能无效：

交易金额超过 ¥1000
或者，它和另一个城市中同名的另一笔交易相隔不超过 60 分钟（包含 60 分钟整）
每个交易字符串 transactions[i] 由一些用逗号分隔的值组成，这些值分别表示交易的名称，时间（以分钟计），金额以及城市。

给你一份交易清单 transactions，返回可能无效的交易列表。你可以按任何顺序返回答案。

示例 1：
输入：transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
输出：["alice,20,800,mtv","alice,50,100,beijing"]
解释：第一笔交易是无效的，因为第二笔交易和它间隔不超过 60 分钟、名称相同且发生在不同的城市。同样，第二笔交易也是无效的。

示例 2：
输入：transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
输出：["alice,50,1200,mtv"]

示例 3：
输入：transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
输出：["bob,50,1200,mtv"]

bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    int str2int(string str) {
        istringstream is(str);
        int i;
        is >> i;
        return i;
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        map<string, vector<vector<int>>> m;
        int del[1001];
        memset(del, 0, sizeof(del));
        string cities[1001];

        for (int i = 0; i < transactions.size(); i++) {
            int len = transactions[i].size();
            int j = 0;
            string name = "", time = "", amount = "", city = "";
            for (; j < len; ++j) {
                if (transactions[i][j] == ',')
                    break;
                name += transactions[i][j];
            }
            for (j++; j < len; ++j) {
                if (transactions[i][j] == ',')
                    break;
                time += transactions[i][j];
            }
            for (j++; j < len; ++j) {
                if (transactions[i][j] == ',')
                    break;
                amount += transactions[i][j];
            }
            if (str2int(amount) > 1000) {
                del[i] = 1;
            }
            for (j++; j < len; ++j) {
                if (transactions[i][j] == ',')
                    break;
                city += transactions[i][j];
            }
            cities[i] = city;
            m[name].push_back({ str2int(time), i });
        }

        for (auto it : m) {
            sort(it.second.begin(), it.second.end(), cmp);
            vector<vector<int>> nums = it.second;
            int len = it.second.size();
            for (int i = 0; i < len - 1; ++i) {
                int time1 = it.second[i][0], idx1 = it.second[i][1];
                for (int j = i + 1; j < len; ++j) {
                    int time2 = it.second[j][0], idx2 = it.second[j][1];
                    if (time2 - time1 > 60)
                        break;
                    if (time2 - time1 <= 60 && cities[idx2] != cities[idx1]) {
                        del[idx1] = 1;	del[idx2] = 1;
                    }
               }
            }
        }
        vector<string> strs;
        for (int i = 0; i < transactions.size(); ++i) {
            if (del[i])
                strs.push_back(transactions[i]);
        }
        return strs;
    }
};
