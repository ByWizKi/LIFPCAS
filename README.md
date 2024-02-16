# LIFPCAS

## Note de TP1

## Reponse au questions

### Question 1

```
c++
// Creation d'un tableau qui stocke les threads
thread threads[nbthreads];
for(int i = 0; i < nbthreads ; i++){
  threads[i] = thread(fct, i, nbtours)
}

// On attend que les threads finissent de s'executer
for(int i = 0; i < nbthreads; i++){
 threads[i].join();
}
```

### Question 2

Personnellement, pour régler le problème des paramètres, j'ai changé de version pour le compilateur et ajouté dans le Makefile l'option '-std=c++17'.

### Question 3

Les messages sont melangees car les threads font les meme calcules en meme temps.
Pour eviter cela on met la variable temps_total en globale car dans le probleme c'est la variable partager,
ensuite on creer un mutex pour bloquer cette valeur lorsqu'un mutex a besoin d'y avoir acces.
Enfin on libere la variable lorsque c'est fini.

## Note TP2

### Modification du makefile

Tout d'abord, j'ai dû installer XQuartz sur ma machine (Mac OS M1 Sonoma). Ensuite, dans le Makefile, il était nécessaire de modifier le LDPATH. Pour moi, c'est LDPATH = /opt/X11/lib. Par la suite, il était essentiel d'ajouter au compilateur les includes nécessaires pour compiler le projet. Les includes manquants concernaient la bibliothèque XQuartz, donc j'ai créé une nouvelle variable INCLUDE = /opt/X11/include pour ma part. Ce INCLUDE, je l'ai ajouté ici : LDFLAGS = $(INCLUDE) $(LDPATH) ....

### Modification de la fonction draw_screen_threads

1. Étape 1 : On crée un tableau de threads

```c++
std::vector<std::thread> tab_treads;
```

2. Étape 2 : On fait une boucle pour exécuter la fonction draw_screen_worker

```c++
for(int i = 0; i < number_of_threads; i ++ ){
  tab_threads.push_back(std::thread(draw_screen_worker));
}
```

3. Étape 3 : On attend que les threads aient fini de s'exécuter

```c++
for(auto &t : tab_threads){
  t.join();
}
```

### Probleme

Certains threads recalculent plusieurs fois la même tranche, ce qui se remarque sur l'affichage.

### Origine du probleme

Le problème est dû à la variable last_slice qui n'est pas protégée. Chaque fois qu'un thread exécute sa fonction, il la modifie, mais comme les threads modifient cette variable en même temps, il y a un conflit. Il est donc nécessaire de protéger la variable last_slice.

### Solution

Pour résoudre le problème, il est nécessaire de modifier la fonction get_slice(). Lors de l'appel à get_slice(), on vérifie d'abord si last_slice est inférieur à number_of_slices. Si c'est le cas, alors on incrémente last_slice pour passer à la tranche suivante. Cependant, étant donné que last_slice est une variable partagée par plusieurs threads, il est crucial de protéger cet accès pour éviter les conflits ou les conditions de course. Pour ce faire, nous utilisons un mutex. L'accès à last_slice est donc entouré par des opérations de verrouillage et de déverrouillage du mutex, garantissant que seul un thread à la fois puisse modifier cette variable.

```c++
int get_slice()
{
	// Utilisation de std::lock_guard pour verrouiller automatiquement le mutex et deverrouiller en fin de fonction
	std::lock_guard<std::mutex> L(last_slice_mutex);
	if (last_slice < number_of_slices)
	{
		int val = last_slice;

		if (rand() % 2 == 0)
		{
			usleep(100);
		}

		last_slice += 1;

		if (rand() % 2 == 0)
			usleep(100);

		return val;
	}
	else
	{
		return -1;
	}
}
```

### Le comptage des slices calculer

1. Étape 1 : On crée une variable globale total_slice_count.
2. Étape 2 : On incrémente la variable dans la fonction draw_screen_worker car c'est elle qui calcule, en quelque sorte, les slices.
3. Étape 3 : draw_screen_thread retourne cette valeur et on l'affiche dans le main.

### Appel a draw_rect()

Aucune erreur pour moi !

## Note TP3
