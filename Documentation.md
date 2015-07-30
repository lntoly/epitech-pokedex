# Documentation #

## Introduction ##

Le projet que nous avons réalisé pour le rush se base sur le célèbre jeu Pokémon.
Il a d’abord été question de créer un Pokedex, soit un répertoire listant les pokémons, leurs évolutions, leurs attaques, etc.
Dans un second temps, nous avons du créer un gestionnaire d’équipe.
Dans Pokémon, il existe ce que l’on appelle des dresseurs, les propriétaires de pokémons. Notre gestionnaire d’équipe permet d’assigner à un dresseur plusieurs équipes de 7 pokémons (chiffre choisi arbitrairement) en vu d’éventuel combat. Il s’agit là de la troisième partie.
Cette dernière partie consiste à faire combattre deux dresseurs et leurs équipes de pokémons.
Pour le moment, nous ne prévoyons pas d’implémenter cette fonctionnalité.

## Le Pokedex ##

Pour créer notre Pokedex, deux fichiers XML nous ont été fournit : pokedata.xml et Mdata.xml.
Le fichier pokedata contient les informations principales concernant les 4XX pokémons. Il s’agit donc d’un fichier conséquent de 35Mo. Pour parser et charger toutes les données contenus dans ce XML, il faut quelques secondes.
C’est de cette constatation que nous ai venu l’idée du splash-screen.

  * Splash-screen

Nous utilisons le splash-screen pour montrer à l’utilisateur que le programme se charge correctement. Différents messages sont affichés sur le splash-screen en fonction de l’avancé du chargement.
Une fois le chargement terminé et le splash-screen passé, nous arrivons sur l’interface principale du programme.

  * Interface

L’interface est minimal mais regroupe le nécessaire au fonctionnement du Pokedex : nous retrouvons la liste des pokémons à gauche, avec une petite icône et le nom du pokémon associé, puis le détail du pokémon sélectionné à droite.
Dans la barre de menus, nous retrouvons les contrôles habituels : fermer l’application (Ctrl+F4), documentation, crédits et à propos. La barre de menus permet d’accéder aux fonctionnalités de la deuxième partie du projet : la gestion des équipes.
La gestion des équipes
Le gestionnaire d’équipe est intégré au Pokedex. On y accède via l’onglet « Equipes » de la barre de menus. Cinq actions différentes sont à disposition de l’utilisateur créer une nouvelle équipe, gérer les équipes existantes, sauvegarder ou tout effacer.

  * Créer une nouvelle équipe

Une équipe est composée d’un dresseur et de 7 pokémons (maximum). Vous retrouverez donc, dans la fenêtre « Créer une nouvelle équipe », deux colonnes : à gauche, la liste des dresseurs et, à droite, la liste des pokémons que vous voulez leur associer. Pour se faire, il suffit de cocher la case se trouvant en face de chaque pokémons que vous voulez ajouter dans l’équipe dirigé par le dresseur sélectionné dans la liste de gauche.