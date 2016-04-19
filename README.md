# Simple Web Server

### Keywords
webserver, static, stream, socket, IPV4, loopback, multithread

### Build and run
```
bash scripts/Makefile.sh
```

### Send request from client
```
curl "http://{VM_ETH0_IP_ADDRESS}:{PORT_NUMBER}"
```


### TODO
```
[--] serveur web fichiers statiques
[--] GET /fichier -> fichier
[--] GET /dossier -> index
[--] Gestion requêtes concurrentes (fork, threads, threadpool, event (epoll))
[--] apprendre à utiliser les sockets
[--] fournir un dossier avec la solution et des benchmarks (temps de réponse, CPU usage, RAM usage), compréhension des existants (nginx, apache)
```
