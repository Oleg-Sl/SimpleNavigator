BUILD_DIR = build
DOCS_DIR = docs
TEXI2DVI = texi2dvi


OS = $(shell uname -s)
MACOS = Darwin

ifeq ($(OS), $(MACOS))
MEMORY_TEST = leaks -atExit --
OPEN_FILE	= open
else 
MEMORY_TEST = valgrind --trace-children=yes --leak-check=yes --track-origins=yes
OPEN_FILE	= xdg-open
endif


all: s21_graph.a s21_graph_algorithms.a

clean:
	rm -rf $(BUILD_DIR)
	rm -rf s21_lcov_report

test: build
	cmake --build $(BUILD_DIR) --target test
	./$(BUILD_DIR)/tests/test

s21_graph.a: build
	cmake --build $(BUILD_DIR) --target s21_graph

s21_graph_algorithms.a: build
	cmake --build $(BUILD_DIR) --target s21_graph_algorithms

build:
	cmake -B $(BUILD_DIR)

cli: build
	cmake --build $(BUILD_DIR) --target cli
	./$(BUILD_DIR)/cli

leaks: test
	$(MEMORY_TEST) $(BUILD_DIR)/tests/test --gtest_filter=-*.Throw*

report: build
	cmake --build $(BUILD_DIR) --target rep
	$(BUILD_DIR)/s21_test
	cd $(BUILD_DIR) && lcov --capture -d . --exclude "/usr/*" -o coverage.info --ignore-errors mismatch
	genhtml $(BUILD_DIR)/coverage.info -o REPORT
# ./$(BUILD_DIR)/tests/report
# cd $(BUILD_DIR)/tests/CMakeFiles/report.dir && lcov --capture --directory . --output-file s21_coverage.info --ignore-errors version
# lcov --capture --directory $(BUILD_DIR)/tests/CMakeFiles/report.dir --output-file s21_coverage.info --exclude "/usr/*"  --ignore-errors mismatch  --ignore-errors version
# lcov --capture --directory $(BUILD_DIR)/tests/CMakeFiles/report.dir --output-file s21_coverage.info --ignore-errors version --exclude "/usr/*"  --ignore-errors mismatch
# lcov --capture -d $(BUILD_DIR)/tests/CMakeFiles/report.dir --exclude "/usr/*" -o coverage.info --ignore-errors mismatch
# genhtml s21_coverage.info --output-directory s21_lcov_report
# $(OPEN_FILE) ./s21_lcov_report/index.html

stylecheck: build
	cmake --build $(BUILD_DIR) --target stylecheck

cppcheck: build
	cmake --build $(BUILD_DIR) --target cppcheck§	

format: build
	cmake --build $(BUILD_DIR) --target format
