# FYS4150 project 1

## The following structure is that one can find the codes in `code` directory and latex in `report`.

### Compiling

#### `C++` code
To compile the `C++` code we use. 

```
g++ -I include src/utils.cpp main.cpp -o main
./main N
```
Where `N` is the corresponding power of $10$ e.g $10^{N}$. 
This will produce `.txt` files for both the general and special algorithms used. 
And has the following structure.

```
x     u     v     t
x1    u1    v1    t1
.     .     .     .
xN    uN    vN    tN
```

These can then be used to load in with `numpy` and plotted in the plotting scripts `plot2.py`, `plot7.py` and `plot8.py`. 

#### Report
To compile the report if for some reason the `pdf` file doesn't work.
```
pdflatex main
```
