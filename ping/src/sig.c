#include "../header/ft_ping.h"

extern struct addrinfo *g_res;
extern struct timeval total_time, program_start;
extern unsigned long long total, suc;
extern int   closefd, ac;
extern char  **av;
extern double *save_times;

void ft_printOptional(struct addrinfo *res){
  struct addrinfo *p;

  p = res;
  if (p->ai_family == AF_INET) {
    printf("IPv4 address, ");
  } else if (p->ai_family == AF_INET6) {
    printf("IPv6 address, ");
  }
}

double sqrt_newton_raphson(double x) {
    double tolerance = 1e-10; // 오차 범위
    double guess = x / 2.0;   // 초기 추정값
    double diff = 1.0;

    // 뉴턴-랩슨 방법을 사용한 반복 계산
    while (diff > tolerance) {
        double new_guess = (guess + x / guess) / 2.0;
        diff = new_guess - guess;
        if (diff < 0) {
            diff = -diff; // 절대값 계산
        }
        guess = new_guess;
    }

    return guess;
}

void ft_rate(){
    unsigned long long rate;
    double averagetime, mdev, dest, min, max;
    struct timeval end;
    int i;
    
    gettimeofday(&end, NULL);
    printf("%llu packets transmitted, %llu packets received, ", total, suc);
    rate = ((total - suc) * 100) / total;
    printf("%llu%% packet loss, ", rate);
    averagetime = (((double)(total_time.tv_sec * 1000000) / suc)  + ((double)(total_time.tv_usec) / suc)) / 1000;
    time_stamp(program_start, end, NULL);
    printf("\n");
    min = 1000;
    max = 0;
    mdev = 0;
    if(save_times && ac == 3){
      i = 0;
      while(1){
        dest = (save_times[i] - averagetime);
        mdev += (dest * dest);
        if (min > save_times[i])
          min = save_times[i];
        if (max < save_times[i])
          max = save_times[i];
        i++;
        if ((unsigned long long)i < suc)
          ;
        else
          break;
      }
      mdev /= suc;
      mdev = sqrt_newton_raphson(mdev);
      printf ("rtt min/avg/max/mdev : %.3f/%.3f/%.3f/%.3f ms", min, averagetime, max, mdev);
    }
    else if (save_times == NULL && ac == 3){
      printf("rtt = NULL");
    }
    printf("\n");
}

void process_end(){
    printf("--- %s ping end statistics  ---\n", av[ac - 1]);
    if (ac == 3)
        ft_printOptional(g_res);
    ft_rate();
    freeaddrinfo(g_res);
    close(closefd);
    if(save_times != NULL)
      free(save_times);
    exit(0);
}

void signal_handler(int signum) {
    if (signum == SIGINT){
        process_end();
    }
}