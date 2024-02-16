# LIFPCAS

## Note de TP1


## Reponse au questions
### Question 1
```c++

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
