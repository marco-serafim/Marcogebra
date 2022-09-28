// Calculus Functions

int fun_exp(double a, double x){
    double y = pow(a, x);
    return y;
}

int fun2g(double a, double b, double c, double x){
    double y = a * pow(x, 2) + b * x + c;
    return y;
}

int fun1g(double a, double b, double x){
    double y = a * x + b;
    return y;
}


// Structs for functions

struct fun_exp{
    double a;
    char *name;
};

struct fun2g{
    double a;
    double b;
    double c;
    char *name;
};

struct fun1g{
    double a;
    double b;
    char *name;
};
