#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#ifdef __APPLE__
    #include <netinet/ip_var.h> // macOS에서 사용할 수 있는 헤더
#endif
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <signal.h>
#include <netdb.h>
#include <regex.h>
#include <ctype.h>

#define DEST_PORT 0
#define PACKET_SIZE 64
#define TIMEOUT 1  
#define BUF_SIZE 512

void            process_end();
void            signal_handler(int signum);
void            ft_printOptional(struct addrinfo *res);
void            ft_rate();
double          sqrt_newton_raphson(double c);

void	        *ft_memset(void *b, int c, size_t len);
int	            ft_strncmp(const char *s1, const char *s2, size_t n);
int	            ft_isalnum(int c);
size_t	        ft_strlen(const char *str);

int             validate_domain_name(const char *domainName);
int             optional(char *str, char *opt);
void            fill_icmp_packet(struct icmp *icmp_hdr, int sequence);
int             time_stamp(struct timeval start, struct timeval end, struct timeval *total);
unsigned short  checksum(unsigned short *paddress, int len);

// macos or linuxos
void ft_print_recvmsg(unsigned long packetsize, char *url, char *recv_buffer);
