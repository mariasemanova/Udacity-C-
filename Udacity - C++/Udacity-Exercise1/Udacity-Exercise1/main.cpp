//
//  main.cpp
//  Udacity-Exercise1
//
//  Created by Maria Semanova on 19/10/2021.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <double> sense(vector <double> p, string Z, vector <string> world, double pHit, double pMiss);
vector <double> move(vector <double> p, int U, double pExact, double pOvershoot, double pUndershoot);
void print_probability(vector <double> p);

int main() {
    // insert code here...
    vector <double> p (5, 0.2);
    vector <string> world;
    vector <string> measurements;
    vector <int> motions(2,1);
    
    world.push_back("green");
    world.push_back("red");
    world.push_back("red");
    world.push_back("green");
    world.push_back("green");
    
    measurements.push_back("red");
    measurements.push_back("green");
    
    double pHit = 0.6;
    double pMiss = 0.2;
    double pExact = 0.8;
    double pOvershoot = 0.1;
    double pUndershoot = 0.1;
    
    for ( int i =0; i < measurements.size(); i++){
        p = sense(p, measurements[i], world, pHit, pMiss);
        p = move(p, motions[i],pExact, pOvershoot, pUndershoot);
    }
    
    print_probability(p);
    
    return 0;
}

vector <double> sense(vector <double> p, string Z, vector <string> world, double pHit, double pMiss){
    vector <double> q (p.size());
    bool hit;
    double s =0 ;
    
    for( int i = 0; i < p.size(); i++){
        hit = (Z == world[i]);
        q[i] = p[i] * (hit * pHit + (1 - hit) * pMiss);
        s += q[i];
        }
    for (int i = 0; i < q.size(); i++){
        q[i] = q[i]/s;
    }
    return q;
}

vector <double> move(vector <double> p, int U, double pExact, double pOvershoot, double pUndershoot){
    vector <double> q (p.size());
    double s = 0;
    for(int i = 0; i < p.size(); i++){
        if ( i-U < 0){
            s = pExact * p[(i-U) + p.size()];
        }
        else {
            s = pExact * p[(i-U) + p.size()];
        }
        if ( i-U-1 < 0){
            s = s + pOvershoot * p[(i-U+1) + p.size()];
        }
        else {
            s = s + pOvershoot * p[(i-U+1) + p.size()];
        }
        q[i] = s;
    }
    return q;
}

void print_probability(vector <double> p){
    
    for ( int i=0; i < p.size(); i++){
        cout << p[i] << " ";
    }
}
