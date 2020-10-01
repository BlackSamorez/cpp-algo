void print_no_space(char * text) {
	while (*text != 0) {
		if (*text != ' ') {
			cout << static_cast<char>(tolower(*text));
		}
		++text;
	}
}