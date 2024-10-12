# Makefile

# Docker Compose 관련 설정
COMPOSE = docker-compose
COMPOSE_FILE = docker-compose.yml

SERV_DIR = ./server
CLIE_DIR = ./client
# 기본 타겟
all: 
	$(MAKE) -C $(SERV_DIR) 
	$(MAKE) -C $(CLIE_DIR)
	$(COMPOSE) -f $(COMPOSE_FILE) up -d --build

up :
	$(COMPOSE) -f $(COMPOSE_FILE) up -d --build

# 컨테이너 중지
clean:
	$(COMPOSE) -f $(COMPOSE_FILE) down

clean2:
	$(COMPOSE) -f $(COMPOSE_FILE) down -v

fclean : 
	$(COMPOSE) -f $(COMPOSE_FILE) down -v
	$(MAKE) -C $(SERV_DIR) fclean
	$(MAKE) -C $(CLIE_DIR) fclean

# 삭제 후 다시 실행
re: fclean all

re2 : clean up

re3 : clean2 up