# Simple Web Server

### Keywords
webserver, static, stream, socket, IPV4, loopback, multithread

### Build and run
```
bash scripts/Makefile.sh
```

### Send request from client
```
navigator -> "http://{VM_ETH0_IP_ADDRESS}:{PORT_NUMBER}/{FILE_NAME_OR_NOTHING}"
```


### TODO
```
[--] Gestion requêtes concurrentes (fork, threads, threadpool, event (epoll))
[--] fournir un dossier avec la solution et des benchmarks (temps de réponse, CPU usage, RAM usage), compréhension des existants (nginx, apache)
```
