#include "../header/ft_ping.h"

extern struct addrinfo *g_res;
extern struct timeval total_time, program_start;
extern unsigned long long total, suc;
extern int   closefd, ac;
extern char  **av;
extern double *save_times;

int validate_domain_name(const char *domainName) {
    int i;
    int length = (int)ft_strlen(domainName);
    int dotCount = 0;

    if (length < 3 || length > 253)
        return 0;
    if (!ft_isalnum(domainName[0]) || !ft_isalnum(domainName[length - 1]))
        return 0;
    for (i = 0; i < length; i++) {
        if (ft_isalnum(domainName[i]) || domainName[i] == '-' || domainName[i] == '.') {
            if (domainName[i] == '.') {
                dotCount++;
                if (i > 0 && domainName[i - 1] == '.')
                    return 0;
            }
        } else {
            return 0;
        }
    }
    if (dotCount < 1)
        return 0;
    return 1;
}

int time_stamp(struct timeval start, struct timeval end, struct timeval *total){
    int value;
    double ptime;
    double *reset;
    unsigned long long i;

    value = (end.tv_sec - start.tv_sec) * 1000000;
    value += (end.tv_usec - start.tv_usec);
    ptime = (double)value / 1000;
    printf(" time %.3f/ms", ptime);
    if(total != NULL){
      total->tv_sec += value / 1000000;
      total->tv_usec += value % 1000000;
      if(total ->tv_usec >= 1000000){
        total->tv_sec += total->tv_usec / 1000000;
        total->tv_usec %= 1000000;
      }
      i = 0;
      reset = malloc(sizeof(double) * suc);
      while(i + 1 < suc){
        reset[i] = save_times[i];
        i++;
      }
      reset[i] = ptime;
      if (save_times != NULL){
        free(save_times);
      }
      save_times = reset;
    }
    return value;
}

void fill_icmp_packet(struct icmp *icmp_hdr, int sequence) {
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = htons(getpid());
    icmp_hdr->icmp_seq = htons(sequence);
    ft_memset(icmp_hdr->icmp_data, 0xA5, PACKET_SIZE - sizeof(struct icmp));
    gettimeofday((struct timeval *)icmp_hdr->icmp_data, NULL);
    icmp_hdr->icmp_cksum = 0;
    icmp_hdr->icmp_cksum = checksum((unsigned short *)icmp_hdr, PACKET_SIZE);
}

unsigned short checksum(unsigned short *paddress, int len)
{
  int nleft = len;
  int sum = 0;
  unsigned short *w = paddress;
  unsigned short answer = 0;

  while (nleft > 1) {
    sum += *w++;
    nleft -= 2;
  }

  if (nleft == 1) {
    *(unsigned char *)&answer = *(unsigned char *)w;
    sum += answer;
  }

  sum = (sum >> 16) + (sum & 0xFFFF);
  sum += (sum >> 16);
  answer = ~sum;
  return (answer);
}