# LITTLE THUMB

## Prérequis :

Installer ROS version Indigo pour le server ROS : http://wiki.ros.org/indigo/Installation/Ubuntu
Installer Qt5 pour le client graphique : http://www.qt.io/

## Notes :

Dans le dossier catkin_ws vous trouverez la partie ROS du server.
Cette partie permet la communication entre l'interface graphique client en Qt et le simulateur en Java.

Plus d'informations concernant les packages : Catkin Workspace : http://wiki.ros.org/fr/ROS/Tutorials/catkin/CreatingPackage

Les sources se trouvent dans le dossier catkin_ws\src\beginner_tutorials\src.
Les executables des liens symboliques du dossier catkin_ws se trouvent dans le dossier catkin_ws\devel\lib\beginner_tutorials.
Ces liens symboliques facilitent les commandes.
Les fichier .srv du dossier catkin_ws\src\beginner_tutorials\srv correspondent aux structures des données envoyées.

Le client graphique en Qt transforme les paquets TCP reçus par le serveur par des paquets ROS qui sont reçus par le simulateur Java.
Ce dernier retourne les informations correspondantes.

## Execution :

Il faut dans un premier temps lancer ROS avec la commande roscore.
Ensuite le serveur TCP, le client graphique et enfin le simulateur Java.

Pour lancer le client graphique Qt : modifier l'adresse IP et le port dans le fichier mainwindow.cpp et lancer le fichier .pro.

Exemple :

Le client graphique envoie une commande :

$> string action
int64 engineFL
int64 engineFR
int64 engineBL
int64 engineBR
int64 time

Le simulateur en Java renvoie :

$> int64 ret

*ret : correspond au retour de l'odométrie.
