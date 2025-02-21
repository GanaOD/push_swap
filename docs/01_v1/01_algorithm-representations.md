# High-level pseudocode:

MAIN ALGORITHM:
1. If stack size ≤ 3:
    sort_small_stack(A)
    return

2. While size of A > 3:
    push_to_b(A, B)

3. sort_three_numbers(A)

4. While B not empty:
    number = get_best_number_to_push_back(B)
    rotate_stacks_to_position(A, B, number)
    push_to_a(B, A)

5. rotate_until_min_at_top(A)



# Example with small sequence:

Initial:        [4 2 1 5 3]    []
                Stack A         Stack B

Push to B:      [4 2 1]        [3 5]
Sort three:     [1 2 4]        [3 5]
Push back:      [1 2 3 4 5]    []