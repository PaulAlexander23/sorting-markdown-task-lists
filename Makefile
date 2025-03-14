my_sorter: my_sorter.cc

check: my_sorter
	./my_sorter test_sorter.md > actual_sorter.md
	diff actual_sorter.md expected_sorter.md
