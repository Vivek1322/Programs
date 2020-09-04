# include<stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
   float x[20], tp = 0;
   int i, j, u;
   u = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }

   if (i < n)
      x[i] = u / weight[i];

   tp = tp + (x[i] * profit[i]);

   printf("\nThe portion of entered meals to be consumed are:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);

   printf("\nMaximum calories you consumed:- %f", tp);

}
void pr(int x){
    int i;
    for(i = 0; i < x/4; i++){
        printf(")");
    }
    printf("\n");
}
struct diet
{
 int weight,calories;
 char meal_name[20];
};

int main() {
   float weight[20], profit[20], capacity;
   int num, i, j,a;
   float ratio[20], temp;

   printf("        ~*~*~*~*~*~*NUTRIFIT-YOUR FIT KITCHEN~*~*~*~*~*~*\n");

   printf("\nMeal planning means 'PROFESSIONAL NUTRITIONIST PASSIONATE ABOUT HEALTHY EATING'. Weight Watchers, which not only champions a sustainable diet but has sustained itself for over fifty years, is a favorite amongst nutritionists.For a lot of us, becoming a better person starts with feeling better about ourselves.We provide you tips and tools for a healthy lifestyle.");


  printf("\n\nTo view, the key to your  healthy lifestyle\n\n\nPress 0 to create your own diet plan\n Press 1 to follow our diet plan\n\n ");
  scanf("%d",&a);
  if(a==1)
  {
      printf("\n1        boiled chicken   100 gm  168 ");pr(168);
      printf("\n2            fish         150gm   164 ");pr(164);
      printf("\n3        sprout salad     200gm   70  ");pr(70);
      printf("\n4            nuts         20gm    116 ");pr(116);
      printf("\n5            oats         40gm    156 ");pr(156);
      printf("\n6        idli sambhar     60gm    200 ");pr(200);
      printf("\n7     half fried omelete  40gm    40  ");pr(40);
      printf("\n8         tofu curry      50gm    28  ");pr(28);
      printf("\n9           bacon         8gm     43  ");pr(43);
      printf("\n10      roasted turkey    71gm    148 ");pr(148);

  }
  else

  {
    int i,a;
 struct diet st[3];
 printf("HEY FITNESS FREAK!!");

 printf("enter the number of meals in your customized diet plan:-");
 scanf("%d",&a);
 if(a<=4)
 {
 printf("Enter the meal information -");
 for(i=0;i<a;i++)
    {
  printf("\nEnter meal name:-");
   scanf("%[^\n*c]",&st[i].meal_name);
   printf("\nEnter weight(in gms):");
    scanf("%d",&st[i].weight);
     printf("\n Enter calories:");
     scanf("%d",&st[i].calories);
 }
 printf("\nMeal Information List:");
 for(i=0;i<a;i++)
    {
        printf("\nmeal_Name:%s ,weight:%d, calories:%d",st[i].meal_name,st[i].weight,st[i].calories);
  }
 }
  else{
    printf("\nAlthough you are creating your own diet plan, you are not supposed to have more than 4 meals a day. To be fit, eat lit!\n\n\n ");
  }
}
   printf("\n\nEnter the no. of meals:- ");
   scanf("%d", &num);

   printf("\nEnter the weights and calories of each meal:- ");
   for (i = 0; i < num; i++) {
      scanf("%f %f", &weight[i], &profit[i]);
   }

   printf("\nEnter your per day calorie requirement:- ");
   scanf("%f", &capacity);

   for (i = 0; i < num; i++) {
      ratio[i] = profit[i] / weight[i];
   }

   for (i = 0; i < num; i++) {
      for (j = i + 1; j < num; j++) {
         if (ratio[i] < ratio[j]) {
            temp = ratio[j];
            ratio[j] = ratio[i];
            ratio[i] = temp;

            temp = weight[j];
            weight[j] = weight[i];
            weight[i] = temp;

            temp = profit[j];
            profit[j] = profit[i];
            profit[i] = temp;
         }
      }
   }

   knapsack(num, weight, profit, capacity);
   return(0);
}
