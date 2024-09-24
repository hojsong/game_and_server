#pragma once

//Header
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <math.h>
#include <time.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#ifdef __APPLE__
    #include <netinet/ip_var.h> // macOS에서 사용할 수 있는 헤더
#endif
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <signal.h>
#include <netdb.h>
#include <regex.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <exception>
#include <sys/select.h>
#include <sys/poll.h>
#include <sys/event.h>
#include <sys/types.h>
#include <sys/wait.h>

//class
class ranking; // ranking 클래스 전방 선언
class client;  // client 클래스 전방 선언
class server;  // server 클래스 전방 선언

#define PORT    8550