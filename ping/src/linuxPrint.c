#include "../header/ft_ping.h"

extern struct addrinfo *g_res;
extern struct timeval total_time, program_start;
extern unsigned long long total, suc;
extern int   closefd, ac;
extern char  **av;
extern double *save_times;

void ft_print_recvmsg(unsigned long packetsize, char *url, char *recv_buffer){
    struct iphdr *ip_hdr = (struct iphdr*)recv_buffer;
    printf("%ld byte from %s : icmp_seq=%lld ttl=%d", packetsize, url, total, ip_hdr->ttl);
}