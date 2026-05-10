#include <stdio.h>

float discount(float x){
	if(x >= 500){
		if(x >= 2000 && x <= 4000 && x != 2027)
			return x * 0.05;
		else if(x == 2027)
			return 270;
		else if(x >= 5000){
			if(x * 0.1 >= 2000){
				return 2000;
			}
			else{
				return x * 0.1;
				}
			}
		else{
			return 50;
		}
	}	
	
	else{
		return 0;
	}
}

int main(){
	float cart_value, cp, cp_to_tk;
	float total_dis, payable, new_cp;
	float x, y;
	
	printf("Enter the cart value: ");
	scanf("%f", &cart_value);
	printf("Enter customer point: ");
	scanf("%f", &cp);

	cp_to_tk = cp / 40;
	
	if(cart_value - discount(cart_value) >= cp_to_tk){
		total_dis = cp_to_tk + discount(cart_value);
		payable = cart_value - total_dis;
		new_cp = (cart_value / 10) * 4;
	}
	else{
		payable = 0;
		total_dis = cart_value;
		x = (cp_to_tk - (cart_value - discount(cart_value))) * 40;
		y = (cart_value / 10) * 4;
		new_cp = x + y;
	}

	printf("Total discount: %.2f\nPayable: %.2f\nUpdated CP: %.2f\n", total_dis, payable, new_cp);

	return 0;	
}
