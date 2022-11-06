/*  IAV   */
#include "mlisp.h"
double root/*2*/ (double a, double b);
	double half__interval/*14*/ (double a, double b
	 , double fa, double fb);
	double __IAV__try/*26*/ (double neg__point, double pos__point);
	bool close__enough_Q/*40*/ (double x, double y);
	 double average/*42*/ (double x, double y);
	extern double tolerance/*44*/;
	extern double total__iterations/*45*/;
	double f/*46*/ (double z);
	//________________ 
double root/*2*/ (double a, double b){
 double temp/*3*/(0.);
	temp = half__interval(a, b, f(a), f(b));
	 display("Total number of iteranions=");
	 display(total__iterations);
	 newline();
	 display("[");
	 display(a);
	 display(" , ");
	 display(b);
	 display("]");
	 return
 temp;
	 }
double half__interval/*14*/ (double a, double b
	 , double fa, double fb){
 double root/*15*/(0.);
	total__iterations = 0.;
	 root = (!(( (fa >= 0.) || (0. >= fb) )) 
	? __IAV__try(a, b) 
	 :!(( (fa >= 0.) || (fb >= 0.) )) 
	? __IAV__try(b, a) 
	 :true 
	? (b + 1.)
	 : _infinity);
	 newline();
	 return
 root;
	 }
double __IAV__try/*26*/ (double neg__point, double pos__point){
 double midpoint/*27*/(0.);
	double test__value/*28*/(0.);
	midpoint = average(neg__point, pos__point);
	 return
 (close__enough_Q(neg__point,  pos__point) 
	? midpoint 
	 :true 
	? (test__value = f(midpoint)
	 , display("+")
	 , total__iterations = (total__iterations + 1.)
	 , (!((0. >= test__value)) 
	? __IAV__try(neg__point, midpoint) 
	 :!((test__value >= 0.)) 
	? __IAV__try(midpoint, pos__point) 
	 :true 
	? midpoint
	 : _infinity))
	 : _infinity);
	 }
bool close__enough_Q/*40*/ (double x, double y){
 return
 !((abs((x - y)) >= tolerance));
	 }
double average/*42*/ (double x, double y){
 return
 ((x + y) * (1. / (* 2.0)));
	 }
double tolerance/*44*/ = 0.001;
	double total__iterations/*45*/ = 0.;
	double f/*46*/ (double z){
 return
 ((3. * z) - (4. * log(z)) - 2.95);
	 }
int main(){
display("Variant 208-08\n");
	 display(root(1.33, 2.0));
	 newline();
	 display("(c) Ivchenko Anna 2022\n");
	 std::cin.get();
 return 0;
}

