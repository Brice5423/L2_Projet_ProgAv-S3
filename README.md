# L2_Projet_ProgAv-S3

Projet de programmation avancée fait en L2 Info durant le S3.  
Par [Brice ORLIANGE](mailto:briceorl54580@gmail.com) et [Antoine SCANU](mailto:antoine.scanu1@gmail.com) du groupe TD2 et TP4.

________________________

# Projet en lui-même

## Renommage

> Certaine partie du code ne sont pas forcément facile à comprendre ou à lire.  
> Nous nous sommes permit de renommer certains fichiers, fonctions, structures et variables. Cela pour travailler dans les meilleurs conditions possible.
> Nous évitons de donner de nouveaux noms qui poseraient problèmes à la lecture de notre professeur.  
> Dans la majorité des cas, nous allons respecter la **norme de nomination** en C, le **camelCase**.

### Fichier changer

- Le fichier `prec.h` est renommé en `db_rec.h`. `db_rec.c` et `db_rec.h` les mêmes noms pour la même chose.

### Variables changer

- `newbagpack` -> `newBagpack`
- `ptrf` -> `ptrF`
- `numelm` -> `numElm`
- `ptrf` & `cmp_ptrf` & `ptr_fct` => `ptrF`
- `Vmax` -> `VMax`
- `nonstop` -> `nonStop`
- `ptr_object` -> `object`


## Création de nouveau fichier 

### `outils.c` & `outils.h`
Nous avons créé ces deux fichiers pour mettre à notre disposition les outils nécessaire pour réussir le projet.  
Fonction :
- `void rmInteger(int *i)`


## Agencement des includes dans les fichiers `.h`

Voici l'agencement des différents `#include` dans les `.h` ce trouvent dans le projet :  
![image non charger : Plan_des_.h.drawio.png](image/Plan_des_.h.drawio.png)  
> Les trois derniers blocs en rose _(dp_rec.h, dp_array.h et dp_list.h)_ sont les trois `#include` à faire appel dans le `main.c` pour qu'il puisse fonctionner.


## Agencement & avancement des fonctions

Voici les fonctions que nous avons réussies à faire durant le projet :  
![image non charger : Plan_avancement_des_fonction.drawio.png](image/Plan_avancement_des_fonction.drawio.png)
> Sur l'image, il y a la légende de la signification de chaque couleur.  
> Voici Les rôles de chaque ligne :
> - **1ᵉ ligne** : L'état des fonctions au début du projet _("À remplir" ou "Vide")_.
> - **2ᵉ ligne** : Les fonctions en cours _("En cours")_.
> - **3ᵉ ligne** : Les fonctions terminées. Indiqué si la fonction est finie est non-test _("Fini, à vérifier")_, si terminé est fonctionnel _("Fini, c'est ok")_, s'il vient (inspirer) d'un TP _("Copier d'un TP")_ ou s'il a était donner au début _("Donner")_.
> - **4ᵉ ligne** : Les fonctions qui étaient complete ou faite entièrement, mais qu'ils ne sont pas fonctionnel _("Erreur")_.


## Fonctionnement

### Dans le makefile
Dans la **première étape** pour pouvoir exécuter le projet correctement, il faut lancer la commande `make` dans un terminal **Linux**. 
#### L'exécutable
Le nom de l'exécutable du projet est `exe_projet`.
```c
_PROG = exe_projet
```
#### Défini tous les `.h`
Nous avons fait appel à tous les `.h`.
```c
_DEP = outils.h objects.h elmlist.h list.h bag.h dp_rec.h # global.h space_array.h dp_array.h states.h dp_list.h
```
> On n'a pas fait appel au fichier `global.h` car il posait problème au moment de la compilation `make`.
#### Défini tout les `.o`
Nous avons défini tous les `.o`
```c
_OBJ = main.o outils.o objects.o elmlist.o list.o bag.o dp_rec.o # global.o space_array.o dp_array.o states.o dp_list.o
```
> Comme avant, nous avons fait avant on n'a pas défini `global.o` pour la même raison. 

### À l'exécution
La **deuxième étape** pour pouvoir exécuter le projet. Il faut lancer cette commande **ci-dessous** dans un terminal **Linux**.
```shell
./exe_projet mode utilité VMax volume1 utilité1 volume2 utilité2 par exemple
```
> Dans la commande il y a des options à bien comprendre comment remplir :
> - **mode** (R|A|L) : Choisi la méthode d'exécution entre recursive _(R)_, array _(A)_ et liste _(L)_.
> - **utilité** (0|1) : Défini si on défini le volume _(1)_ ou pas _(0)_. S'il n'est pas défini alors l'utilité prendra le volume comme valeur.
> - **VMax** : Défini le volume maximal que le sac peut avoir.
> - **volumeN** : Volume du Nème objet.
> - **utilitéN** : Utilité du Nème objet.