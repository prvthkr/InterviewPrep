// Online C compiler to run C program online
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SetBit(num, bit_pos)            (num |=  (1 << bit_pos))
#define ClearBit(num, bit_pos)          (num &=  ~(1 << bit_pos))
#define ToggleBit(num, bit_pos)         (num ^= (1 << bit_pos))
#define SetNoofBits(num, bit_pos, bits) (num |= ((1 << bits) - 1) << bit_pos)
#define SetRangeBits(num, high, low)    (num |= ((1 << ((high - low) + 1)) - 1) << low)


#define Mask_val(high, low)         ((1 << ((high - low) + 1)) - 1)
#define Num_mask(num, high, low)    (num & (~(Mask_val(high, low) << low)))
#define Val_mask(val, high, low)    ((val & Mask_val(high, low)) << low)
#define PutRangeVal(num, high, low, val)   (num = (Num_mask(num, high, low) | Val_mask(val, high, low)))



uint8_t CountNoSetBit(uint32_t num) {
    uint8_t count = 0;
    
    for (int i = 0; i < (sizeof(uint32_t) * 8); i++) {
        if ((num >> i) & 1) {
            count++;
        }
    }
    return count;
}

bool PowerOfTwo(uint32_t num) {
    return !(num & (num - 1));
}

void PrintBinary(uint32_t num) {
    
    printf("0x%x(%d): ",num, num);
    for (int i = (/*sizeof(uint32_t) * */ 8) - 1; i >= 0 ; i--) {
        if ((num >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

uint32_t PutRangeVal_f(uint32_t num, uint32_t high, uint32_t low, uint32_t val) {
    uint32_t tmp = 0;

    tmp = ((1 << ((high - low) + 1)) - 1);
    num = num & ~(tmp << low);
    val = ((val & tmp) << low);
    return (num |= val);
}

int main(void) {

    uint32_t num = 8;
    uint32_t bit_pos = 2;

    if (PowerOfTwo(num)) {
        printf("%d is power of 2\n", num);
    } else {
        printf("%d is not power of 2\n", num);
    }
    printf("Set Bit Count: %d\n", CountNoSetBit(num-1));
    
    printf("Before: ");
    PrintBinary(num);
    SetBit(num, bit_pos);
    printf("After Set Bit: ");
    PrintBinary(num);
    ClearBit(num, bit_pos+2);
    printf("After Clear Bit: ");
    PrintBinary(num);
    ToggleBit(num, bit_pos-1);
    printf("After Toggle Bit: ");
    PrintBinary(num);
    num = 0;
    printf("Before: ");
    PrintBinary(num);
    SetNoofBits(num, 0, 3);
    printf("After Set Bits: ");
    PrintBinary(num);
    printf("\n");
    num = 0;
    printf("Before: ");
    PrintBinary(num);
    SetRangeBits(num, 4, 2);
    printf("After Set Bits: ");
    PrintBinary(num);
    
    printf("\n");
    num = 0x00;
    printf("Before: ");
    PrintBinary(num);
    PutRangeVal(num, 7, 0, 0xFE);
    printf("After Set value Bits: ");
    PrintBinary(num);

    printf("\n");
    num = 0x00;
    printf("Before: ");
    PrintBinary(num);
    num = PutRangeVal_f(num, 7, 0, 0xfe);
    printf("After Set value Bits: ");
    PrintBinary(num);

    return 0;
}
