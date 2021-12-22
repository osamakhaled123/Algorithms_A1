#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {

    int n,i,x,y;
    cin>>n;

    double min_distance;
    vector<pair<int,int>> points(n);
    for(i=0;i<n;i++){
        cin>>x>>y;
        points[i].first = x;
        points[i].second = y;
    }

    sort(points.begin(),points.end());

    pair<int,int> final_1;
    pair<int,int> final_2;

    min_distance = sqrt(pow(points[0].first-points[1].first,2) + pow(points[0].second-points[1].second,2));
    final_1 = points[0];
    final_2 = points[1];


    for(i=0;i<n-2;i++){

        if(min_distance > sqrt(pow(points[i].first-points[i+1].first,2)
                                    + pow(points[i].second-points[i+1].second,2)))
        {
                min_distance = sqrt(pow(points[i].first-points[i+1].first,2)
                                    + pow(points[i].second-points[i+1].second,2));
                final_1 = points[i];
                final_2 = points[i+1];
        }

        if(min_distance > sqrt(pow(points[i].first-points[i+2].first,2)
                               + pow(points[i].second-points[i+2].second,2)))
        {
            min_distance = sqrt(pow(points[i].first-points[i+2].first,2)
                                + pow(points[i].second-points[i+2].second,2));

            final_1 = points[i];
            final_2 = points[i+2];
        }

        if(min_distance > sqrt(pow(points[i+1].first-points[i+2].first,2)
                               + pow(points[i+1].second-points[i+2].second,2)))

        {
            min_distance = min_distance > sqrt(pow(points[i+1].first-points[i+2].first,2)
                                               + pow(points[i+1].second-points[i+2].second,2));

            final_1 = points[i+1];
            final_2 = points[i+2];
        }


    }

    cout<<"\nThe closest pair points are ("<<final_1.first<<","<<final_1.second<<") and ("<<
    final_2.first<<","<<final_2.second<<")\n";
    cout<<"The distance between this pair is: "<<min_distance<<"\n";


}
