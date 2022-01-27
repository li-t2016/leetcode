#include <iostream>
#include <vector>
#include <random>
#include <cmath>

using namespace std;

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        this -> radius = radius;
        this -> x_center = x_center;
        this -> y_center = y_center;

        this -> uniformDistAngle = uniform_real_distribution<double>(0, 2 * M_PI);
        this -> uniformDistRadius = uniform_real_distribution<double>(0, radius * radius);
        this -> re = default_random_engine();
    }
    
    vector<double> randPoint() {
        vector<double> res = GenerateRandomRadiusAndAngle();
        res[0] = sqrt(res[0]);

        return {x_center + res[0] * cos(res[1]), y_center + res[0] * sin(res[1])};
    }

private:
    double radius;
    double x_center, y_center;
    uniform_real_distribution<double> uniformDistAngle;
    uniform_real_distribution<double> uniformDistRadius;
    default_random_engine re;

    vector<double> GenerateRandomRadiusAndAngle(){
        return {uniformDistRadius(re), uniformDistAngle(re)};
    }
};

int main(){
    cout << sin(1.5 * M_PI) << endl;

    return 0;
}