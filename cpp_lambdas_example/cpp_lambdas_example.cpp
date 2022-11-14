#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

//generates vector of numbers from 0 to 100 of length l
void makeVector(int l, std::vector<int> &vec)
{
	vec.clear();
	for (int i = 0; i < l; i++)
	{
		vec.push_back(rand()%101);
	}
}

//prints vector
void printVector(std::vector<int> vec)
{
	int l = vec.size();
	for (int i = 0; i < l; i++)
	{
		printf("%d) % d; ", i+1, vec[i]);
	}
	std::cout << std::endl;
}

//function for data check
bool checkVecItem(int vecItem)
{
	return vecItem > 49;
}

int func(int a, int b) { return a + b; }

int main()
{	
	//inite RNG seed
	srand(time(NULL));


	/*
	[<capture clause>] (<arguments>) -> <return type (auto by default)>
	{
		<algorithm>
		return <return type xpression>;
	};
	*/

	std::cout << [](int a, int b) { return a + b; } (10,3) << std::endl;

	int k = 5;
	//just grab k from memory
	std::cout << [k](int a, int b) { return k + a + b; } (10, 3) << std::endl;
	
	//grab k from memory and modify
	std::cout << [k = pow(k,2)](int a, int b) { return k + a + b; } (10, 3) << std::endl;

	//lambda - in - lambda
	std::cout << [](int val)->int { return [val]() { return val + 10; }(); }(5) << std::endl;
	/*
	
	[](int val)->int { <lambda1 code> } (5)

	<lambad1 code> = return [val]() { <lambda2 code> }();

	<lambda2 code> = return val + 10;
	
	*/

	//use lambda as function pointer
	std::vector<int> vec = {};
	makeVector(10, vec);
	printVector(vec);

	int n1 = std::count_if(vec.begin(), vec.end(), *checkVecItem);
	int n2 = std::count_if(vec.begin(), vec.end(), [](int val) {return val > 49; });
	
	printf("n1 = %d; n2 = %d\n", n1, n2);

	//pass check value to lambda through capture clause
	int pass = 80;
	int n3 = std::count_if(vec.begin(), vec.end(), [pass](int val) {return val > pass; });

	printf("n3 = %d\n", n3);

}