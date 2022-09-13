#ifndef __utils_hpp__
#define __utils_hpp__

#include <armadillo>
#include <sstream>
#include <string>
#include <iomanip>
#include <fstream>

double f(double x);

arma::vec f(arma::vec x);

double u(double x);

arma::vec u(arma::vec x);

std::string sci_format(const arma::vec&, const int width, const int prec);

std::string sci_format(const double d, const int width, const int prec);

void output(std::string filename, const arma::vec& x, const arma::vec& u,
           const int n, int width, int prec);

void output(std::string filename, const arma::vec& x, const arma::vec& u,
            const arma::vec& v, const int n, int width, int prec);

// Added time coloumn
void output(std::string filename, const arma::vec& x, const arma::vec& u,
            const arma::vec& v, double t, const int n, int width, int prec);

void append(std::string filename, const arma::vec& v, const arma::vec& x,
           const int n, int width, int prec);

void thomas_alg(int n, int width, int prec, std::string basename);

void gen_thomas_alg(int n, int width, int prec, std::string basename);
#endif // __utils_hpp
