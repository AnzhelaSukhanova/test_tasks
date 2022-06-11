struct Cls {
	Cls(char c, double d, int i) : c(c), d(d), i(i)
	{}
private:
	char c;
	double d;
	int i;
};

char &get_c(Cls &cls) {
	char *char_cls = (char *)(&cls);
	return char_cls[0];
}

double &get_d(Cls &cls) {
	double *double_cls = (double *)(&cls);
	return double_cls[1];
}

int &get_i(Cls &cls) {
	int *int_cls = (int *)(&cls);
	return int_cls[4];
}
