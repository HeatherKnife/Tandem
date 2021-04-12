#include <iostream>
#include <string>
#include <utility>
#include <float.h>
#include <stdint.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void display(double *array)
{
	size_t size = sizeof(array)+1.;

    for(size_t i = size; i--;)
    	{
			std::cout << array[i] << std::endl;
    	}
}


//Para testear como sacar la posicion del algun punto en el puntero que contiene el pulso

/*void print(initializer_list<int> ia)
{
    auto p = begin(ia);
    while(p != end(ia))
        cout<<*p++<<'\t';
}*/


void Element( int *arr, int n, int elem )
{
	auto itr = find(arr, arr + n, elem);

	if (itr != end(arr)) {

        cout << "Element " << elem << " is present at index "
            << distance(arr, itr) << " in the given array";
    }
    else {

        cout << "Element is not present in the given array";
    
    }
}




int main()
{
	float del = 3.5;
	for(int m = 0; m < 10; ++m)
	{
		if ( m <= del)
		{
			printf("Green %f  %3d\n", del, m);
		}
		else
		{
			printf("Red %f  %3d\n", del, m);
		}
	}


	int l=0;

	if(l){
		printf("True %3d\n", l);
	}

	int w = 6;

	if (w == 0 || w < 5 || w == 6)
	{
		printf("Green\n");		
	}

	double array1[9] = {-9.4, -7.3, -5.2, -2.5, 0., 2.3, 6.7, 8.8, 10.6};
	double array2[9] = {0};
	double delay = 1.7;

	for(int j = 0; j < 9; j++) 
		{
			array2[j] = array1[j]*0.5 + delay;
		}

	const int size1 = sizeof(array1)/sizeof(array1[0]);
	const int size2 = sizeof(array2)/sizeof(array2[0]);

	std::cout << size1 << " " << size2 << std::endl;

	display(array1);
	display(array2);

	double Threshhold = 6.0;
	std::vector<double> trigs;



	for (int i = 0; i < size1-1; i++) {
		std::cout << "counter " << i << std::endl;
		if (array2[i] < 0 && array2[i+1] > 0) { //if signal crosses 0 (positive edge)
			std::cout << array2[i] << " " << array2[i+1] << std::endl;
			int t = i;

			if(array1[t] > Threshhold || array1[t+1] > Threshhold || array1[t+2] > Threshhold) { //check threshold
				std::cout << array1[t] << " " << array1[t+1] << " " << array1[t+2] << std::endl;

				if(array2[t+1]==array2[t]) {
					trigs.push_back( 0.5*(array1[t+1] + array1[t+2]) - delay*array1[1] );

					for (std::vector<double>::const_iterator i = trigs.begin(); i != trigs.end(); ++i)
				    std::cout << "triigg " << *i << ' ';

				} else {
					trigs.push_back( array1[t+1]
				- ( array1[t+2] - array1[t+1] ) * array2[t] / (array2[t+1] - array2[t]) - delay*array1[1] );
					
					for (std::vector<double>::const_iterator i = trigs.begin(); i != trigs.end(); ++i)
				    std::cout << "triigg " << *i << ' ';
				};

				//if( trigs.size()>1 && (trigs.back()-trigs.at(trigs.size()-2))<Deadtime) trigs.pop_back();

				while(array2[i+1]>=0 && i<size1-1) { //signal must return to zero before finding the next trigger
					i++;
				}
			}
		};
	}

   int arr[] = { 6, 3, 5, 2, 8 };
   int n = sizeof(arr)/sizeof(arr[0]);
   int elem = 8;

   Element( arr, n, elem );

	return 0;
}




