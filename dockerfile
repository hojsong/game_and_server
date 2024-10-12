# Dockerfile
FROM postgres:latest

# 초기화 스크립트 복사
COPY sql/init.sql /docker-entrypoint-initdb.d/
