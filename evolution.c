#include "allinc.h"

using namespace std;

void mutate (Individual &indi, int mutPoints)
{
	for (int n=0; n<mutPoints; n++)
	{
		if ((rand() % 2)==1)
		{
			int cur = rand()%SUM_UPPER_BOUND;
			if (indi.genes[cur] == 1) indi.genes[cur] = 0; else indi.genes[cur] = 1;
		}
	}
}

void mutatePop(struct Population &population1)
{
	for (int i=0; i<=POPULATION_SIZE; i++)
	{
		mutate(population1.Population[i], MUTATE_POINTS);
	}
}

float fitness (Individual c)
{
	float sum = 0;
	for (int n=0; n<SUM_UPPER_BOUND; n++)
	{
		sum+=c.genes[n];

	}
	return sum/SUM_UPPER_BOUND;

}

Individual crossover(Individual a, Individual b)
{
	Individual c;
	int lima = rand()%SUM_UPPER_BOUND;
	if (lima==SUM_UPPER_BOUND) lima--;
	int limb = SUM_UPPER_BOUND-lima;

	for (int i=0; i<lima; i++) c.genes[i]=a.genes[i];
	for (int i=lima; i<SUM_UPPER_BOUND; i++) c.genes[i]=b.genes[i];

	return c;
}

int gens=0;
void evolve (Population &population1)
{
	Individual parents[POPULATION_SIZE/2];
	Individual offspring[POPULATION_SIZE/2];
	cout << "Starting evolution..." << endl;

	do
	{
		mutatePop(population1);
		printInd(getMax(population1));
		cout << "   GEN: " << gens << ", f()=" << fitness(getMax(population1)) << endl;
		for (int i=0; i<POPULATION_SIZE/2; i++)
		{
			parents[i]=population1.Population[rand()%(POPULATION_SIZE)];
		}

		for (int k=0; k<POPULATION_SIZE/2; k++)
		{
			offspring[k]=crossover(parents[k], getMax(population1));
		}

		for (int c=0; c<POPULATION_SIZE/2; c++)
		{
			if (fitness(getMax(population1)) < fitness(offspring[c]))
			{
				population1.Population[c]=offspring[c];
				for (int l=0; l<SUM_UPPER_BOUND; l++) offspring[c].genes[l]=0;
			}
		}
	gens++;
	} while (fitness(getMax(population1)) != 1);
	printInd(getMax(population1));
	cout << "   GEN: " << gens << ", f()=" << fitness(getMax(population1)) << endl;
}
