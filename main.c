#include "allinc.h"

using namespace std;

int main()
{
	srand(time(NULL));

	// initializing the population
	struct Population population1;
	int n;
	for (n=0; n<POPULATION_SIZE; n++)
	{
		Individual indi;

		cout << " [";
		for ( int i = 0; i < SUM_UPPER_BOUND; i++ )
		{
			indi.genes[i] = rand()%2;
		}
		population1.Population[n]=indi;
		cout << "] with f()=" << fitness(population1.Population[n]) << endl;
	}

	evolve(population1);

	return 1;
}
