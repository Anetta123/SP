/*  IAV   */
#include "mlisp.h"
double largest/*1*/ (double coins__set);
	double count__change/*13*/ (double amount);
	bool Shaeffer_Q/*27*/ (double x_Q, double y_Q);
	 double cc/*31*/ (double amount, double coins__set);
	double denomination__list/*39*/ (double coins__set);
	extern double VARIANT/*46*/;
	extern double COINS/*47*/;
	//________________ 
double largest/*1*/ (double coins__set){
 return
 ((coins__set == 1.) 
	? 1. 
	 :(coins__set == 2.) 
	? 2. 
	 :(coins__set == 3.) 
	? 3. 
	 :(coins__set == 4.) 
	? 5. 
	 :(coins__set == 5.) 
	? 10. 
	 :(coins__set == 6.) 
	? 15. 
	 :true 
	? 0.
	 : _infinity);
	 }
double count__change/*13*/ (double amount){
 display("______");
	 newline();
	 display(" amount: ");
	 display(amount);
	 newline();
	 display("COINS: ");
	 display(COINS);
	 newline();
	 return
 (( (0. >= amount) || !((COINS >= 1.)) || (largest(COINS) == 0.) ) 
	? (display("Improper parameter value!")
	 , newline()
	 , display("count-change= ")
	 , -1.) 
	 :true 
	? (display("List of coin denominations: ")
	 , denomination__list(COINS)
	 , display("count-change= ")
	 , cc(amount, COINS))
	 : _infinity);
	 }
bool Shaeffer_Q/*27*/ (double x_Q, double y_Q){
 return
 ( !(x_Q) || !(y_Q) );
	 }
double cc/*31*/ (double amount, double coins__set){
 return
 ((amount == 0.) 
	? 1. 
	 :Shaeffer_Q((amount >= 1.),  !((0. >= coins__set))) 
	? 0. 
	 :true 
	? (cc(amount, (coins__set - 1.)) + cc((amount - largest(coins__set)), coins__set))
	 : _infinity);
	 }
double denomination__list/*39*/ (double coins__set){
 return
 ((coins__set == 0.) 
	? (newline()
	 , 0.) 
	 :true 
	? (display(largest(coins__set))
	 , display(" ")
	 , denomination__list((coins__set - 1.)))
	 : _infinity);
	 }
double VARIANT/*46*/ = 8.;
	double COINS/*47*/ = 6.;
	int main(){
display("Variant ");
	 display(VARIANT);
	 newline();
	 display(count__change(100.));
	 newline();
	 COINS = 13.;
	 display(count__change(100.));
	 newline();
	 display("(c) Anna Ivchenko 2022");
	 newline();
	 std::cin.get();
 return 0;
}

