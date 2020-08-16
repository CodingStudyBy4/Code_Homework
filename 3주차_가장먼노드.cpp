#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

vector<int> tmp[20001];
int visit[20001];
queue<int> q;

int solution(int n, vector<vector<int>> edge) {

    //visit 초기화
    for (int i = 0; i <= 20000; i++)
        visit[i] = -1;

    //그래프 형태로 자료구조 형성.
    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        tmp[a].push_back(b);
        tmp[b].push_back(a);
    }

    //test print
    /*for (int i = 1; i <= n; i++) {
        if (tmp[i].empty())
            continue;
        for (int j = 0; j < tmp[i].size(); j++)
            cout << tmp[i][j] << " ";
        cout << endl;
    }*/

    visit[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < tmp[node].size(); i++) {
            if (visit[tmp[node][i]] == -1) {
                q.push(tmp[node][i]);
                visit[tmp[node][i]] = visit[node] + 1;
            }
        }
    }
    
    //test print for visit array
    /*for (int i = 1; i <= n; i++)
        cout << visit[i] << " ";
    cout << endl;*/
    
    int mx = -1;
    int mx_cnt;
    for (int i = 1; i <= n; i++) {
        if (visit[i] > mx) {
            mx = visit[i];
            mx_cnt = 1;
        }
        else if (visit[i] == mx)
            mx_cnt++;
    }

    return mx_cnt;
}

int main()
{
    vector<vector<int>> edge = { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} };
    int n = 6;
    /*for (int i = 0; i < edge.size(); i++) {
        if (edge[i].empty())
            continue;
        for (int j = 0; j < edge[i].size(); j++)
            cout << edge[i][j] << " ";
        cout << endl;
    }*/
    cout << solution(n, edge) << endl;
    return 0;
}