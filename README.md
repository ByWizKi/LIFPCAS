# LIFPCAS

## Note de TP1

**Creation d'un thread**

_thread(fonction, arg1, arg2, ....) creation d'un thread a qui on attribut une fonction_
_unThread.getid() on recupere la valeur de retour d'une la fonction du thread_
_unThread.join() attend que le thread ce termine avant main_

```
#include <thread>
#include <iostream>
// On creer la fonction a executer
int une_fonction(int m){
  std::cout <<"je suis le thread " << m  << ", je m'execute ..." << std::endl;
  return m;
}

int main(){

  std::thread t[5]; // on fait un tableau pour stocker les threads
  std::thread::id l[5]; // on fait un tableau pour stocker les id attribuer au thread
  // on creer 5 threads qui vont executer une fonction et on ajoute leur resultat dans un tableau

  for(int i = 0; i<5; i++){
    t[i] = std::thread(une_fonction, i);
    l[i] = t[i].get_id();
    t[i].join();
  }
  std::cout << "On attend que les processus termine ..." << std::endl;
  // on attend que les threads termine avec la methode join pour que le main termine aussi
  for(int i = 0; i < 5; i++){
    std::cout << "le thread " << l[i] << " a fini" << std::endl;
  }
  std::cout << "les threads ont tous termine, je suis main et je termine aussi" << std::endl;
  return 0;
}
```
### Reponse au questions

1. _Normalement, dès qu’il y a un nombre de threads important, vous pouvez observer
que les messages qu’ils affichent se mélangent. Sachant que les fonctions système sont
prévues pour fonctionner en environnement multithread, pourquoi y a-t-il ce mélange et
comment l’éviter ?_

** Il faut utiliser std::thread.join() pour attendre la fin d'execution du thread**

_j'ai declarer en variable global le temps_total car je n'ai pas trouve le moyen de recupere la valeur d'execution du threads_

### Test

|Temps reel|Temps user|Temps utilisateur   |Temps Programme |Nombres Threads|
|:--------:|:---------:|:-----------------:|:--------------:|:-------------:|
|0.21 real |0.21 user |0.00 sys            |0.214477        |2              |
|0.31 real |0.31 user |0.00 sys            |0.31066         |3              |
|0.40 real |0.40 user |0.00 sys            |0.406448        |4              |
|0.50 real |0.50 user |0.00 sys            |0.502527        |5              |
|0.79 real |0.78 user |0.00 sys            |0.788413        |8              |
|0.97 real |0.97 user |0.00 sys            |0.975297        |10             |
|1.91 real |1.91 user |0.00 sys            |1.91341         |20             |

_Note : le temps est calculer grace a la fonction /usr/bin/time de mac os_

Le temps real est le temps ecoule pendant le calcul.

Le temps user correspond user est la somme des temps processeur utilisés par les threads en mode utilisateur.

Le temps sys est la somme des temps processeur passés en mode noyau

**_Le temps real_** correspond bien au temps calculer dans **_le programme_**

Dans mon cas je n'ai pas de difference entre le temps utilisateur et le temps reel, mais comme le programme est multi-thread et que le temps utilisateur est le travail total qu'effectue par tous les coeurs du processeur en parrallele, alors que le temps reel est uniquement le temps qui s'est ecoule entre le lancement du programme et la fin de l'execution.

***

## Note TP2

