#include <iostream>
#include <vector>


using namespace std;

// AERSP 424 Homework 1: Question 9
// Goal: Create classifier software to determine engine type


double dot_product(vector<double> w, vector<double> x) //dot product function, 

//two vectors w and z passed into function
{
	double result = 0; //start the result at zero, then values will be added 
	//to it zero the for loop.
	for (int i = 0; i < w.size(); i++) //both vectors will be same size, so run
		//loop for number of elements within vectors
	{
		result += w[i] * x[i]; //new result is equal to the original result 
		//plus the product of w*x (dot product is multiplying respective terms
		//and adding the products of the terms together
	}
	return result; //returns result of function to main 

}

double y_predict = 0;
double sigmoid(double z) //sigmoid function
{
	y_predict = 1 / (1 + exp(-z)); //function given in doc
	return y_predict; //return value calculated for sigma
}

