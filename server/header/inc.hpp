#pragma once;

//Header
#include <iostream>
#include <cstring>
#include <netinet/in.h>
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
//class
#include "client.hpp"
#include "server.hpp"
#include "ranking.hpp"