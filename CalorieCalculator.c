#include <stdio.h>
float CalculateBMR (int gender, float height, float weight, int age){
float bmr;
if (gender == 1){
    bmr= 10* weight + 6.25* height - 5* age + 5;
}
else if (gender == 2){
    bmr= 10*weight + 6.25*height - 5*age -161;
}
return bmr;
}
float CalculateTDEE (float bmr, int activity_level){
float tdee;
if(activity_level == 1){
    tdee= bmr* 1.2;

}
else if(activity_level == 2){
    tdee= bmr *1.375;
}
else if (activity_level == 3){
    tdee= bmr* 1.55;
}
else if (activity_level == 4){
    tdee= bmr*1.725;
}
else if (activity_level == 5){
    tdee= bmr*1.9;

}
return tdee;
}
float TrackCalories() {
float total_consumed = 0;

int choice;
int servings;
while (1){

    printf("\n 1- Apple (95)");
    printf("\n 2- Sandwich (350)");
    printf("\n 3- Soda (150)");
    printf("\n 4- Banana (105)");
    printf("\n 5- Pizza Slice (285)");
    printf("\n 6- Stop");
    printf("\nEnter Selection:");
    scanf ("%d", &choice);
    if(choice == 6){
        break;
    }
        printf("Enter Servings:");
        scanf ("%d", &servings);
        if(choice == 1){
            total_consumed += 95* servings;
        }
        else if (choice == 2){
            total_consumed += 350 * servings;
        }
         else if (choice == 3){
            total_consumed += 150 * servings;
    }
     else if (choice == 4){
            total_consumed += 105 * servings;
}
 else if (choice == 5){
            total_consumed += 285 * servings;

 }
 printf ("Current Total: %2f\n", total_consumed);
}

return total_consumed;
}
int main(){
    int gender, age, activity;
    float weight, height, myBMR, myTDEE, myConsumed;
    printf ("Enter Gender: (1-Male, 2-Female)\n");
    scanf ("%d", &gender);
    printf("Enter Weight in kg: \n");
    scanf ("%f", &weight);
    printf ("Enter Height In cm: \n");
    scanf ("%f", &height);
    printf ("Enter Age: \n");
    scanf ("%d", &age);
    myBMR = CalculateBMR(gender,height,weight,age);
    printf("Your BMR Is: %f\n", myBMR);
    printf ("1 = Lazy: little or no exercise \n");
    printf ("2 = Light: exercise 1-2 times/week \n");
    printf ("3 = Moderate: exercise 3-4 times/week \n");
    printf ("4 = Active: exercise 5-6 times/week \n");
    printf ("5= Very Active: exercise 7 times/week, or physical job \n");
    printf ("Select Activity Level (1-5) \n");
    scanf("%d", &activity);
    myTDEE= CalculateTDEE(myBMR, activity);
    printf ("Your TDEE is: %f\n", myTDEE);
    printf ("Starting Food Tracking... \n");
    myConsumed=TrackCalories();
    printf("Total Consumed %f \n", myConsumed);
    printf ("Target TDEE: %f \n", myTDEE);
    if (myConsumed < myTDEE){
        printf ("Result: Cutting Phase \n");

    }
    else if (myConsumed > myTDEE){
        printf ("Result: Bulking Phase \n");

    }
    else {
        printf("Result: Maintaining phase \n");
    }
return 0;
}
