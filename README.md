
# cub3D

## Le points de cub3D

> Ce projet est inspiré du célèbre jeu Wolfenstein 3D, qui était le tout premier FPS. Il vous permettra d'explorer le ray-casting. Votre objectif sera de faire une vue dynamique à l'intérieur d'un labyrinthe, dans lequel vous devrez trouver votre chemin.
>
> ## 📝 PDF
>
> - [**`FICHIER ORIGINAL`**](https://github.com/louchebem06/Docs-42/blob/master/en.cub3D.pdf)

## 🚀 Contenu

### 🚩 Partie obligatoire

| Program name     | cub3D                                                                                                                                                                                        |
| :--------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Turn in files    |  All your files                                                                                                                                                                                      |
| Makefile         | all, clean, fclean, re, bonus                                                                                                                                                                                          |
| Arguments        |   a map in format *.cub                                                                              |
| External functs. | • open, close, read, write, printf, malloc, free, perror, strerror, exit<br>• All functions of the math library (-lm man man 3 math) <br>• All functions of the MinilibX |
| Libft authorized | Yes                                                                                                                                                                                           |
| Description      | Vous devez créer un graphique 3D « réaliste » représentation de l'intérieur d'un labyrinthe à partir d'un point de vue à la première personne. Vous devez créer ceci représentation utilisant les principes du Ray-Casting mentionné plus tôt.                                                                                                                                                        |

Les contraintes sont les suivantes :
-  Vous devez utiliser la miniLibX. Soit la version disponible sur le
système ou de ses sources. Si vous choisissez de travailler avec les sources, vous
besoin d'appliquer les mêmes règles pour votre libft que celles écrites ci-dessus dans Common
Partie instructions.
- La gestion de votre fenêtre doit rester fluide : changement de fenêtre, minimisation, etc.
- Affichez différentes textures de mur (à vous de choisir) qui varient en fonction de
côté le mur fait face (Nord, Sud, Est, Ouest).
- Votre programme doit pouvoir régler les couleurs du sol et du plafond sur deux couleurs différentes.
- Le programme affiche l'image dans une fenêtre et respecte les règles suivantes :
Les touches fléchées gauche et droite du clavier doivent vous permettre de regarder à gauche et
droit dans le labyrinthe.<br>
◦ Les touches W, A, S et D doivent vous permettre de déplacer le point de vue à travers
le labyrinthe.<br>◦ Appuyer sur ESC doit fermer la fenêtre et quitter le programme proprement.<br>◦ Cliquer sur la croix rouge sur le cadre de la fenêtre doit fermer la fenêtre et
quittez le programme proprement.<br>
L'utilisation d'images de la minilibX est fortement recommandée.
- Votre programme doit prendre comme premier argument un fichier de description de scène avec le .cub
extension.
La carte doit être composée uniquement de 6 caractères possibles : 0 pour un espace vide,
1 pour un mur, et N,S,E ou W pour la position de départ et le frai du joueur
orientation.<br>
Il s'agit d'une simple carte valide :
```
111111
100101
101001
1100N1
111111
```
◦ La carte doit être fermée/entourée de murs, sinon le programme doit revenir
une erreur.<br>
◦ A l'exception du contenu de la carte, chaque type d'élément peut être séparé par un ou
plus de ligne(s) vide(s).<br>
◦ A l'exception du contenu de la carte qui doit toujours être le dernier, chaque type de
L'élément peut être défini dans n'importe quel ordre dans le fichier.<br>
◦ A l'exception de la carte, chaque type d'information d'un élément peut être séparé
par un ou plusieurs espace(s).<br>
◦ La carte doit être analysée telle qu'elle apparaît dans le fichier. Les espaces sont une partie valide du
carte et sont à vous de gérer. Vous devez être capable d'analyser tout type de carte,
tant qu'il respecte les règles de la carte.<br>
◦ La première information de chaque élément (sauf la carte) est l'identifiant de type (composé d'un ou deux caractère(s)), suivi de toutes les informations spécifiques à chacun objet dans un ordre strict tel que :<br>

Texture Nord :
```
NO ./path_to_the_north_texture
```
-  identifiant : NO
- chemin vers la texture nord

Texture sud :
```
SO ./path_to_the_south_texture
```
- identifiant : SO
- chemin vers la texture sud

Texture ouest :
```
WE ./path_to_the_west_texture
```
- identifiant : WE
- chemin vers la texture ouest

Texture Est :
```
EA ./path_to_the_east_texture
```
- identifiant : EA
- chemin vers la texture est

Couleur du sol :
```
F 220,100,0
```
identifiant : F
- Couleurs R,V,B dans la plage [0,255] : 0, 255, 255

Couleur du plafond :
```
C 225,30,0
```
- identifiant : C
- Couleurs R,V,B dans la plage [0,255] : 0, 255, 255

◦ Exemple de la partie obligatoire avec une scène .cub minimaliste :
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
◦ Si une mauvaise configuration de quelque nature que ce soit est rencontrée dans le fichier, le programme
doit se terminer correctement et renvoyer "Error\n" suivi d'un message d'erreur explicite
de votre choix.

### 🚩 Bonus part

Liste des bonus :
- Collisions murales.
- Un système de minicarte.
- Portes pouvant s'ouvrir et se fermer.
- Sprites animé.
- Faites pivoter le point de vue avec la souris.
