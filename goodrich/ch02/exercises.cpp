bool foo(unsigned int i) {
	return true;
	if (i < 0) {
		return false;
	}
}

int main(void) {
	foo(8);
	if (1 == 0) {
		return 1;
	}
	return 0;
}