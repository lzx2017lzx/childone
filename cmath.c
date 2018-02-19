#include<iostream>
#include<cmath>
#include<fenv.h>
#include<math.h>
#define PI 3.1415926
int main01()
{
	std::cout << "abs(3.1416=" << std::abs(3.1416) << '\n';
	std::cout << "abs(-10.6)=" << std::abs(-10.6) << '\n';	
	return 0;
}
int main02()
{
	double param, result;
	param = 0.5;
	result = acos(param)*180.0 / PI;
	printf("The arc cosine of %f is %f degrees.\n", param, result);
	return 0;
}
int main03()
{
	double param, result;
	param = exp(2) - sinh(2);
	result = acosh(param);
	printf("The arc hyperbolic cosine of %f is %f radians.\n", param, result);
	return 0;
}
int main04()
{
	double param, result;
	param = 0.5;
	result = asin(param)*180.0 / PI;
	printf("the arc sine of %f is %f degrees\n", param, result);
	return 0;
}
int main05()
{
	double param, result;
	param = exp(2) - cosh(2);
	result = asinh(param);
	printf("The arc hyperbolic sine of %f is %f radians.\n", param, result);
	return 0;
}
int main06()
{
	double param, result;
	param = 1.0;
	result = atan(param) * 180 / PI;
	printf("the arc tangent of %f is %f degrees\n", param, result);
	return 0;
}
int main07()
{
	double x, y, result;
	x = -10.0;
	y = 10.0;
	result = atan2(y, x) * 180 / PI;
	printf("the arc tangent for(x=%f,y=%f)is %f degrees\n", x, y, result);
	return 0;
}
int main08()
{
	double param, result;
	param = tanh(1);
	result = atanh(param);
	printf("the arc hyperbolic tangent of %f is %f radians.\n", param, result);
	return 0;
}
int main09()
{
	double param, result;
	param = 27.0;
	result = cbrt(param);
	printf("cbrt(%f)=%f\n", param, result);
	return 0;
}
int main10()
{
	printf("ceil of 2.3 is %.1f\n", ceil(2.3));
	printf("ceil of 3.8 is %.1f\n", ceil(3.8));
	printf("ceil of -2.3 is %.1f\n", ceil(-2.3));
	printf("ceil of -3.8 is %.1f\n", ceil(-3.8));
	return 0;
}
int main11()
{
	printf("copysign(10.0,-1.0)=%f\n", copysign(10.0, -1.0));
	printf("copysign(-10.0,-1.0=%f\n", copysign(-10.0, -1.0));
	printf("copysign(-10.0,1.0=%f\n", copysign(-10.0, 1.0));
	return 0;
}
int main12()
{
	double param, result;
	param = 60.0;
	result = cos(param*PI / 180.0);
	printf("the cosine of %f degrees is %f.\n", param, result);
	return 0;
}
int main13()
{
	double param, result;
	param = log(2.0);
	result = cosh(param);
	printf("the hyperbolic cosine of %f is %f.\n", param, result);
	return 0;
}
int main14()
{
	double param, result;
	param = 1.0;
	result = erf(param);
	printf("erf(%f)=%f\n", param, result);
	return 0;
}
int main15()
{
	double param, result;
	param = 1.0;
	result = erfc(param);
	printf("erf(%f)=%f\n", param, result);
	return 0;
}
int main16()
{
	double param, result;
	param = 5.0;
	result = exp(param);
	printf("the exponential value of %f is %f.\n", param, result);
	return 0;
}
int main17()
{
	double param, result;
	param = 8.0;
	result = exp2(param);
	printf("2^%f=%f.\n", param, result);
	return 0;
}
int main18()
{
	double param, result;
	param = 1.0;
	result = expm1(param);
	printf("expm1(%f)=%f.\n", param, result);
	return 0;
}
int main19()
{
	double param, result;
	param = 1.0;
	result = expm1(param);
	printf("expm1(%f)=%f.\n", param, result);
	return 0;
}
int main20()
{
	printf("the absolute value of 3.1416 is %f\n", fabs(3.1416));
	printf("the absolute value of -10.6 is %f\n", fabs(-10.6));
	return 0;
}
int main21()
{
	printf("fdim(2.0,1.0)=%f\n", fdim(2.0,1.0));
	printf("fdim(1.0,2.0)=%f\n", fdim(1.0, 2.0));
	printf("fdim(-2.0,-1.0)=%f\n", fdim(-2.0, -1.0));
	printf("fdim(-1.0,-2.0)=%f\n", fdim(-1.0, -2.0));
	return 0;
}
int main22()
{
	printf("floor of 2.3 is %.11f\n", floor(2.3));
	printf("floor of 3.8 is %.11f\n", floor(3.8));
	printf("floor of -2.3 is %.11f\n", floor(-2.3));
	printf("floor of -3.8 is %.11f\n", floor(-3.8));
	return 0;
}
int main23()
{
	printf("fmax(100.0,1.0)=%f\n", fmax(100.0, 1.0));
	printf("fmax(-100.0,1.0=%f\n", fmax(-100.0, 1.0));
	printf("fmax(-100.0,-1.0)=%f\n", fmax(-100.0, -1.0));
	return 0;
}
int main24()
{
	printf("fmin(100.0,1.0)=%f\n", fmin(100.0, 1.0));
	printf("fmin(-100.0,1.0=%f\n", fmin(-100.0, 1.0));
	printf("fmin(-100.0,-1.0)=%f\n", fmin(-100.0, -1.0));
	return 0;
}
int main25()
{
	printf("fmod of 5.3/2 is %f\n", fmod(5.3, 2));
	printf("fmod of 18.5/4.2 is %f\n", fmod(18.5, 4.2));
	return 0;
}
int main26()
{
	double param, result;
	int n;
	param = 8.0;
	result = frexp(param, &n);
	printf("%f=%f*2^%d\n", param, result,n);
	return 0;
}
int main27()
{
	double leg_x, leg_y, result;
	leg_x = 3;
	leg_y = 4;
	result = hypot(leg_x, leg_y);
	printf("%f,%f and %f form a right=angled triangle.\n", leg_x, leg_y, result);
	return 0;
}
int main28()
{
	double param;
	int result;
	param = 10.0;
	result = ilogb(param);
	printf("ilogb(%f)=%d\n", param, result);
	return 0;
}
int main29()
{
	double result;
	result = log(10.0);
	if (isgreater(result, 0.0))
		printf("log(10.0) is positive");
	else
		printf("log(10.0) is not positive");
	return 0;
}
int main30()
{
	double result;
	result = log(10.0);
	if (isgreaterequal(result, 0.0))
		printf("log(10.0)is not negative");
	else
		printf("log(10.0)is negative");
	return 0;
}
int main31()
{
	double result;
	result = log(10.0);
	if (isless(result, 0.0))
		printf("log(10.0) is negative");
	else
		printf("log(10.0)is not negative");
	return 0;
}
int main32()
{
	double result;
	result = log(10.0);
	if (islessequal(result, 0.0))
		printf("log(10.0) is not positive");
	else
		printf("log(10.0)is positive");
	return 0;
}
int main33()
{
	double result;
	result = log(10.0);
	if (islessgreater(result, 0.0))
		printf("log(10.0)is not zero");
	else
		printf("log(10.0) is zero");
	return 0;
}
int main34()
{
	double result;
	result = sqrt(-1.0);
	if (isunordered(result, 0.0))
		printf("sqrt(-1.0)and 0.0 cannot be ordered");
	else
		printf("sqrt(-1.0)and 0.0 can be ordered");
	return 0;
}
int main35()
{
	double param, result;
	int n;
	param = 0.95;
	n = 4;
	result = ldexp(param, n);
	printf("%f*2^%d=%f\n", param, n, result);
	return 0;
}
int main36()
{
	double param, result;
	param = 0.5;
	result = lgamma(param);
	printf("lgamma(%f)=%f\n", param, result);
	return 0;
}
int main37()
{
	printf("rounding using");
	switch (fegetround())
	{
	case FE_DOWNWARD:printf("downward"); break;
	case FE_TONEAREST:printf("to-nearest"); break;
	case FE_TOWARDZERO:printf("toward-zero"); break;
	case FE_UPWARD:printf("upward"); break;
	default:printf("unknown");
	}
	printf("rounding:\n");
	printf("llrint(2.3)=%lld\n", llrint(2.3));
	printf("llrint(3.8)=%lld\n", llrint(3.8));
	printf("llrint(-2.3)=%lld\n", llrint(-2.3));
	printf("llrint(-3.8)=%lld\n", llrint(-3.8));
	return 0;
}
int main38()
{
	printf("llround(2.3)=%lld\n", llround(2.3));
	printf("llround(3.8)=%lld\n", llround(3.8));
	printf("llround(-2.3)=%lld\n", llround(-2.3));
	printf("llround(-3.8)=%lld\n", llround(-3.8));
	return 0;
}
int main39()
{
	double param, result;
	param = 5.5;
	result = log(param);
	printf("log(%f)=%f\n", param, result);
	return 0;
}
int main40()
{
	double param, result;
	param = 1000.0;
	result = log10(param);
	printf("log10(%f)=%f\n", param, result);
	return 0;
}
int main41()
{
	double param, result;
	param = 1.0;
	result = log1p(param);
	printf("log1p(%f)=%f.\n", param, result);
	return 0;
}
int main42()
{
	double param, result;
	param = 1024.0;
	result = log2(param);
	printf("log2(%f)=%f.\n", param, result);
	return 0;
}
int main43()
{
	double param, result;
	param = -1024.0;
	result = logb(param);
	printf("logb(%f)=%f.\n", param, result);
	return 0;
}
int main44()
{
	double param, fractpart, intpart;
	param = 3.1415925;
	fractpart = modf(param, &intpart);
	printf("%f=%f+%f\n", param, intpart, fractpart);
	return 0;
}
int main45()
{
	double a = nan("abcd");
	printf("%lld", a);
	return 0;
}
int main46()
{
	float a = nanf("abcd");
	printf("%f\n", a);
	return 0;
}
int main47()
{
	printf("first representable value greater than zero:%e\n", nextafter(0.0, 1.0));
	printf("first representable value less than zero:%e\n", nextafter(0.0, -1.0));
	return 0;
}
int main49()
{
	printf("7^3=%f\n", pow(7.0, 3.0));
	printf("4.73^12=%f\n", pow(4.73, 12.0));
	printf("32.01^1.54=%f\n", pow(32.01, 1.54));
	return 0;
}
int main()
{
	printf("remainder of 5.3/2 is %f\n", remainder(5.3, 2));
	printf("remainder of 18.5/4.2 is of\n", remainder(18.5, 4.2));

	return 0;
}