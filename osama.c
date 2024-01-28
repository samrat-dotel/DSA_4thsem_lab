#include <stdio.h>
#include<string.h>
int main() {
    int size;
    scanf("%d",&size);
    if (size == 0){printf("%d",0);
        return 0;
    }
    
    int weapons[size];

    for(int i = 0 ; i<size; i++){
        scanf("%d",&weapons[i]);
    }
        
    int gunCase[size];
    memcpy(gunCase,weapons, sizeof(weapons));
    gunCase[size-3] += gunCase[size-1];
    
    for (int i = size - 4; i >= 0; i--) {
    if (gunCase[i + 2] > gunCase[i + 3]) {
        gunCase[i] += gunCase[i + 2];
    } else {
        gunCase[i] += gunCase[i + 3];
    }
}

int result;
if (gunCase[0] > gunCase[1]) {
    result = gunCase[0];
} else {
    result = gunCase[1];
}
    
    printf("%d", result);
    
    return 0;
}