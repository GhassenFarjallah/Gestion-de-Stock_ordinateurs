# Gestion-de-Stock_ordinateurs
+++  Plan de travail  +++  (on utilise dans ce programme la notion de la liste chainée)
Le programme consiste à stocker des produits(on a choisit les ordinateurs), chacun possède des carracterisques uniques saisie par l'utilisateurs. 
Notre programme assure les taches suivantes: 
● Ajouter un produit.
● Afficher la description d’un produit.
● Supprimer un produit.
● Modifier un produit.
● Recherche d’un produit dans le stock.
  
 ***** les fonctions qu'on a utiliser sont :
    -->int sontEgaux : prend en parametre deux ordinateur et compare leur carracteristique s'ils sont egaux return(1) else return(0).
    
    -->void ajout : saisie de l'utilisateur les carracteristiques de l'ordinateur qu'on va l'ajouter 
    puis on l'ajout au stock par l'appel de  la fonction ajouterAustock 
(NB: en cas d'existence du cet ordinateur précedement dans le stock , on l'ajoute a la quantité stockée et non pas creer un autre noeud de la liste chainée)

    -->Noeud *rechercherOrdinateur : return une liste chainée contenant l'ordinateur recherché s'il le trouve sinon return (NULL). 
    
    -->void recherche : selon la resultat de la fonction rechercherOrdinateur afiche la marque,modele,quantité de l'ordinateur  s'il  trouve sa ref  ou affiche q'il n'existe pas dans le stock .
    
   -->void modification: changer les valeurs récentes par de nouvelles carracteristiques. Elle appelle la  fonction void modifierOrdinateur qui permet le changement de chaque carracteristique.
   
   -->void afficherOrdinateur : afficher les caractéristiques de l'ordinateur dont la reference est passé en paramètre.
   
  -->void delete_computer : supprimer l'ordinateur dont la reference est passé en parametre.
  
NB: Dans tous les fonctions on a traité le cas ou la reference saisie  par l'utilisateur est  fausse. 
