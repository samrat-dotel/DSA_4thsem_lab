#include <stdio.h>
#include<string.h>
int main() {
    int size;
    scanf("%d",&size);
    if (size == 0){printf("%d",0);
        return 0;
    }
    
    int pots[size];

    for(int i = 0 ; i<size; i++){
        scanf("%d",&pots[i]);
    }
        
    int dp[size];
    memcpy(dp,pots, sizeof(pots));
    dp[size-3] += dp[size-1];
    
    for (int i = size-4; i>=0;i--){
        dp[i] += dp[i+2] > dp[i+3] ? dp[i+2]: dp[i+3];
    }
        
    int result = dp[0]> dp[1] ? dp[0]: dp[1];
    
    printf("%d", result);
    
    return 0;
}