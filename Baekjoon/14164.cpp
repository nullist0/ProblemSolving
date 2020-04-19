#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int ret[301];
int triangle[300][300][300];

double angle(int x, int y){
    if(x > 0 && y > 0)
        return atan(y/x);
    else if(x == 0 && y > 0)
        return M_PI/2;
    else if(x < 0)
        return M_PI + atan(y/x);
    else if(x > 0 && y < 0)
        return 2 * M_PI + atan(y/x);
    else if(x == 0 && y < 0)
        return 3 * M_PI / 2;
    else 
        return 0;
}

int main(void){
    int N, x, y;
    int pi[2], pj[2], rel[2];
    int ij[2], ik[2], it[2];
    int coe[2], det, sum, trianglesInIJK;
    vector<pair<int, int> > point;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d %d", &x, &y);
        point.push_back(make_pair(x, y));
    }

    for(int i = 0; i < N; i++){
        vector<pair<double, int> > inPlane;
        pi[0] = point[i].first; pi[1] = point[i].second;
        
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            pj[0] = point[j].first; pj[1] = point[j].second;
            rel[0] = pj[0] - pi[0]; rel[1] = pj[1] - pi[1];
            inPlane.push_back(make_pair(angle(rel[0], rel[1]), j));
            inPlane.push_back(make_pair(abs(angle(rel[0], rel[1]) - M_PI), -j));
        }

        sort(inPlane.begin(), inPlane.end());

        for(int j = 0; inPlane.size(); j++){
            if(inPlane[j].second < 0) continue;

            for(int k = 0; inPlane.size(); k++){
            }
        }
    }

    return 0;
}

// int main(void){
//     int N, x, y;
//     int pi[2], pj[2], pk[2], pt[2];
//     int ij[2], ik[2], it[2];
//     int coe[2], det, sum, trianglesInIJK;
//     vector<pair<int, int> > point;

//     scanf("%d", &N);

//     for(int i = 0; i < N; i++){
//         scanf("%d %d", &x, &y);
//         point.push_back(make_pair(x, y));
//     }

//     sort(point.begin(), point.end());

//     for(int i = 0; i < N; i++){
//         for(int j = i + 1; j < N; j++){
//             for(int k = j + 1; k < N; k++){
//                 trianglesInIJK = 0;
//                 pi[0] = point[i].first; pi[1] = point[i].second;
//                 pj[0] = point[j].first; pj[1] = point[j].second;
//                 pk[0] = point[k].first; pk[1] = point[k].second;
//                 ij[0] = pj[0] - pi[0]; ij[1] = pj[1] - pi[1];
//                 ik[0] = pk[0] - pi[0]; ik[1] = pk[1] - pi[1];
                
//                 for(int t = i+1; t < k; t++){
//                     pt[0] = point[t].first, pt[1] = point[t].second;
//                     it[0] = pt[0] - pi[0]; it[1] = pt[1] - pi[1];

//                     coe[0] = it[0] * ik[1] - it[1] * ik[0];
//                     coe[1] = - it[0] * ij[1] + it[1] * ij[0];
                    
//                     det = ij[0] * ik[1] - ij[1] * ik[0];
//                     sum = abs(coe[0]) + abs(coe[1]);
                    
//                     if(coe[0] * det > 0 && coe[1] * det > 0)
//                         trianglesInIJK += (sum <= abs(det));
//                 }

//                 ret[trianglesInIJK]++;
//             }
//         }
//     }

//     for(int i = 0; i < N - 2; i++)
//         printf("%d\n", ret[i]);

//     return 0;
// }