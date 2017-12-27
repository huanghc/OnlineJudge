int coinCount(int *coins,int n,int amount){
	int *money = new int [amount+1];
	money[0] = 0;
	for (int i=1; i<=amount; ++i){
		money[i] = amount+1;
		for (int j=0; j<n; ++j){
			if (coins[j]<=i){
				money[i] = min(money[i],money[i-coins[j]]+1);
			}			
		}
	}

	if (money[amount] > amount) return -1;
	else return money[amount];	
}

