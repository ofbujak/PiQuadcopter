#include "gaussian_matrix.h"
#define M_PI 3.1415926535

matrix gauss_matrix(int variance, int matrix_size){
	matrix gaussian_matrix;
	init_matrix(&gaussian_matrix, matrix_size, matrix_size);
	float scaling_factor =  1 / ( 2 * M_PI * variance );

	for (int x=0 ; x < matrix_size ; x++ ){
		double x_element = x-((matrix_size-1)/2);
		
		for (int y=0 ; y < matrix_size ; y++ ){	
			double y_element = y-((matrix_size-1)/2);
			
			float element_X = ( (-1 * pow(x_element, 2.0 )) / (2 * variance ) );
			float element_Y = ( (-1 * pow(y_element, 2.0 )) / (2 * variance ) );
			float matrix_value = scaling_factor*(exp(element_X+element_Y));
			set_matrix_value(&gaussian_matrix, x, y, matrix_value);

		}

	}

	return gaussian_matrix;
}
