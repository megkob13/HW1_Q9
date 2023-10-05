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

int main()
{
	vector<double> w = { 0.095902, -.20531, -.000185721 }; //w vector from question 8

	//given information about aircraft
	vector<double> x_SF50Vision = { 87.0, 38.67, 6.00 };
	vector<double> x_208Caravan = { 79.0, 52.08,8.0 };
	vector<double> x_AeroL29Delfin = { 92.0, 33.75, 7.804 };
	vector<double> x_AT802U = { 91.0, 59.25,16.00 };

	//dot product with w vector to get z for sigmoid equation
	double z_SF50Vision = dot_product(w, x_SF50Vision);
	double z_208Caravan = dot_product(w, x_208Caravan);
	double z_AeroL29Delfin = dot_product(w, x_AeroL29Delfin);
	double z_AT802U = dot_product(w, x_AT802U);

	//call calculated zs into sigmoid equation to get predicted y for each aircraft
	double y_predicted_SF50Vision = sigmoid(z_SF50Vision);
	double y_predicted_208Caravan = sigmoid(z_208Caravan);
	double y_predicted_AeroL29Delfin = sigmoid(z_AeroL29Delfin);
	double y_predicted_AT802U = sigmoid(z_AT802U);

	//if else statements for each aircraft

	if (y_predicted_SF50Vision > 0.5)
		cout << "SF50 Vision uses a jet engine." << endl; //true
	else
		cout << "SF50 Vision uses a turboprop engine." << endl;


	if (y_predicted_208Caravan > 0.5)
		cout << "208 Caravan uses a jet engine." << endl;
	else
		cout << "208 Caravan uses a turboprop engine." << endl; //true


	if (y_predicted_AeroL29Delfin > 0.5)
		cout << "Aero L-29 Delfin uses a jet engine." << endl; //true
	else
		cout << "Aero L-29 Delfin uses a turboprop engine." << endl;


	if (y_predicted_AT802U > 0.5)
		cout << "AT-802U uses a jet engine." << endl;
	else
		cout << "AT-802U uses a turboprop engine." << endl; //true

	return 0;
}