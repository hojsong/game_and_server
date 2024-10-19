#pragma once

#define PORT    8550

// 공통 헤더
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include <time.h> 
#include <regex.h>
#include <ctype.h>
#include <string>
#include <utility>

// C++
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

// Container
#include <vector>
#include <map>
#include <queue>

// C 표준 헤더
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>

// 플랫폼 별 헤더
#ifdef __APPLE__ // macOS
    #include <netinet/ip_var.h> // macOS에서 사용할 수 있는 헤더
    #include <sys/event.h>      // macOS 전용
#else // Linux
    #include <sys/poll.h>       // Linux에서 사용할 수 있는 헤더
#endif

#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/wait.h>
#include <sys/time.h>

// SQL 관련 헤더
#include <libpq-fe.h> // PostgreSQL
// #include <mysql_driver.h>
// #include <mysql_connection.h>
// #include <cppconn/prepared_statement.h>
// #include <cppconn/resultset.h>

// 클래스 전방 선언
class ranking; // ranking 클래스 전방 선언
class sql_Integration; // sql_Integration 클래스 전방 선언
class client;  // client 클래스 전방 선언
class server;  // server 클래스 전방 선언
