#pragma once

#define PORT    8550
//Header
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h> 
#include <netinet/in.h>
#include <netinet/ip.h>
#ifdef __APPLE__
    #include <netinet/ip_var.h> // macOS에서 사용할 수 있는 헤더
#endif
#include <netinet/ip_icmp.h>
#include <regex.h>
#include <ctype.h>
#include <string>
#include <utility>

//C++
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

//Container
#include <vector>
#include <map>
#include <queue>

//C
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>

#include <sys/socket.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <sys/event.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/time.h>

// //sql
#include <libpq-fe.h> //postgresql
// #include <mysql_driver.h>
// #include <mysql_connection.h>
// #include <cppconn/prepared_statement.h>
// #include <cppconn/resultset.h>


//class
class ranking; // ranking 클래스 전방 선언
class sql_Integration; // sql_Integration 클래스 전방 선언
class client;  // client 클래스 전방 선언
class server;  // server 클래스 전방 선언
