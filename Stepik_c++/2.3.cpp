void rotate(int a[], unsigned size, int shift)
{
	int mod_shift = shift % size;
	if (mod_shift == 0) return;
	for (int i = size - 1; i >= mod_shift; --i)
		for (int j = size - 1; j > 0; --j)
		{
			int temp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = temp;
		}
}
