# SWS (Static Web Server)

### About
Based on a UNIX domain server: http://www.linuxhowtos.org/C_C++/socket.htm

### Build and run
```
bash scripts/yoloMakefile.sh
```

### Use with a navigator
```
http://{VM_ETH0_IP_ADDRESS}:8888/
```


### TODO
```
[ok] ------------> PUSH into a folder called "Malo" in
     ------------> https://github.com/julien-leroy/SimpleWebServer
[ok] FIX "undefined reference to Class::Method()"
[doing] REFACTOR "socket becomes a class (listen, read, bind, create, etc.)"
[--] FEAT "display by default a webpage to displays 'It works!'"
[--] FEAT "display HTTP response when a client send a request"
[--] FEAT "create a Makefile" -> http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
```

### Infos
 - serveur web fichiers statiques
 - GET /fichier -> fichier
 - GET /dossier -> index
 - Gestion requêtes concurrentes (fork, threads, threadpool, event (epoll))
 - apprendre à utiliser les sockets
 - fournir un dossier avec la solution et des benchmarks (temps de réponse, CPU usage, RAM usage), compréhension des existants (nginx, apache)
