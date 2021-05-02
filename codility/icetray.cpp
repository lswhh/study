
#include <iostream>
#define MAX_GRAPH_IDX (1000)
using namespace std;

int graph[MAX_GRAPH_IDX][MAX_GRAPH_IDX];
int N,M;
int iceCount = 0;
typedef struct qitem
{
    int i;
    int j;
} qitem;
qitem queue[1000];
int queueAddPos = 0;
int queuePointer = 0;
void addQ(int i, int j)
{
    queue[queueAddPos].i = i;
    queue[queueAddPos].j = j;
    queueAddPos++;
}
qitem * getQ()
{
    qitem * sResult;
    if (queueAddPos <= queuePointer)
    {
        sResult = NULL;
    }
    else
    {
        sResult = &(queue[queuePointer]);
        queuePointer++;
    }
    return sResult;
}
void bfs(int i, int j)
{
    qitem * sItem = NULL;
    int x, y;
    if ( graph[i][j] == 1 )
    {
        return; 
    }
    else
    {
        iceCount++;
        graph[i][j] = 1; //방문처리
        addQ(i,j);
        sItem = getQ();
        while ( sItem != NULL )
        {
            if ( ( sItem->j - 1 ) > 0 ) //좌
            {
                if ( graph[sItem->i][sItem->j - 1] == 0 )
                {
                    graph[sItem->i][sItem->j - 1] = 1; //방문
                    addQ(sItem->i, sItem->j - 1);
                }
            }
            if ( ( sItem->j + 1 ) < M ) //우
            {
                if ( graph[sItem->i][sItem->j + 1] == 0 )
                {
                    graph[sItem->i][sItem->j + 1] = 1; //방문
                    addQ(sItem->i, sItem->j + 1);
                }
            }
            if ( ( sItem->i - 1 ) > 0 ) //상
            {
                if ( graph[sItem->i - 1][sItem->j] == 0 )
                {
                    graph[sItem->i - 1][sItem->j] = 1; //방문
                    addQ(sItem->i - 1 , sItem->j);
                }
            }
            if ( ( sItem->i + 1 ) < N ) //하
            {
                if ( graph[sItem->i + 1][sItem->j] == 0 )
                {
                    graph[sItem->i + 1][sItem->j] = 1; //방문
                    addQ(sItem->i + 1 , sItem->j);
                }
            }
            sItem = getQ();
        }
    }
    return;
}
int main()
{

    cin >> N >> M;
    cout << N << " " << M << endl;

    // 2차원 리스트의 맵 정보 입력 받기
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            scanf("%1d", &graph[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            bfs(i,j);
        }
    }
    cout << iceCount << endl;

    return 0;
}