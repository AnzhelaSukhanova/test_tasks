#include <cstdlib>

int ** create_array2d(size_t a, size_t b)
{
	int **array = new int *[a];
	array[0] = new int[a * b];
	for (int i = 1; i < a; ++i)
		array[i] = array[i - 1] + b;
	return array;
}

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
	int **matrix = create_array2d(cols, rows);
	for (int i = 0; i < cols; ++i)
		for (int j = 0; j < rows; ++j)
			matrix[i][j] = m[j][i];
	return matrix;
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
	int min = m[0][0], min_row = 0;
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			if (m[i][j] < min)
			{
				min = m[i][j];
				min_row = i;
			}
	int *temp = m[0];
	m[0] = m[min_row];
	m[min_row] = temp;
}
