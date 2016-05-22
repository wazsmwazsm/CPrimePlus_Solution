#include <stdio.h>
#include <math.h>

struct polar {
	
	double r;
	double theta;
};

struct rect {
	
	double x;
	double y;
};

struct rect p_to_r(const struct polar *pol);

int main(void)
{
	struct polar input;
	struct rect answer;
	
	puts("Enter the radius and theta:");
	while(scanf(" %lf %lf", &(input.r),&(input.theta)) == 2)
	{
		answer = p_to_r(&input);
		printf("Polar coord: %g %f\n", input.r, input.theta);
		printf("rectangular coord: %g %f\n", answer.x, answer.y);
		puts("Enter the radius and theta:");
	}
	
	puts("Bye!");
	return 0;
}

struct rect p_to_r(const struct polar *pol)
{
	static const double deg_rad = 3.141592654 / 180.0;
	struct rect res;
	double ang = deg_rad * pol->theta;
	
	res.x = pol->r * sin(ang);
	res.y = pol->r * cos(ang);
	
	return res;
}

