#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sys/time.h>
#include <cmath> // Utilisez <cmath> pour C++
#include <thread>
#include <mutex>
using namespace std;

double timevalsub(struct timeval *tv1, const struct timeval *tv2)
{
  double res = 0;
  res = tv2->tv_sec - tv1->tv_sec;
  res += (tv2->tv_usec - tv1->tv_usec) * 1.0 / 1000000;
  return res;
}

/*
  Creation d'un mutex qui va permetre de bloquer la variable lorsque threads veut y avoir acces et la liberer a la fin
  Creation d'une variable gloable
*/

mutex m;
double temps_total = 0;

// Returns the duration of call
double fct(int num, int nbtours)
{
  // Les threads vont faire le calcul donc je lock la variable
  m.lock();
  struct timeval tv1, tv2;
  int err;

  cout << num << " lancement de la fonction pour " << nbtours << " itérations" << endl;
  for (int i = 0; i < nbtours; i++)
  {
    double sum = 0;
    err = gettimeofday(&tv1, NULL);
    if (err != 0)
    {
      perror("gettimeofday");
      exit(EXIT_FAILURE);
    }

    for (int j = 0; j < 5000000; j++)
    {
      sum += log(j + 1);
    }

    err = gettimeofday(&tv2, NULL);
    if (err != 0)
    {
      perror("gettimeofday");
      exit(EXIT_FAILURE);
    }
    double duree = timevalsub(&tv1, &tv2);
    temps_total += duree;

    fprintf(stdout, "%d : je viens de faire un calcul dont le résultat est %g, il a fallu %g secondes\n", num, sum, duree);
  }
  // Je libere la variable
  m.unlock();
  return temps_total;
}

int main(int argc, char **argv)
{
  int nbthreads = 10;
  int nbtours = 5;

  if ((argc == 2) && (atoi(argv[1])))
  {
    nbthreads = atoi(argv[1]);
  }
  else if (argc != 1)
  {
    cerr << "usage: " << argv[0] << " [<nb de lancements et de threads>]" << endl;
    exit(1);
  }
  cout << "Th principal : lancement de " << nbthreads << " fois la fonction" << endl;

  // Creation d'un tableau qui stocke les threads
  thread threads[nbthreads];
  for (int i = 0; i < nbthreads; i++)
  {
    threads[i] = thread(fct, i, nbtours);
  }

  // On attend que les threads finissent de s'executer
  for (int i = 0; i < nbthreads; i++)
  {
    threads[i].join();
  }

  cout << "Th principal : Tous les threads ont terminé " << temps_total << endl;

  return 0;
}
