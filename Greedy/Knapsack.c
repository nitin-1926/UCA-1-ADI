#include<stdio.h>

int main()
{
	int n,capacity;
	scanf("%d %d",&n,&capacity);
	int profit[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&profit[i]);
	}
	int weight[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	float ratio[n];
	for(int i=0;i<n;i++)
	{
		 ratio[i] = (profit[i]/(float)weight[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(ratio[i]>ratio[j])
			{
				float tmp = ratio[i];
				ratio[i]=ratio[j];
				ratio[j]=tmp;

				int tmp2 = profit[i];
				profit[i]=profit[j];
				profit[j]=tmp2;

				int tmp3 = weight[i];
				weight[i]=weight[j];
				weight[j]=tmp3;
			}
		}
	}
	int i=0;
	float money=0.0;
	while(capacity!=0)
	{
		if(capacity-weight[i]>=0)
		{
			capacity-=weight[i];
			money+=profit[i];
			i++;
		}
		else
		{
			float temp = ((profit[i])*(capacity)/(float)(weight[i]));
			money+=temp;
			capacity=0;
		}
	}
	printf("%.2f\n",money);
	return 0;
}