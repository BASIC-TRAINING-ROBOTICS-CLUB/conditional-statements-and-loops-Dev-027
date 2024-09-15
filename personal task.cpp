#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool D;
    bool CLK;
    bool RESET;
    bool Q;       // Output state
} DFlipFlop;
// Initialize the flip-flop
void init_flip_flop(DFlipFlop *ff) {
    ff->D = false;
    ff->CLK = false;
    ff->RESET = false;
    ff->Q = false;
}
// Set inputs for the flip-flop
void set_inputs(DFlipFlop *ff, bool D, bool CLK, bool RESET) {
    ff->D = D;
    ff->CLK = CLK;
    ff->RESET = RESET;
}
// Update the flip-flop state
void update_flip_flop(DFlipFlop *ff) {
    static bool previous_CLK = false;
    
    // Check for synchronous reset
    if (ff->RESET) {
        ff->Q = false;
    } else if (ff->CLK && !previous_CLK) {
        // Rising edge detected
        ff->Q = ff->D;
    }

    // Store the current clock state for the next edge detection
    previous_CLK = ff->CLK;
}
// Print the current state of the flip-flop
void print_state(DFlipFlop *ff) {
    printf("Q = %d\n", ff->Q);
}
int main() {
    DFlipFlop ff;
    init_flip_flop(&ff);
    
//for case 1
    set_inputs(&ff, true, false, true);
    update_flip_flop(&ff);
    printf(" Case 1: ");
    print_state(&ff);  // Should be 0 (reset active)
    
//for case 2
    set_inputs(&ff, true, true, false);
    update_flip_flop(&ff);
    printf(" Case 2: ");
    print_state(&ff);  // Should be 1 (D = 1 on rising edge)
    
//for case 3
    set_inputs(&ff, false, false, false);
    update_flip_flop(&ff);
    printf(" Case 3: ");
    print_state(&ff);  // Should still be 1 (Q remains the same)

//for case 4
    set_inputs(&ff, true, true, true);
    update_flip_flop(&ff);
    printf(" Case 4: ");
    print_state(&ff);  // Should be 0 (reset active, irrespective of D)

    return 0;
}
