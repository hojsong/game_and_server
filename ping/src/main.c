#include "../header/ft_ping.h"

struct addrinfo *g_res;
struct timeval total_time, program_start;
unsigned long long total, suc;
int   closefd, ac;
char  **av;
double *save_times;

int main(int argc, char **argv) {
  int size;
  size = (int)ft_strlen(argv[1]);
  if(size < 2)
    size = 2;
  if ((argc != 2 && argc != 3) || ((argc == 3) && ft_strncmp(argv[1], "-v", size) != 0)) {
      printf("How to use: %s \"url\" or %s \'-v\' \"url\" \n", argv[0], argv[0]);
      return 1;
  }
  int sockfd;
  struct addrinfo addr, *res;
  char icmp_packet[PACKET_SIZE];
  struct icmp *icmp_hdr = (struct icmp *)icmp_packet;
  struct msghdr msg;
  struct iovec iov[1];
  char recv_buffer[PACKET_SIZE];
  struct timeval time_start, time_end, tv;
  int delay;
  //init
  ft_memset(icmp_packet, 0, PACKET_SIZE);
  ft_memset(&addr, 0, sizeof(addr));
  addr.ai_family = AF_UNSPEC;
  addr.ai_socktype = SOCK_RAW;
  addr.ai_protocol = IPPROTO_ICMP;
  tv.tv_sec = 1;
  tv.tv_usec = 0;
  total_time.tv_sec = 0;
  total_time.tv_usec = 0;
  ft_memset(&msg, 0, sizeof(msg));
  iov[0].iov_base = recv_buffer;
  iov[0].iov_len = sizeof(recv_buffer);
  msg.msg_iov = iov;
  msg.msg_iovlen = 1;
  ac = argc;
  av = argv;
  if (getaddrinfo(argv[argc - 1], 0, &addr, &res) != 0) {
      printf("getaddrinfo Failed : Undefined Url or Ip address.\n");
      exit(EXIT_FAILURE);
  }
  if (validate_domain_name(argv[argc - 1]) == 0){
    printf("Invalid domain name or Ip\n");
    freeaddrinfo(res);
    exit(EXIT_FAILURE);
  }
  if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
      printf("Permission Error : Please access with administrator permission.\n");
      freeaddrinfo(res);
      exit(EXIT_FAILURE);
  }
  if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv)) < 0) {
      printf("Set Error : setsockopt set timeout Failed.\n");
      exit(EXIT_FAILURE);
  }
  save_times = NULL;
  closefd = sockfd;
  g_res = res;
  total = 0;
  suc = 0;
  signal(SIGINT, signal_handler);
  fill_icmp_packet(icmp_hdr, 1);
  printf("--- PING %s %ld(%ld) bytes of data Start ---\n", argv[argc - 1], sizeof(msg) ,sizeof(icmp_packet));
  gettimeofday(&program_start, NULL);
  while (1) {
    total++;
    delay = 0;
    gettimeofday(&time_start, NULL);
    if (sendto(sockfd, icmp_packet, PACKET_SIZE, 0, res->ai_addr, res->ai_addrlen) <= 0) {
      if (argc == 3)
        printf("Packet Send Error\n");
    }
    if (recvmsg(sockfd, &msg, 0) <= 0) {
      if (argc == 3)
        printf("Recv Time Out\n");
      delay = 1000000;
    }
    else {
      suc++;
      gettimeofday(&time_end, NULL);
      ft_print_recvmsg(sizeof(icmp_packet), argv[argc - 1], recv_buffer);
      delay = time_stamp(time_start, time_end, &total_time);
      printf("\n");
    }
    usleep(1000000 - delay);
  }
  freeaddrinfo(res);
  close(sockfd);
  return 0;
}