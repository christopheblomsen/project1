#include <chrono>
#include <armadillo>
#include <math.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>
#include "utils.hpp" // todo: absolute or relativ path this (Vetle)

// function definitions
double f(double x){
    return 100.*exp(-10.*x);
}

// Same but with "numpy" vector
arma::vec f(arma::vec x){
    return 100.*exp(-10.*x);
}

// The excact solution
double u(double x){
    return (1. - (1. - exp(-10.))*x - exp(-10.*x));
}

arma::vec u(arma::vec x){
    return (1. - (1. - exp(-10.))*x - arma::exp(-10.*x));
}

// Return a string with double in scientific notation
/*
** Parameters:
** -----------
** d
**     the number to be printed
** width
**     the width of the whitespace
** prec
**     the precision of the number
 */
std::string sci_format(const double d, const int width, const int prec){
    std::stringstream ss;
    ss << std::setw(width) << std::setprecision(prec) << std::scientific << d;
    return ss.str();
}

// Return a string with an aramadillo vector in sci notation
// uses the above sci_format, but runs through the elements in it
std::string sci_format(const arma::vec& v, const int width, const int prec){
    std::stringstream ss;
    for(double elem : v){
        ss << sci_format(elem, width, prec);
    }
    return ss.str();
}

// Makes an output file
/*
** Parameters:
** -----------
** filename
**         Name of the file
** v
**         v vector
** x
**         corresponding x vector to v
** n
**         length of the vectors
** width
**         whitespace width in output
** prec
**         precision in output
 */
void output(std::string filename, const arma::vec& x, const arma::vec& u,
            const int n, int width, int prec){
    std::ofstream outfile;
    outfile.open(filename);
    // Header for the file
    outfile << "  x" << std::setw(width) << "u" << std::setw(width) << std::endl;
    // Couldn't get a pretty output without the loop, might revisit
    for (int i=0; i<n; i++){
        outfile << sci_format(x[i], width, prec) << sci_format(u[i], width, prec) << std::endl;
    }
    outfile.close();
}

// output with three coloums
void output(std::string filename, const arma::vec& x, const arma::vec& u,
            const arma::vec& v, const int n, int width, int prec){
    std::string n_string = std::to_string(n);
    std::ofstream outfile;
    outfile.open(filename);
    // Header for the file
    outfile << n_string << "x" << std::setw(width) << "u" << std::setw(width)
            << "v" << std::setw(width) << std::endl;
    // Couldn't get a pretty output without the loop, might revisit
    for (int i=0; i<n; i++){
        outfile << sci_format(x[i], width, prec) << sci_format(u[i], width, prec)
                << sci_format(v[i], width, prec) << std::endl;
    }
    outfile.close();
}

// output with three coloums + time
void output(std::string filename, const arma::vec& x, const arma::vec& u,
            const arma::vec& v, double t, const int n, int width, int prec){
    std::string n_string = std::to_string(n);
    std::ofstream outfile;
    outfile.open(filename);
    // Header for the file
    outfile << "n = " << n_string << std::endl;
    outfile << std::setw(width) << "x" << std::setw(width) << "u" << std::setw(width)
            << "v" << std::setw(width) << "t" << std::setw(width) << std::endl;
    // Couldn't get a pretty output without the loop, might revisit
    for (int i=0; i<n; i++){
        outfile << sci_format(x[i], width, prec) << sci_format(u[i], width, prec)
                << sci_format(v[i], width, prec) << sci_format(t, width, prec) << std::endl;
    }
    outfile.close();
}
// To append
void append(std::string filename, const arma::vec& v, const arma::vec& x,
            const int n, int width, int prec){
    std::ofstream outfile;
    // std::ios::app is the append
    outfile.open(filename, std::ios::app);
    for (int i=0; i<n; i++){
        outfile << sci_format(x[i], width, prec) << sci_format(v[i], width, prec) << std::endl;
    }
    outfile.close();
}

// Thomas algorithm, with built in time
void thomas_alg(int n_steps, int width, int prec, std::string basename){
    auto t1 = std::chrono::high_resolution_clock::now();
    double x_max = 1.0;
    double x_min = 0.0;

    arma::vec b_(n_steps), g_(n_steps), v(n_steps), g(n_steps);
    arma::vec x = arma::linspace(x_min, x_max, n_steps);
    arma::vec u_x = u(x);
    //double h = (x_max - x_min)/n_steps; // Using this one gives less accurate result
    double h = x(1) - x(0);

    // Initilize g
    g = h*h*f(x);
	
	// Initilize b_
	
	for (int i=1; i <= n_steps-2; i++){
		b_(i) = (i + 1.)/i;
	}
	
	// forward substitution
	g_(1) = g(1);
    for (int i=2; i <= n_steps-2; i++){
        g_(i) = g(i) + g_(i-1)/b_(i-1);
    }

    // Boundary conditions
    v(0) = 0;
    v(n_steps-1) = 0;

    // Initial v
    v(n_steps-2) = g_(n_steps-2)/b_(n_steps-2);
	
	// backwards substitution
    for (int i=n_steps-3; i>= 1; i--){
        v(i) = (g_(i) + v(i+1))/b_(i);
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    double t = std::chrono::duration<double>(t2 - t1).count();

    std::string n_string = std::to_string(n_steps);
    std::string filename = basename + "_" + n_string + ".txt" ;

    output(filename, x, u_x, v, t, n_steps, width, prec);
}

void gen_thomas_alg(int n_steps, int width, int prec, std::string basename){
    auto t1 = std::chrono::high_resolution_clock::now();
    double x_max = 1.0;
    double x_min = 0.0;

    arma::vec a(n_steps), b(n_steps), c(n_steps), g(n_steps), v(n_steps);
    arma::vec b_(n_steps), g_(n_steps);
    arma::vec x = arma::linspace(x_min, x_max, n_steps);
    arma::vec u_x = u(x);
    //double h = (x_max - x_min)/n_steps; // Using this one gives less accurate result
    double h = x(1) - x(0);
	
	// constant for optimizing the forward substitution
	double d;

    // Initilize
    a.fill(-1);
    b.fill(2);
    c.fill(-1);
    g = h*h*f(x);
    g_ = g;

    // forward substitution
    b_[0] = b[0];
    for (int i=1; i <= n_steps-1; i++){ // todo: optimize this (Vetle)
        b_[i] = b[i] - a[i]/b_[i-1]*c[i-1];
        g_[i] = g[i] - a[i]/b_[i-1]*g_[i-1];
	}

    // Boundary conditions
    v(n_steps-1) = 0;
    // v.at(0) = 0; Don't use x.at(), use x() instead. It is more safe
	// see here this link for more info: 
	// http://arma.sourceforge.net/docs.html#element_access

    // Initial v
    v(n_steps-2) = g_(n_steps-2)/b_(n_steps-2); // todo: .at or not (), (Vetle)
	
    // backwards substitution
    for (int i=n_steps-2; i>= 1; i--){
        v.at(i) = (g_(i) - c(i)*v(i+1))/b_(i);
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    double t = std::chrono::duration<double>(t2 - t1).count();

    std::string n_string = std::to_string(n_steps);
    std::string filename = basename + "_" + n_string + ".txt" ;

    output(filename, x, u_x, v, t, n_steps, width, prec);
}
