#include <iostream>
#include <fstream>
using namespace std;

int N, K;
int data[10][20];

bool better(int a, int b, int session)
{
    int apos, bpos;
    for (int i=0; i<N; i++) {
        if (data[session][i] == a) apos = i;
        if (data[session][i] == b) bpos = i;
    }
    return apos < bpos;
}

int Nbetter(int a, int b)
{
    int total = 0;
    for (int session=0; session<K; session++)
        if (better(a,b,session)) total++;
    return total;
}

int main(void)
{
    ifstream fin ("gymnastics.in");
    ofstream fout ("gymnastics.out");
    fin >> K >> N;
    for (int k=0; k<K; k++)
        for (int n=0; n<N; n++)
            fin >> data[k][n];
    int answer = 0;
    for (int a=1; a<=N; a++)
        for (int b=1; b<=N; b++)
            if (Nbetter(a,b) == K) answer++;
    fout << answer << "\n";
    return 0;
}