
#include <stdio.h>
struct dms
{
	int degs;
	int	mins;
	double secs;
};

double decDegs(int D, int M, double S)
{
	if (D < 0)
	{
		D = D * -1;
		return (D + ((double)M / 60) + (S / 3600)) * -1;
	}
	else
	{
		return D + ((double)M / 60) + (S / 3600);
	}
}

int main()
{
	struct dms lat, lon;
	double latitude, longitude;
	printf("Enter Latitude Degrees: ");
	scanf("%d", &lat.degs);
	printf("Enter Latitude Minutes: ");
	scanf("%d", &lat.mins);
	printf("Enter Latitude Seconds: ");
	scanf("%lf", &lat.secs);

	printf("Enter Longitude Degrees: ");
	scanf("%d", &lon.degs);
	printf("Enter Longitude Minutes: ");
	scanf("%d", &lon.mins);
	printf("Enter Longitude Seconds: ");
	scanf("%lf", &lon.secs);

	latitude = decDegs(lat.degs, lat.mins, lat.secs);
	longitude = decDegs(lon.degs, lon.mins, lon.secs);

	printf("Latitude: %lf\n", latitude);
	printf("Longtitude: %lf\n", longitude);

	return 0;
}