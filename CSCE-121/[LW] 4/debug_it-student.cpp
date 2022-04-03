//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                              DEBUG IT! LAB                               //
//                           debug_it-student.cpp                           //
//                                                                          //
// Written By : Michael R. Nowak        Environment : Mac OS X 10.10.5      //
// Date ......: 2017/05/16              Compiler ...: Homebrew GCC 6.3.0_1  //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <iomanip>
using namespace std;

constexpr int NO_TEMPS = 10;
//int argc, char * argv[]
int main ()
{
    char delim = '\n';
    std::default_random_engine d_engine{};
    std::normal_distribution<> temp_dist{32, 2};
    vector< double > ftemps;  
    int i;
    for (i = 0; i < NO_TEMPS; ++i) {
        ftemps.push_back(temp_dist(d_engine));
    }
    vector<double> ctemps;
    for (decltype(ftemps.size()) i = 0; i < ftemps.size(); ++i){
        double a = double(5)/double(9);
        double ctemp = ((ftemps.at(i) - 32) * a);
        ctemps.push_back(ctemp);
    }
    double min = ctemps.at(0); 
    double max = ctemps.at(0);
    for (decltype(ctemps.size()) i = 0; i < ctemps.size(); ++i){
        if (min > ctemps.at(i)){
            min = ctemps.at(i);
        }
        if (max < ctemps.at(i)){
            max = ctemps.at(i);
        }
        cout << "[" << i << "]" <<  " " << std::fixed << std::setprecision(3) << ftemps.at(i) << " to " << std::fixed << std::setprecision(3) << ctemps.at(i) << delim;
    }
    cout << "Max Temp (in celsius) : " << std::fixed << std::setprecision(3) << max << '\t' << "Min Temp (in celsius) : " << std::fixed << std::setprecision(3) << min << endl;
    return 0;
}