# Reflection on testing process so far:

"Black Box Testing" to KISS

testing with known inputs and expected outputs, without considering the internal workings



a working test foundation that:
	Catches obvious issues
	Tests key edge cases (already sorted, reverse sorted)
	Tests different sizes (3,4,5 numbers)
	Is easy to understand and debug
	sufficient for catching major issues




# if more systematic. robust approach needed later:


Systematic Test Case Design:

A. Edge Cases
   - Empty stack
   - Single element
   - Already sorted
   - Reverse sorted
   - Duplicates (should error)

B. Boundary Cases
   - INT_MIN and INT_MAX values
   - Numbers close to these boundaries

C. Permutation Coverage
   - For n=3: All 6 possible permutations
   - For n=4: Selected from 24 permutations
   - For n=5: Strategic subset of 120 permutations




Property-Based Testing:

// Properties that MUST be true after sorting:
1. Size remains same
2. Elements remain same (just reordered)
3. For any i: stack[i] <= stack[i+1]
4. Min element at start
5. Max element at end




Operation Count Testing:

// Track and verify operation counts
void test_case(...) {
    int op_count = 0;
    // Intercept operations (sa, ra, etc)
    // Count them
    assert(op_count <= max_ops_for_size[size]);
}