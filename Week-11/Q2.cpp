#include <iostream> 
#include <vector> 
 
using namespace std; 
 
int coinChange(int coins[], int n, int N) 
{     
    vector<int> dp(N + 1, 0);     
    dp[0] = 1; 
 
    for (int i = 0; i < n; i++) 
    {         
        for (int j = coins[i]; j <= N; j++) 
        {             
            dp[j] += dp[j - coins[i]]; 
        } 
    } 
 
    return dp[N]; 
} 
 
int main() 
{ 
    int n; 
    cout << "Enter the number of coins: ";     
    cin >> n; 
 
    int coins[n];     
    cout << "Enter the values of coins: ";    
    for (int i = 0; i < n; i++) 
    {        
        cin >> coins[i]; 
    } 
 
    int N;    
    cout << "Enter the value of N: ";     
    cin >> N; 
 
    int ways = coinChange(coins, n, N);     
    cout << "Number of ways to make sum " << N << ": " << ways << endl; 
 
    return 0; 
} 
