# Simple Web Server

### Keywords
webserver, static, stream, socket, IPV4, loopback

### Build and run
```
bash scripts/Makefile.sh
```

### Send request from client
```
navigator -> "http://{VM_ETH0_IP_ADDRESS}:{PORT_NUMBER}/{FILE_NAME_OR_NOTHING}"
```

### Fonctionnement socket (FR)
 1. Création d'un socket IPV4 de type stream
 2. Ecoute du socket sur l'addresse de loopback et un port
 3. Indication de la taille maximale de la queue de requêtes clients simultannées
 4. Lancement d'une boucle infinie :
    1. Récupération du premier client se connectant à notre socket
    2. Si ce dernier nous envoie une requête :
      - Traitement de la requête
      - Génération de la réponse
      - Envoi de la réponse avec le bon formatage (HEADER, HTTP status code)
      - Déconnection du client courant
 5. Arrêt du socket
