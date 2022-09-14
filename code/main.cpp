// This does all of the subtasks
#include <chrono>
#include "utils.hpp"

int main(int argc, char** argv){
    // The len multiplication of 10
    int n_len = std::atoi(argv[1]);
    std::vector<double> n_arr;
    for (int i=1; i <= n_len; i++){
        n_arr.push_back(std::pow(10, i));
    }

    std::cout << n_arr.back() << std::endl;
    // For the .txt file of data
    int width = 12;
    int prec = 4;

    // The below is a shortened version of our project, look at utils.cpp
    // problem 2, problem 7 and problem 8
    // Corresponing python scripts
    std::string general_alg = "general_thomas";
    std::cout << general_alg << std::endl;
    for (int n : n_arr){
        gen_thomas_alg(n, width, prec, general_alg);
    }

    // problem 9
    std::string special_alg = "special_thomas";
    for (int n : n_arr){
        std::cout << "start" << std::endl;
        thomas_alg(n, width, prec, special_alg);
        std::cout << "end" << std::endl;

        std::string filename = "analytical.txt";

        arma::vec x = arma::linspace(0, 1, n);
        arma::vec f_x = u(x);
        output(filename, x, f_x, n, width, prec);
    }

    return 0;
}
